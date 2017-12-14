#! /usr/bin/env python
'''
This module reads data from the SwiftNav GNSS Development module
and relays it to the other modules through a ROS node
'''

from sbp.client.drivers.pyserial_driver import PySerialDriver
from sbp.client import Handler
from sbp.client import Framer
from sbp.client.loggers.json_logger import json_logger
from sbp.navigation import SBP_MSG_BASELINE_NED, MsgBaselineNED

import rospy
from std_msgs.msg import String

PORT = '/dev/swiftnav'

def main():
    '''Retreives data from GNSS module and sends it to a node'''
    publisher = rospy.Publisher('swiftnav-gnss', String, queue_size=10)
    rospy.init_node('swiftnav')
    with PySerialDriver(PORT, baud=1000000) as driver:
        with Handler(Framer(driver.read, None, verbose=True)) as source:
            while not rospy.is_shutdown():
                for msg, _ in source.filter(SBP_MSG_BASELINE_NED):
                    publisher.publish('{},{},{}'.format(msg.n * 1e-3, msg.e * 1e-3, msg.d * 1e-3))

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass