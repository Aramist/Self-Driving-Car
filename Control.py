from serial import Serial

class Control:
    '''
    A class that facilitates sending commands to the physical peripherals of the cart.
    '''
    def __init__(self):
        #Open the serial port to begin communications with the Arduino
        #It is likely that this may be edited, as there may be more than one Arduino in use
        self.ser = Serial('/dev/ttyACM0', 9600)
        #What is the s field for?
        self.s = [0]

    def brake(self, brake_value):
        '''
        Sends an angle to the brakes
        Params:
          brake_value: An int. The angle that will be sent to the brake's servo.
        '''
        #to JR: Does the brake command need an angle sent with it? Let me know.
        self.ser.write('b{}'.format(brake_value))

    def wheel(self, wheel_value):
        '''
        Sends an angle to the wheel
        Params:
          wheel_value: An int. The angle that will be sent to the wheel's servo.
        '''
        self.ser.write('w{}'.format(wheel_value))

    def gas(self, gas_value):
        '''
        Sends an angle to the gas pedal
        Params:
          gas_value: An int. The angle that will be sent to the gas' servo.
        '''
        self.ser.write('g{}'.format(gas_value))
