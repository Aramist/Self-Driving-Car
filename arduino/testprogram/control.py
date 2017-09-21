from inputs import  devices
from serial import Serial as S

GAS = b'a'
BRAKE = b'b'
FORMAT = '{:0>3}'
MIN = 6
MID = 91
MAX = 180

ser = S('/dev/ttyACM0', baudrate = 115200)
stick = devices.gamepads[0]

def read():
    data = stick.read()[0]
    if data.code == 'ABS_Y':
        return 'a' + FORMAT.format(norm(data.state))
    elif data.code == 'ABS_RZ':
        return 'b' + FORMAT.format(norm(data.state))
    else:
        return None

def norm(data):
    step1 = data - 512 #range: [-512, 512)
    step2 = step1 / 2048 #range: [-0.25, 0.25); formerly [-1, 1)
    step3 = 0
    if step2 < 0:
        step3 = (step2 + 1) * (MID - MIN) + MIN #range: [MIN, MID)
    elif step2 > 0:
        step3 = step2 * (MAX - MID) + MID #range: [MID, MAX)
    else:
        step3 = MID #range: [MID, MID]
    return int(step3)

def run():
    while True:
        datum = read()
        if not datum is None: #ensure that datum is not equal to None
            print(datum.encode('utf-8'))
            ser.write(datum.encode('utf-8'))

if __name__ == '__main__':
    run()
