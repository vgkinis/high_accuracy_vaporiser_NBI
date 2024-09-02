# -*- coding: utf-8 -*-
"""
Created on Wed Aug 21 14:36:48 2024

@author: prh754
"""

import numpy as np
import matplotlib.pyplot as plt
import os

# File path
file_path = r'C:\Users\prh754\Documents\KU_postdoc_isoDEEPICE\Micro_pump\DATA\Flow_tests\TEST_100Hz_150V_cycleNO_020924_n2.txt'

# Load the data from the file
data = np.loadtxt(file_path)

# Extract a readable version of the file name (without the path and extension)
file_name = os.path.splitext(os.path.basename(file_path))[0]

# Create an array for time assuming each data point is 1 second apart
time = np.arange(len(data))

# Calculate 1-minute averaged data (60 data points per minute)
# Truncate the data length to a multiple of 60 for proper averaging
truncated_len = len(data) - len(data) % 60
data_avg = np.mean(data[:truncated_len].reshape(-1, 60), axis=1)

# Create a time array for the averaged data (1 data point per minute)
time_avg = np.arange(len(data_avg))  # already in minutes since 1 avg data point per minute

# Plot the raw and averaged data
plt.figure(figsize=(10, 6), dpi=150)
plt.plot(time / 60, data, label='Raw Flow Rate')
plt.plot(time_avg, data_avg, label='1 min mean', color='orange', linewidth=2)
plt.xlabel('Time (minutes)')
plt.ylabel('Flow Rate (nl/min)')
plt.title(f'Flow Rate vs. Time\n{file_name}')
plt.grid(True)
plt.legend()
plt.show()

# Calculate the total volume pumped for 1 hour using the raw data
# Time step is 1 second, flow rate is in nl/min, so convert to nl/second
total_volume_raw = np.sum(data[:len(data)]) / 60.0 / 1000  # nl (nanoliters)

# Calculate the total volume pumped for 1 hour using the 1-minute averaged data
# Time step is 60 seconds for each averaged point
total_volume_avg = np.sum(data_avg[:len(data_avg)]) / 1000  # nl (nanoliters)


# Calculate the total duration in minutes
total_duration_minutes = len(data) / 60.0

# Print the results
print(f"Total volume pumped over {total_duration_minutes:.2f} minutes (using raw data): {total_volume_raw:.2f} mul")
print(f"Total volume pumped over {total_duration_minutes:.2f} minutes (using 1-minute averaged data): {total_volume_avg:.2f} mul")

