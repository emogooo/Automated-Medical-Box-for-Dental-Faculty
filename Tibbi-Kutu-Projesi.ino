#include <Servo.h>
#include <MyRealTimeClock.h>
MyRealTimeClock RTC(12, 11, 10);
#define servo1Pin 2
#define servo2Pin 3
Servo servo1;
Servo servo2;

int saat = 0;
int kapak1AcilmaSaati = 1650;
int kapak1KapanmaSaati = 1651;
int kapak2AcilmaSaati = 1750;
int kapak2KapanmaSaati = 1751;
bool servo1Kontrol = false;
bool servo2Kontrol = false;

void setup() {
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
}

void loop() {
  RTC.updateTime();
  saat = (RTC.hours * 100) + RTC.minutes;
  if(saat >= kapak1AcilmaSaati && saat < kapak1KapanmaSaati){
   servo1Don(); 
  }
  if(saat >= kapak2AcilmaSaati && saat < kapak2KapanmaSaati){
   servo2Don();
  }
  delay(60000);
}

void servo1Don(){
  if(servo1Kontrol){
       servo1.write(180);
  }else{
       servo1.write(90);
  }
  servo1Kontrol = !servo1Kontrol;
}

void servo2Don(){
 if(servo2Kontrol){
       servo2.write(180);
  }else{
       servo2.write(90);
  }
  servo1Kontro2 = !servo2Kontrol;
}
