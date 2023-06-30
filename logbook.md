# Title : Log book high Accuracy vaporiser

- list 1
- list 2

## Tests with 0.5mm inner diameter 25 cm length

Measures with one pump at different voltage (peak to peak) and different frequency: 

![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/9f1d385e-8405-41a2-9753-2356415af098)

## Tests with 0.25mm inner diameter 25cm length

Measures with one pump at different voltage (peak to peak) and different frequency: 

![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/0c760832-68f9-4b99-9ce7-b7d951792574)

## Update 24/05

I am now able to read the value from the new flow sensor with the arduino code in the folder "readSensorValue"

## Tests with 0.25mm inner diameter 50cm length

Measures with one pump at different voltage (peak to peak) and different frequency: 

![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/ed23f4c7-ea4f-4cfd-8489-96aee1461938)

## Conclusion on different tests

| Conclusion    |                        |                        |                        |
|---------------|------------------------|------------------------|------------------------|
| inner tube :  | 0.5 mm                 | 0.25 mm                | 0.25 mm                |
| tube length : | 25 cm                  | 25 cm                  | 50 cm                  |
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

Zoom on 0.25mm inner tube : 
![image](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/e4f06cbb-78b4-4412-b6b9-dff5fdc6b0cd)

## 30/06 update:

today I ran tests with low flow sensor for the stability of the flow. 

the first stability test is with 0.5mm inner tube. We can see that it is not very stable around a value.
This graph shows the flow in nL/min depending on the time: 
![FirstTest](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/e618229d-20aa-4c75-86ca-4f534d6d2d44)

I ran the same test but this time with a node after the sensor going from a 0.5mm inner tube to a 0.25mm one. The flow now is pretty stable, but the problem that I got was that it was difficult to go less than 5 microlitters per minutes... I should run more tests on monday.
Here is the graph: 
![SeondTest](https://github.com/vgkinis/high_accuracy_vaporiser_NBI/assets/72393572/a6aa5d3f-59ad-40e0-b95f-906e737570df)



