# Title : Development Notes - Robin


## Guidance for micropump software: mp Multiboard2 communication

Here is outlined how to communicate with the mp-Multiboard2 by Bartels Mikrotechnik as the software documentation provided by the company rather lacking.

If this is your first time communicating with the device make sure to install the USB-driver located in the mp-Multiboard2_USB_Driver folder. Download the entire folder and locate a file called silbser.inf. Righ click the file and press install (for a KUcomputer it will be necessary to request admin priviledges using Heimdal). Once installation is complete USB/VISA communication is possible.

The other folder named mp-Multiboard2_App contains a executable provided by the company that allows for communication with the board. It also contains the firmware provided by the company in a separate folder. The executable is explained well in the software documentation provided so it will not be discussed further.

Reflashing the original firmware: Download the firmware folder. Use command promp to locate the path to that folder and then run the upload.bat file. You sould now have the original firmware on the board. (If you experience issues with the flashing try holding the small 'boot' button on the board down while running the .bat file.

## Labview VI

A labview VI has been made for communication with the board as well. To use it open the VISA connection with the open button (remember to first select the correct com-port) then it is possible to operate two pumps with the software (pump1 = CH5 and pump2 = CH6) setting the voltage and frequency. Remeber to close the VISA connection when done communicating.

The voltage readout is inconsistent and can be illustrated with this little test of the output:

Manual 1 (read CH5, CH5 V from 200 to 100):
200
200
OK
100
...
Eventually correct after several reads

Manual 2 (read CH5, CH5 V from 100 to 200):
100
100
100
OK
200
...
Eventually correct after several reads

Continous 1 (read both channels: CH6 CH5, CH5 V from 200 to 100)
(0 200)
(0 200)
(OK 0)
(100 0)
(100 0)
(100 0)
(100 0)
(100 0)
...
V is eventually correct after several reads but wrong channel

Continous 2 (read both channels: CH6 CH5, CH5 V from 100 to 200)
(100 0)
(100 0)
(100 OK)
(0 200)
(0 200)
(0 200)
(0 200)
...
Eventually correct after several reads

Continous 3 (read both channels: CH6 CH5, CH5 V from 200 to 100)
(0 200)
(0 200)
(0 200)
(OK 0)
(100 0)
(100 0)
(100 0)
(100 0)
...
V is eventually correct after several reads but wrong channel

Continous 2 (read both channels: CH6 CH5, CH5 V from 100 to 200)
(100 0)
(100 0)
(100 0)
(100 OK)
(0 200)
(0 200)
(0 200)
...
Eventually correct after several reads

The measurements are done using a two second wait bewteen reading and writing this is consistent with results seen with 0.5 second wait time. The continous measurements have an additional 2 second wait between them.
