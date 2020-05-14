int analog0;// обозначаем переменную <<analog0>>
#include <Ultrasonic.h> // обозначаем библиотеку <<Ultrasonic.h>>
Ultrasonic ultrasonic(12, 13); // обозначаем пины <<УЗ дальномера>> (13 echo , 12 trig)
int Max ; // обозначаем переменную <<Max>>
int distance;// обозначаем переменную<<distance>>
void setup() {
  Serial.begin(9600);// обозначаем Serial порт (Bluetooth)
  pinMode(6,OUTPUT);// обозначаем пины светодиодов
  pinMode(5,OUTPUT);// обозначаем пины светодиодов
   pinMode(A0,INPUT);// обозначаем пин патэнциометра
  Max= ultrasonic.read();
    Max=Max-13;
          for (int i=0;i<3;i++) {
    digitalWrite(5,1);
      delay(100);
    digitalWrite(5,0);
      delay(100);
   }    
}
void loop() {
analog0=analogRead(0);   
distance = ultrasonic.read();  
Serial.print("Distance in CM: ");
Serial.print(distance);
reaktsiya ();
delay(analog0); 
}
void reaktsiya () {
  if(distance >= Max) {
    Serial.println(",off");
   digitalWrite(6,0);  
  }else{
  Serial.println(",on");
   digitalWrite(6,1); 
   }
}
