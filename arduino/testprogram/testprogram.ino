#include <Servo.h>

Servo gas;
Servo brake;
 
char buffer[4] = {0};
int bufferIndex = 0;

void setup(){
    Serial.begin(115200);
    gas.attach(9);
    brake.attach(10);
}

void loop(){
    //sendData();
    if(Serial.available() > 0) buffer[bufferIndex++] = Serial.read();
    if(bufferIndex > 3){
        int identifier = (int)buffer[0] - 97;
        int hundred = (int)buffer[1] - 48;
        int ten = (int)buffer[2] - 48;
        int one = (int)buffer[3] - 48;
        if(identifier != 0 && identifier != 1){
            bufferIndex = 0;
            return;
        }
        if(identifier == 0){
            gas.write(100 * hundred + 10 * ten + one);
        }else if(identifier == 1){
            brake.write(100 * hundred + 10 * ten + one);
        }
        bufferIndex = 0;
    }
}

void sendData(){
    Serial.println(analogRead(A0));
}
