# Logbook - Robin

Welcome to the logbook. This document keeps track of significant events, updates, and progress organized by date about the micro pump setup. 

## Index

### 2024
- [2024-08-21: Initial Test](#2024-08-21-initial-test)
- [2024-08-28: Longer Measurement](#2024-08-28-longer-measurement)
- [2024-09-02: Test of Syringe without Needle](#2024-09-02-test-of-syringe-without-needle)
- [2024-09-03: Test of Syringe with Needle](#2024-09-03-test-of-syringe-with-needle)
- [2024-10-04: First Long Term Test of only Syringe](#2024-10-04-first-long-term-test-of-only-syringe)
- [2024-10-07: Second Long Term Test of only Syringe](#2024-10-07-second-long-term-test-of-only-syringe)
- [2024-10-08: Third Long Term Test of only Syringe](#2024-10-08-third-long-term-test-of-only-syringe)

### 2025 (setup changes & tests)
- [General changes made to the setup](#general-changes-made-to-the-setup)
- [2025-07-04: First test with active cooling](#2025-07-04-first-test-with-active-cooling)
- [2025-07-08: Second test with active cooling](#2025-07-08-second-test-with-active-cooling)
- [2025-07-09: No priming test](#2025-07-09-no-priming-test)
- [2025-07-10: Second no priming test](#2025-07-10-second-no-priming-test)
- [2025-07-11: Priming test](#2025-07-11-priming-test)
- [2025-07-15: Sanity check](#2025-07-15-sanity-check)
- [2025-07-16: Is it the syphon effect?](#2025-07-16-is-it-the-syphon-effect)
- [2025-07-17: Is it the water itself?](#2025-07-17-is-it-the-water-itself)
- [2025-07-21: Syringe test – no needle](#2025-07-21-syringe-test---no-needle)

## Log Entries 2024

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

### 2024-10-04: First Long Term Test of only Syringe
- **Description**: The testing-syringe without needle was run over night.
- **Highlights**: 
  - 1 run was made but failed after a few hours likely due to leak at the syringe adapter.
- **DATA**: 
  - 100Hz, 150V, No cycles - Initially pumping had fine flow but stopped, reprimed and and seemingly working for a couple of hours then it became very noisy on stopped. After some inspection this seemed the be the metal syringe adapter ruining the seal. Changed the damaged fittings.
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Long_test_041024/TEST_100Hz_150V_cycleNO_041024.png)

### 2024-10-07: Second Long Term Test of only Syringe
- **Description**: The testing-syringe without needle was run over the weekend.
- **Highlights**: 
  - 1 run was made but showed 4 different flow regimes (High, Decreasing, Mid-Noisy snf Low_Stable).
- **DATA**: 
  - 100Hz, 150V, No cycles - Initially pumping had fine at high stable flow but then stopped, reprimed the line and high stable flow continued for a some of hours. At about the 5 hours mark the flow rate dropped, became noisy and started to decrease for about 15 hours. The following 18 or so hours the flow rate plateaued slightly higher than the end-point of the decrease, but was much more noisy than initially. At the 38 hour mark it changed regime again as the flow rate dropped to similar levels to the decrease end-point, while fluctuating it was much more stable.
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Long_test_071024/TEST_100Hz_150V_cycleNO_071024.png)

### 2024-10-08: Third Long Term Test of only Syringe
- **Description**: The testing-syringe without needle was run over night. Additional test with no flowmeter.
- **Highlights**: 
  - 1 run was made showed a stable high flow regime but completely stopped after approx. 6 hours. In the morning about 50 ml of water was in the out beaker.
  - 5 runs without flowmeter was made.
- **DATA**: 
  - 100Hz, 150V, No cycles - Initially pumping had fine at high stable flow but then stopped after 6 hours, did not rebound.
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/Long_test_081024/TEST_100Hz_150V_cycleNO_081024.png)
  - 100Hz, 150V (maybe 250V by mistake) without flowmeter straight to beeaker - filled 50 ml in less than an hour.
  - 100Hz, 150V without flowmeter straight to beeaker - filled 60 ml in about an hour 10 min.
  - 100Hz, 150V without flowmeter straight to beeaker - only very little water in an hour (reprimed after).
  - 100Hz, 150V without flowmeter straight to beeaker - filled 50 ml in less than an hour.
  - 100Hz, 150V without flowmeter straight to beeaker - filled 50 ml in less than an hour.

## Log Entries 2025

### General changes made to the setup
- **Description**: The following changes have been made to the setup.
	- A new labview VI for micropump and flowmeter DAQ has been implemented (See Robin_software for further documentation). This enables simultaneous DAQ and control of both the micropump and the flowmeter, live view of flow, voltage and frequency as well as PID control of voltage and frequency.
	- The jar containing inlet water is kept in a commercial peltier coolerbox (Essential Minikøleskab by Nohro - PO no.: 108596 Model no. ELEC00014-1) which allows cooling to 15C lower than ambient temperature.
	-Following tests are without syringe and needle unless specified
	
### 2025-07-04: First test with active cooling
- **Description**: The Peltier cooler was powered through USB from an 2011 27' iMAC, and a long run to test stability
- **Highlights**: 
  - Active cooling 
  - new miliQ water
  - priming 
  - fixed V and f
  - output container underneath the input container (possible syphon effect)
- **DATA**: 
  - Even flow, slightly dropping initially (2 hrs), then very stable
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/CoolerTests2025/040725_150V_104Hz_NoPID.png)
  
### 2025-07-08: Second test with active cooling 
- **Description**: Replication test of previous run
- **Highlights**: 
  - Active cooling 
  - new miliQ water
  - no priming 
  - fixed V and f
  - Output opening above input opening
- **DATA**: 
  - Even flow, slightly dropping initially (2 hrs), then minimally noisy
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/CoolerTests2025/080725_150V_104Hz_NoPID.png)
  
### 2025-07-09: No priming test
- **Description**: Test No priming
- **Highlights**: 
  - Active cooling 
  - same water from 080725
  - no priming 
  - start at high F about 150Hz then 100Hz fixed V
  - Output opening above input opening
- **DATA**: 
  - Discontinous flow states (5000ul to 1500ul), no change noticible for frequency change (f change was a mistake replication needed)
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/CoolerTests2025/090725_150V_104Hz_NoPID.png)
  
### 2025-07-10: Second no priming test
- **Description**: Replication test of previous run
- **Highlights**: 
  - Active cooling 
  - same water from 080725
  - no priming 
  - fixed V and f
  - Output opening above input opening
- **DATA**: 
  - Discontinous flow states (4000ul to 2000ul), priming seems to make a difference
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/CoolerTests2025/100725_150V_104Hz_NoPID.png)
  
### 2025-07-11: Priming test
- **Description**: Test similar to previous run, but now with priming
- **Highlights**: 
  - Active cooling 
  - same water from 080725
  - priming 
  - fixed V and f (final bit with PID F)
  - Output opening above input opening
- **DATA**: 
  - Discontinous flow states (relatively steady at 3500ul) - not recording V at start, V turned on a 5min mark, maybe priming was not the only issue will try replicating 040725 test next
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/CoolerTests2025/110725_150V_104Hz_NoPID.png)
  
### 2025-07-15: Sanity check
- **Description**: Test similar to 040725 run
- **Highlights**: 
  - Active cooling 
  - new miliQ water
  - priming 
  - fixed V and f
  - Output opening above input opening (+5cm approx)
- **DATA**: 
  - Even flow at 3100uL, when turning off pump 1400uL flow, disrupted by moving the output slightly up (+2cm approx) (still syphon effect?)
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/CoolerTests2025/150725_150V_104Hz_NoPID.png)
  
### 2025-07-16: Is it the syphon effect?
- **Description**: Replication test of previous run (trying to ensure no syphon effect)
- **Highlights**: 
  - Active cooling 
  - new miliQ water
  - priming 
  - fixed V and f
  - Output opening high above input opening (+30cm approx)
- **DATA**: 
  - When output first moved after pumping strong negative flow, with pumping even flow at 3100uL, when turned off negative flow which settles- Height of ouput important
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/CoolerTests2025/160725_150V_104Hz_NoPID.png)
  
### 2025-07-17: Is it the water itself?
- **Description**: Replication test of previous run using previous runs water
- **Highlights**: 
  - Active cooling 
  - same water from 160725
  - priming 
  - fixed V and f
  - Output opening high above input opening (+30cm approx)
- **DATA**: 
  - When output first moved after pumping strong negative flow, with pumping even flow at 3100uL that then became noisy, when turned off negative flow which settles after some time, not true for repeats as it is almost immediate- Old water seems to cause issues, what?
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/CoolerTests2025/170725_150V_104Hz_NoPID.png)
  
  ### 2025-07-21: Syringe test - no needle
- **Description**: Syringe connected to system, submerged vertically, seal initially validated manually with the plunger syringe making sure there are no air bubbles in the lines
- **Highlights**: 
  - Active cooling 
  - new miliQ water
  - priming 
  - fixed V and f
  - Output opening high above input opening (+30cm approx)
- **DATA**: 
  - Very even flow, it does take some time for the flow to recover after pumping (20min approx)
  - ![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/blob/main/Robin_data/CoolerTests2025/210725_150V_104Hz_NoPID.png)