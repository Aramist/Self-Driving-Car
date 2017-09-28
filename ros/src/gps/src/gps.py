'''
This module reads data from the SwiftNav GNSS Development module
and relays it to the other modules through a ROS node
'''

from sbp.client.drivers.pyserial_driver import PySerial_Driver
from sbp.client import Handler
from sbp.client import Framer
from sbp.client.loggers.json_logger import json_logger
from sbp.navigation import SBP_MSG_BASELINE_NED, MsgBaselineNED


PORT = '/dev/ttyUSB0'

def main():
    '''Retreives data from GNSS module and sends it to a node'''
    with PySerialDriver(PORT, baud=1000000) as driver:
        with Handler(Framer(driver.read, None, verbose=True)) as source:
            try:
                for msg, metadata in source.filter(SBP_MSG_BASELINE_NED):
                    print('{},{},{}'.format(msg.n * 1e-3, msg.e * 1e-3, msg.d * 1e-3))
            except KeyboardInterrupt:
                pass

if __name__ == '__main__':
    main()