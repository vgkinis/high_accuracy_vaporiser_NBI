# Logbook - Robin

Welcome to the logbook. This document keeps track of significant events, updates, and progress organized by date about the micro pump setup. 

## Index

- [2024-08-21: Initial Test](#2024-08-21-initial-test)
- [2024-08-28: Longer Measurement](#2024-08-28-longer-measurement)
- [2024-09-02: Test of Syringe witout Needle](#2024-09-02-test-of-syringe-witout-needle)

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

### 2024-09-02: Test of Syringe witout Needle
- **Description**: Syringe replaced with testing-syringe without a needle. The needleless syringe was placed in water container.
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
  
  
