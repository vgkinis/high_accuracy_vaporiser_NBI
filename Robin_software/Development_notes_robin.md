# Title : Development notes Robin


## Guidance for micropump software: mp Multiboard2 communication

Here is outlined how to communicate with the mp-Multiboard2 by Bartels Mikrotechnik as the software documentation provided by the company rather lacking.

If this is your first time communicating with the device make sure to install the USB-driver located in the mp-Multiboard2_USB_Driver folder. Download the entire folder and locate a file called silbser.inf. Righ click the file and press install (for a KUcomputer it will be necessary to request admin priviledges using Heimdal). Once installation is complete USB/VISA communication is possible.

The other folder named mp-Multiboard2_App contains a executable provided by the company that allows for communication with the board. It also contains the firmware provided by the company in a separate folder. The executable is explained well in the software documentation provided so it will not be discussed further.

Reflashing the original firmware: Download the firmware folder. Use command promp to locate the path to that folder and then run the upload.bat file. You sould now have the original firmware on the board. (If you experience issues with the flashing try holding the small 'boot' button on the board down while running the .bat file.

## Labview VI: MP6_micro_pump.vi

A labview VI has been made for communication with the board as well. To use it open the VISA connection with the open button (remember to first select the correct com-port) then it is possible to operate two pumps with the software (pump1 = CH5 and pump2 = CH6) setting the voltage and frequency. Remeber to close the VISA connection when done communicating.

For this VI to work the ESP32 must have the original firmware on it. The commands must be entered as code strings:

| Command       | Meaning                                                                                      |
|---------------|----------------------------------------------------------------------------------------------|
| `PON`         | Turns all pumps on                                                                           |
| `POFF`        | Turns all pumps off                                                                          |
| `P<p>ON`      | Turns the selected pump `<p>` on. Example: Turns pump #1 on with `P1ON`                      |
| `P<p>OFF`     | Turns the selected pump `<p>` off. Example: Turns pump #1 off with `P1OFF`                   |
| `P<p>V<a>`    | Sets the amplitude for the selected pump `<p>` to the chosen value `<a>`. Example: `P1V250` sets pump #1 to 250 Vpp |
| `P<p>V?`      | Gets the amplitude for the selected pump `<p>`. Example: `P1V?` returns “250” meaning 250 Vpp for pump #1 |
| `F<d>=<f>`    | Sets the frequency for driver `<d>` to the chosen value `<f>`. Example: `F0=100` sets the frequency for the mp-Highdriver4 to 100 Hz. |
| `V1ON`        | Turns valve 1 on                                                                             |
| `V2ON`        | Turns valve 2 on                                                                             |
| `V1OFF`       | Turns valve 1 off                                                                            |
| `V2OFF`       | Turns valve 2 off                                                                            |
| `DPON`        | Enables pressure readout                                                                     |
| `DPOFF`       | Disables pressure readout                                                                    |
| `DFON`        | Enables liquid flow readout                                                                  |
| `DFOFF`       | Disables liquid flow readout                                                                 |
| `DGON`        | Enables gas flow readout                                                                     |
| `DGOFF`       | Disables gas flow readout                                                                    |
| `DA<a>ON`     | Enables analog sensor readout at Analog `<a>` connector on board                             |
| `DA<a>OFF`    | Disables analog sensor readout at Analog `<a>` connector on board                            |
| `L<l>`        | Changes flowrate sensor calibration to `<l>` (0=water, 1=IPA). Example: `L0` changes to water calibration |
| `V`           | Displays the current firmware version                                                        |
| *(enter key)* | Displays current settings of the Multiboard                                                  |

A typlical write and read command can be seen for the send command button in the bottom of the front panel:
![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_software/Images/IMG_send_command_110624.png)

Log: 11/06/24

The voltage readout eg. `P5V?` is inconsistent and can be illustrated with this little test of the output:

Manual 1 (read CH5, CH5 V from 200 to 100):
- 200
- 200
- OK
- 100
- ...
Eventually correct after several reads

Manual 2 (read CH5, CH5 V from 100 to 200):
- 100
- 100
- 100
- OK
- 200
- ...
Eventually correct after several reads

Continous 1 (read both channels: CH6 CH5, CH5 V from 200 to 100)
- 0 200
- 0 200
- OK 0
- 100 0
- 100 0
- 100 0
- 100 0
- 100 0
- ...
V is eventually correct after several reads but wrong channel

Continous 2 (read both channels: CH6 CH5, CH5 V from 100 to 200)
- 100 0
- 100 0
- 100 OK
- 0 200
- 0 200
- 0 200
- 0 200
- ...
Eventually correct after several reads

Continous 3 (read both channels: CH6 CH5, CH5 V from 200 to 100)
- 0 200
- 0 200
- 0 200
- OK 0
- 100 0
- 100 0
- 100 0
- 100 0
- ...
V is eventually correct after several reads but wrong channel

Continous 2 (read both channels: CH6 CH5, CH5 V from 100 to 200)
- 100 0
- 100 0
- 100 0
- 100 OK
- 0 200
- 0 200
- 0 200
- ...
Eventually correct after several reads

The measurements are done using a two second wait bewteen reading and writing this is consistent with results seen with 0.5 second wait time. The continous measurements have an additional 2 second wait between them.

Log 12/06/24

The voltage reading issue has been resolved, this was a buffer issue which has been resolved by flushing the buffer during continuous readings. This solution gives fast and correct readouts for each channel, the only downside is that continuous readings must be stopped to read other values. For now this is not an issue as there are limited commands that are not relevant right now.

The implementation of this can be seen here:
![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_software/Images/IMG_flush_buffer_120624.png)

The VI is thus now operational with the basic commands available.

## Arduino sketch (Visual Studio code with Platformio extension): MP6_Robin

A simple arduino sketch has been made based on a modified template available on [Bartels Mikrotechnik's website](https://bartels-mikrotechnik.de/wp-content/uploads/simple-file-list/EN/Software/Pumpdriver_Arduino_Example_Code.zip) for the current lowdriver configuration.

To run the code in viasual studio the platformio extension is required. From the platformio home menu choose to open the project, make sure that both the platformio.ini and main.cpp files are open.

Alternatively, the main.cpp file can be copied as a .ino file and run in the Arduino IDE. This requires the installation of Espressif's board manager. Go to files>preferences and then add [https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json) to the “Additional Board Manager URLs” field. When selecting a core choose "ESP32 Dev Module". However, this guide if focused on Visual Studio Code.

The program itself is simple. It will set a voltage and frequency for the pump and turn it on for set experimental time. It will then turn off for the same amount of time. Open serial monitor in order to recieve status.