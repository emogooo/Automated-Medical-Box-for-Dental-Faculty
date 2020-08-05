#include <Servo.h>
#include <MyRealTimeClock.h>

MyRealTimeClock RTC(12, 11, 10);

Servo servo1;
Servo servo2;

int servo1Pin = 2;
int servo2Pin = 3;
int saat = 0;
int servo1Kontrol = 0;
int servo2Kontrol = 0;

int kapak1AcilmaSaati = 1658;
int kapak1KapanmaSaati = 1659;

void setup() {
  Serial.begin(9600);
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
}

void loop() {
  RTC.updateTime();
  saat = (RTC.hours * 100) + RTC.minutes;
  Serial.println(saat); 
  if(saat >= kapak1AcilmaSaati && saat < kapak1KapanmaSaati){
   kapak1AcKapa(); 
  }
  if(saat >= 1650 && saat < 1651){
   kapak2AcKapa();
  }
  delay(1000);
}

void servo1Don(){
  
  if(servo1Kontrol == 0){
     for(int pos = 90; pos <= 180; pos++){
       servo1.write(pos);
       delay(10);
     }
  }else if(servo1Kontrol == 1){
     for(int pos = 180; pos >= 90; pos--){
       servo1.write(pos);
       delay(10);
     }
  }
  servo1Kontrol = (servo1Kontrol + 1)%2;
}

void servo2Don(){
  
  if(servo2Kontrol == 0){
     for(int pos = 90; pos <= 180; pos++){
       servo2.write(pos);
       delay(10);
     }
  }else if(servo2Kontrol == 1){
     for(int pos = 180; pos >= 90; pos--){
       servo2.write(pos);
       delay(10);
     }
  }
  servo2Kontrol = (servo2Kontrol + 1)%2;
}

void kapak1AcKapa(){  
  RTC.updateTime();
  saat = (RTC.hours * 100) + RTC.minutes; 
  while(saat >= kapak1AcilmaSaati && saat < kapak1KapanmaSaati){  
    RTC.updateTime();
    saat = (RTC.hours * 100) + RTC.minutes;
    Serial.println(saat);    
    if(servo1Kontrol == 0){
      servo1Don();
    }    
    delay(1000);
  }
  servo1Don();
}
void kapak2AcKapa(){
  RTC.updateTime();
  saat = (RTC.hours * 100) + RTC.minutes; 
  while(saat >= 1530 && saat <= 1730){  
    RTC.updateTime();
    saat = (RTC.hours * 100) + RTC.minutes;    
    if(servo2Kontrol == 0){
      servo2Don();
    }    
    delay(30000);
  }
  servo2Don();
}
