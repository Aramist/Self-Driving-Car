from serial import Serial
from geopy.point import Point

class GPS(object):
    def __init__(self):
        #initiate GPS
        self.location = Point(0,0)
        self.relative = True

    def update(self):
        pass