

#include <NewPing.h>//chama biblioteca new ping
#include <Servo.h>
#define trigPin 12// pino trig conectado ao pino 12 de arduino
#define echoPin 13//pino echo como pino 13 do arduino
#define MAX_DISTANCE 500
NewPing Sonar(trigPin, echoPin, MAX_DISTANCE);
int greenLed=3, redLed = 2;//Associa o led verde ao pino 3 e o LED vermelho ao pino 2

int pos =20;
Servo myservo;
void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLed, OUTPUT); 
  
  pinMode(redLed, OUTPUT);
  myservo.attach(9);//servomotor conectado ao pino 9
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
int duration, distance, pos =0,i;
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH); //o pino Trig envia um ping
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);//recebe o ping
distance = (duration/2) / 29.1;
Serial.print(distance);
Serial.println(" cm");
if(distance<=30){
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
  myservo.write(180);
  delay(500);
  digitalWrite(redLed, LOW);
  myservo.write(90);
  delay(350);
  myservo.write(90);
}
else{
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  myservo.write(90);
}
delay(450);
}
