#!/usr/bin/env python3
import ast
import math
import time

class LaserModel(object):

    def __init__(self, angle_min, angle_max, range_min, range_max):
        # Basic settings of your laser
        self.angle_min = angle_min
        self.angle_max = angle_max
        self.range_min = range_min
        self.range_max = range_max
        self.angle_inc = 0

        # Member variables
        self.scan_data = []
        self.laser_read_cycle = -1

    def update_laserdata(self, laserdata_file):
        """Update the laser data from a file."""
        with open(laserdata_file, "r") as file:
            laserdata_raw = file.read()
            scan_data_raw = ast.literal_eval(laserdata_raw)

        self.scan_data = scan_data_raw[self.laser_read_cycle % len(scan_data_raw)]
        self.laser_read_cycle += 1

    def set_angle_inc(self, angle_inc):
        """Set the angle increment."""
        self.angle_inc = angle_inc

    def get_angle_inc(self):
        """Get the angle increment."""
        return self.angle_inc

    def get_scan_length(self):
        """Return the length of the scan data."""
        return len(self.scan_data)

    def calc_angle_inc(self):
        """Calculate the angle increment."""
        # Calculate angle increment based on the provided angles and the length of scan data
        return (self.angle_max - self.angle_min) / self.get_scan_length()

    def calc_index_of_closest_point(self):
        idx = min(filter(lambda x : x > 0.0, self.scan_data), default=None)
        idx = self.scan_data.index(idx) 

        return idx
    def calc_angle_of_closest_point(self):
        """Calculate the angle of the closest point."""
        closest_index = self.calc_index_of_closest_point()
        if closest_index is None:
            return None  # No valid point found

        # Calculate angle based on the closest index
        angle = self.angle_min + closest_index * self.angle_inc
        return angle

    def run(self):
        """Core method for your function calls."""
        self.update_laserdata("laser-testdata_2")
        print("-" * 20 +
              str("\nCurrent cycle: {0}" +
                  "\nIndex of closest point: {1}" +
                  "\nAngle of closest point: {2}"
                  ).format(self.laser_read_cycle, 
                            self.calc_index_of_closest_point(), 
                            self.calc_angle_of_closest_point())
             )

if __name__ == '__main__':
    # Instantiate the class and set parameters
    app = LaserModel(-math.pi/2, math.pi/2, 0.0, 7.0)
    app.update_laserdata("laser-testdata_2")
    app.set_angle_inc(app.calc_angle_inc())

    print("-" * 20 +
          str("\nAngle increment: {}" +
              "\nLength of scan data: {}"
              ).format(app.get_angle_inc(), app.get_scan_length())
          )

    # Run the script in a loop to continuously read and process laser data
    while True:
        app.run()
        time.sleep(1)

