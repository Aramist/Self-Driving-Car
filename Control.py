import serial

class Control:

  ser = serial.Serial('/dev/ttyACM0',9600)
  s = [0]
  
  while True:
  
    def brake(x):
      ser.write(x)
      
    def wheel(y):
      ser.write(y)
      
    def gas(z):
      ser.write(z)

    
