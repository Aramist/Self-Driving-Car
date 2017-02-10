import Serial

class Control:

  ser = serial.Serial('/dev/ttyACM0',9600)
  s = [0]
  
  while True:
  
    def brake(boolean x):
      ser.write(x)
      
    def wheel(int y):
      ser.write(y)
      
    def gas(int z):
      ser.write(z)

    
