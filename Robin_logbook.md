# Logbook - Robin

Welcome to the logbook. This document keeps track of significant events, updates, and progress organized by date about the micro pump setup. 

## Index

- [2024-08-21: Initial Test](#2024-08-21-initial-test)
- [2024-08-28: Longer Measurement](#2024-08-28-longer-measurement)
- [2024-09-02: Test of Syringe without Needle](#2024-09-02-test-of-syringe-without-needle)
- [2024-09-03: Test of Syringe with Needle](#2024-09-02-test-of-syringe-with-needle)

## Log Entries

### 2024-08-21: Initial Test
- **Description**: Testing the SD-card reader and LabView program cycle routine
- **Highlights**: 
  - 1 measurement data was successfully saved.
  - Pumping from sample tray using autosampler with syringe and needle.
  - Flow abrubtly stopped while pump cycling still on.
- **DATA**: 
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/TEST_100Hz_150V_cycle5s_210824.png)

### 2024-08-28: Longer Measurement
- **Description**: Tested pumping through syringe and needle.
- **Highlights**: 
  - It was necessary to prime the line in order to get flow (pumping using 5s cycling on and off).
  - Flowrate firsts declines slowly over 30min then spikes shortly and then is no more.
  - No visible loss of water from the vial in the tray. Likely only line volume is being pumped
- **DATA**: 
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/TEST_100Hz_150V_cycle5s_280824.png)

### 2024-09-02: Test of Syringe without Needle
- **Description**: Syringe replaced with testing-syringe without a needle. The needleless syringe was placed in water container.
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/IMAGES/IMG_syringe_noneedle_side.png)
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/IMAGES/IMG_syringe_noneedle_top.png)
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/IMAGES/IMG_line_end.png)
- **Highlights**: 
  - 4 x 1 hr runs measured (two with on/off cycling, two without).
  - First two measurements show instability of the flowrate, the following two were much more stable.
  - Seemingly no issue with the tubing to syringe converter made by the workshop.
- **DATA**: 
  - First measurement: 100Hz, 150V, No cycles - Initial spike, approx 8min decline, 35 min relatively stable 400-600 nl/min, noisy regime
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/TEST_100Hz_150V_cycleNO_020924.png)
  - Second measurement: 100Hz, 150V, 5s cycles - Approx 15 min increasing rate, sharp and short decline, 40 min stable regime
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/TEST_100Hz_150V_cycle5s_020924.png)
  - Third measurement: 100Hz, 150V, No cycles - relatively stable the whole time
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/TEST_100Hz_150V_cycleNO_020924_n2.png)
  - Fourth measurement: 100Hz, 150V, 5s cycles - stable the whole time
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/TEST_100Hz_150V_cycle5s_020924_n2.png)
  
### 2024-09-03: Test of Syringe with Needle
- **Description**: Continued with the testing-syringe from the day before first assuring flow without a needle, then added a needle. The test was performed in the same water container.
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/IMAGES/IMG_syringe_needle.png)
- **Highlights**: 
  - 2 runs without needle ensuring that the system was still operational (this required priming the line with a manual syringe according to Bartels instructions).
  - 2 runs with the needle showed similar results to what has been seen when pumping with the syringe and needles previously. Flow to begin with and then a decline until no flow
  - Last run to ensure that problem was with needle and not down line- tentatively confirmed.
- **DATA**: 
  - First measurement: 100Hz, 150V, No and 5s cycles - Initially pumping fine with no cycles, however the flow stopped after 10 minutes with a small pickup afterwards, at approx half hour mark 5s cycles were wngaged in the hopes that it would restart the flow - no clear results.
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/TEST_100Hz_150V_cycleNO5s_030924.png)
  - Second measurement: 100Hz, 150V, No and 5s cycles - Attempt to restart the flow, several priming events were conducted with a manuel syringe, and a combination of cycles and no cycles were used. After a priming attempt in combination with 5s second cycles afterwards a stable regime was reached.
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/TEST_100Hz_150V_cycleNO5s_030924_priming.png)
  - Third measurement: 100Hz, 150V, 5s cycles - Pumping through needle in big container. Singnificant flow at 5 minutes followed by decline which then picks up between 20 to 30 minutes, but generally very sporadic flow spikes with average flow of 100 nl/min to 400 nl/min
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/TEST_100Hz_150V_cycle5s_030924_needle1.png)
  - Fourth measurement: 100Hz, 150V, No cycles - Pumping through needle in big container. Initial slight flow which reduced to almost nothing in 10 minutes. Attempts at priming were unsuccessful.
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Flow_tests/TEST_100Hz_150V_cycleNO_030924_needle2_priming.png)
  - Fifth measurement: 100Hz, 150V, 10 min of 5s and 50 min cycles - pumping without syringe in big container - cycling gave big swings 5000nl/min on and - 5000nl/min off - no cycling gave consistent approx 4000nl/min.
  - DATA in SD card corrupted
