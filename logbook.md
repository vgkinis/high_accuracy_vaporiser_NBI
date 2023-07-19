# Title : Log book high Accuracy vaporiser


## Tests with 0.5mm inner diameter 25 cm length

Measures with one pump at different voltage (peak to peak) and different frequency: 

![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/9f1d385e-8405-41a2-9753-2356415af098)

## Tests with 0.25mm inner diameter 25cm length

Measures with one pump at different voltage (peak to peak) and different frequency: 

![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/0c760832-68f9-4b99-9ce7-b7d951792574)

## Update 20230524

I am now able to read the value from the new flow sensor with the arduino code in the folder "readSensorValue"

## Tests with 0.25mm inner diameter 50cm length

Measures with one pump at different voltage (peak to peak) and different frequency: 

![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/ed23f4c7-ea4f-4cfd-8489-96aee1461938)

## Conclusion on different tests

| Conclusion    |                        |                        |                        |
|---------------|------------------------|------------------------|------------------------|
| tube ID :     | 0.5 mm                 | 0.25 mm                | 0.25 mm                |
| tube length:  | 25 cm                  | 25 cm                  | 50 cm                  |
| 50 Hz         |                        |                        |                        |
| Voltage (V)   | Flow measured (µL/min) | Flow measured (µL/min) | Flow measured (µL/min) |
| 16            | 51,0                   | 1,0                    | 0,0                    |
| 40            | 196,0                  | 12,0                   | 7,0                    |
| 80            | 505,0                  | 55,0                   | 27,0                   |
| 120           | 795,0                  | 88,0                   | 46,0                   |
| 160           | 1057,0                 | 122,0                  | 63,0                   |
| 67 Hz         |                        |                        |                        |
| Voltage (V)   | Flow measured (µL/min) | Flow measured (µL/min) | Flow measured (µL/min) |
| 16            | 39                     | 1                      | 0                      |
| 40            | 179                    | 16                     | 8                      |
| 80            | 513                    | 60                     | 28                     |
| 120           | 855                    | 92                     | 48                     |
| 160           | 1136                   | 129                    | 66                     |
| 84 Hz         |                        |                        |                        |
| Voltage (V)   | Flow measured (µL/min) | Flow measured (µL/min) | Flow measured (µL/min) |
| 16            | 72                     | 1                      | 1                      |
| 40            | 254                    | 15                     | 9                      |
| 80            | 615                    | 63                     | 30                     |
| 120           | 989                    | 98                     | 50                     |
| 160           | 1291                   | 135                    | 68                     |
| 100 Hz        |                        |                        |                        |
| Voltage (V)   | Flow measured (µL/min) | Flow measured (µL/min) | Flow measured (µL/min) |
| 16            | 63                     | 1                      | 0                      |
| 40            | 275                    | 18                     | 9                      |
| 80            | 657                    | 65                     | 30                     |
| 120           | 1045                   | 104                    | 52                     |
| 160           | 1378                   | 137                    | 69                     |


![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/cf9c2481-09f4-428d-8533-d0548bff0eb8)

Zoom on 0.25mm ID tube : 
![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/e4f06cbb-78b4-4412-b6b9-dff5fdc6b0cd)

## 20230630 update:

today I ran tests with low flow sensor for the stability of the flow. 

the first stability test is with 0.5mm inner tube. We can see that it is not very stable around a value.
This graph shows the flow in nL/min depending on the time: 
![FirstTest](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/15ad39ea-9109-45c5-bbe8-129cab8496f2)


I ran the same test but this time with a node after the sensor going from a 0.5mm inner tube to a 0.25mm one. The flow now is pretty stable, but the problem that I got was that it was difficult to go less than 5 microlitters per minutes... I should run more tests on monday.
Here is the graph: 
![secondTest](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/3749c840-1d70-4d56-a806-f26555719781)


Again with the node, I ran two tests on the 4th of July. I ran the three next tests with the same parameters (50Vpp and 50Hz) to know more about the stability of the system at 3uL/min: 
![ThirdTest](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/a13b0f61-4e7a-46f1-84f9-8d719518f570)
![FourthTest](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/96cce11f-e996-40a8-80ae-e2acc1722c53)
![FifthTest](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/2a5aa705-3bfc-4bec-803e-d86b7270b872)





## 20230706 Note Vas
- The results of the tests show that the flow varies roughly linearly with the length of the tubing downstream of the pump (Good!)
- Theu also indicate about a factor of 10 when going from a 0.5 mm to 0.25 mm ID. This is roughly in agreement with a power of 4.

## Tests with Capillary
on the 18/07 I made the first test with capillary 

Two tests were made, one with longer capillary and one with smaller one 

First test on 15 minutes: 
length of the first tube = 14,5 cm
length of the second tube= 11,7 cm
Max frequency and max voltage on lowdriver

Second test on 15 minutes 
length of the first tube = 12,2 cm
length of the second tube = 9,2 cm
Max frequency and max voltage on lowdriver

flow is in nL/min
![TestCapilary](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/47bf0763-f764-42fd-a7c2-ff736834e00a)

Decreasing the length decrease the flow too

## Tests results on test about frequency and amplitude for a flow of 1000 nL/min

| Frequency (Hz)       | 725     | 110     | 110     | 690     | 608     | 103     | 102     | 525     | 405     | 128     | 235     | 361     | 334     | 265    |
|----------------------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|--------|
| Voltage (Vpp)        | 150     | 150     | 130     | 130     | 110     | 110     | 90      | 90      | 70      | 70      | 60      | 60      | 55      | 55     |
| Average flow(nL/min) | 1029,69 | 1052,41 | 1061,55 | 1011,06 | 1050,62 | 1063,04 | 1055,21 | 1021,66 | 1026,71 | 1018,47 | 1062,37 | 1024,28 | 1019,53 | 997,16 |
| Standart deviation   | 25,17   | 26,18   | 28,41   | 18,19   | 24,60   | 8,97    | 9,56    | 14,82   | 12,84   | 19,89   | 15,09   | 20,63   | 9,38    | 22,95  |

to reach 1000 nL/min we can: 
| Voltage | Low Frequency | High |
|---------|---------------|------|
| 150     | 110           | 725  |
| 130     | 110           | 690  |
| 110     | 103           | 608  |
| 90      | 102           | 525  |
| 70      | 128           | 405  |
| 60      | 235           | 361  |
| 55      | 265           | 334  |

![ChartFrequencyAmplitude1nLmin](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/18ddcae7-64af-4600-84ef-3358444a91e2)

I noticed that we can obtain 1000 nL/min with two different frequency for a same voltage... a high frequency and a low one. I also noticed that we can obtain 1000 nL/min with an amplitude of 55V for every frequency between 265 Hz and 334 Hz. 


