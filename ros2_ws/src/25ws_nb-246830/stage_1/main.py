#!/usr/bin/env python3
import ast

# Set constants
angle_min = -1.57079637051
angle_max = 1.53938043118
angle_incr = 0.0314159281552

'''
TODO: This function returns the length of a given list.
'''
def get_length(scan_data):
    return len(scan_data)  # Use scan_data parameter, not self.scan_data

'''
TODO: Find the index of the closest point in the scan_data.
'''
def get_index_of_closest_point(scan_data):
    #if not scan_data:
     #   return None  # Return None if scan_data is empty

    #closest_index = 0
    #closest_distance = scan_data[0]

    #for index, distance in enumerate(scan_data):
    #    if distance < closest_distance:
    #        closest_distance = distance
    #        closest_index = index

    idx = min(filter(lambda x : x > 0.0, scan_data), default=None)
    idx = scan_data.index(idx) 

    return idx

'''
TODO: Calculate the angle in radians for the closest point in scan_data.
'''
def get_angle_of_closest_point(scan_data):
    closest_index = get_index_of_closest_point(scan_data)
    if closest_index is None:
        return None  # Return None if there is no closest point

    # Calculate the angle based on the closest index
    angle = angle_min + closest_index * angle_incr
    return angle

def get_laserdata(path):
    with open(path, "r") as file:  # Use a context manager to handle file
        laserdata_raw = file.read()
        laserdata = ast.literal_eval(laserdata_raw)

    return laserdata

if __name__ == "__main__":
    # Print header
    print("####################")
    print("Python exercise")
    print("####################")

    # Read raw laser data
    scan_data = get_laserdata("laser-testdata_1")

    # Print length of scan_data
    print("Length of scan data: {0}".format(get_length(scan_data)))

    # Print index of closest point
    print("Index of closest point: {0}".format(get_index_of_closest_point(scan_data)))

    # Print angle of closest point
    print("Angle of closest point: {0}".format(get_angle_of_closest_point(scan_data)))

