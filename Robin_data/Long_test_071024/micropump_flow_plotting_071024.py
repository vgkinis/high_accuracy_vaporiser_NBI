# -*- coding: utf-8 -*-
"""
Modified to handle multiple files: TESTn.TXT (n starting from 1 and increasing),
and combine the data for a continuous plot.
"""

import numpy as np
import matplotlib.pyplot as plt
import os

# Directory where the files are stored
directory = r'C:\Users\prh754\Documents\KU_postdoc_isoDEEPICE\Micro_pump\DATA\Long_test_071024'

# Initialize lists to store all data from multiple files
combined_data = []
combined_data_avg = []
combined_time = []
combined_time_avg = []

# Start loading multiple files based on the pattern TESTn.TXT
n = 1  # Starting file number
current_time = 0  # Track the cumulative time in seconds
current_time_avg = 0  # Track the cumulative time in minutes for averaged data

while True:
    file_name = f'TEST{n}.TXT'
    file_path = os.path.join(directory, file_name)
    
    # Try to load the file, if it doesn't exist, break the loop
    try:
        data = np.loadtxt(file_path)
        print(f"Loaded file: {file_name}")
    except OSError:
        print(f"No more files to load. Last file checked: {file_name}")
        break

    # Append raw data
    combined_data.extend(data)
    
    # Create a time array for raw data (assuming each data point is 1 second apart)
    time = np.arange(len(data)) + current_time
    combined_time.extend(time)
    
    # Update the current time for the next file
    current_time += len(data)
    
    # Calculate 1-minute averaged data (60 data points per minute)
    truncated_len = len(data) - len(data) % 60  # Truncate length to a multiple of 60
    data_avg = np.mean(data[:truncated_len].reshape(-1, 60), axis=1)
    
    # Create a time array for the averaged data (1 data point per minute)
    time_avg = np.arange(len(data_avg)) + current_time_avg
    combined_data_avg.extend(data_avg)
    combined_time_avg.extend(time_avg)
    
    # Update the current averaged time for the next file (in minutes)
    current_time_avg += len(data_avg)
    
    # Move to the next file (increment n)
    n += 1

# Convert combined data and time lists to numpy arrays for consistency
combined_data = np.array(combined_data)
combined_data_avg = np.array(combined_data_avg)
combined_time = np.array(combined_time)
combined_time_avg = np.array(combined_time_avg)

# Plot the raw and averaged data combined for all files
plt.figure(figsize=(10, 6), dpi=150)
plt.plot(combined_time / 60 /60, combined_data , label='Raw Flow Rate')
plt.plot(combined_time_avg / 60, combined_data_avg, label='1 min mean', color='orange', linewidth=2)

plt.xlabel('Time (hours)')
plt.ylabel('Flow Rate (nl/min)')
plt.title('Flow Rate vs. Time')
plt.grid(True)
plt.legend()
plt.show()

# Calculate the total volume pumped over 1 hour for the combined data
total_volume_raw = np.sum(combined_data) / 60.0 / 1000  # nl to μl
total_volume_avg = np.sum(combined_data_avg) / 1000  # nl to μl

# Calculate the total duration in minutes
total_duration_minutes = len(combined_data) / 60.0

# Print the results for the combined data
print(f"\nTotal volume pumped over {total_duration_minutes:.2f} minutes (using raw data): {total_volume_raw:.2f} μl")
print(f"Total volume pumped over {total_duration_minutes:.2f} minutes (using 1-minute averaged data): {total_volume_avg:.2f} μl")
