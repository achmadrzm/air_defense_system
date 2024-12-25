#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <dht.h>

#define SERVOMIN 170 //150 //650
#define SERVOMAX 470 //600 //2350
#define FREQUENCY 50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver ();

const int laser = 7;
const int dht22 = 8;
const int trigger = 9;
const int echo = 10;
const int buzzer = 12;
const int led = 13;

float duration, distance;
float speed;

unsigned long previousMillis = 0;
const long interval1120 = 100;
const long interval2130 = 500;

dht DHT;

void setup() {
  pinMode(laser, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);

  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

void loop() {
  for(int i=SERVOMIN;i<=SERVOMAX;i++){
    pwm.setPWM(12, 0, i);
    //delay(15);
    distance = calculateDistance();
    
    Serial.print(i);
    Serial.print("a");
    Serial.print(distance);
    Serial.print("d");

    if (distance <= 10) {
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, HIGH);
      pwm.setPWM(13, 0, i+1);
      //pwm.setPWM(14, 0, i);
      digitalWrite(laser, HIGH);
      //delay(1000);
    } else if (distance >= 11 && distance <= 20) {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= interval1120) {
        previousMillis = currentMillis;
        static int state = LOW;
        if (state == LOW) {
          state = HIGH;
        } else {
          state = LOW;
        }
        digitalWrite(buzzer, state);
        digitalWrite(led, state);
      }
      pwm.setPWM(13, 0, i+1);
      //pwm.setPWM(14, 0, i);
      digitalWrite(laser, HIGH);
    } else if (distance >= 21 && distance <= 30) {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= interval2130) {
        previousMillis = currentMillis;
        static int state = LOW;
        if (state == LOW) {
          state = HIGH;
        } else {
          state = LOW;
        }
        digitalWrite(buzzer, state);
        digitalWrite(led, state);
      }
      pwm.setPWM(13, 0, i+1);
      //pwm.setPWM(14, 0, i)
      digitalWrite(laser, HIGH);
    } else {
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);
      digitalWrite(laser, LOW);
    }
  }

  for(int i=SERVOMAX;i>SERVOMIN;i--){
    pwm.setPWM(12, 0, i);
    //delay(15);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print("a");
    Serial.print(distance);
    Serial.print("d");

    if (distance <= 10) {
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, HIGH);
      pwm.setPWM(13, 0, i+1);
      //pwm.setPWM(14, 0, i);
      digitalWrite(laser, HIGH);
      //delay(1000);
    } else if (distance >= 11 && distance <= 20) {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= interval1120) {
        previousMillis = currentMillis;
        static int state = LOW;
        if (state == LOW) {
          state = HIGH;
        } else {
          state = LOW;
        }
        digitalWrite(buzzer, state);
        digitalWrite(led, state);
      }
      pwm.setPWM(13, 0, i+1);
      //pwm.setPWM(14, 0, i);
      digitalWrite(laser, HIGH);
    } else if (distance >= 21 && distance <= 30) {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= interval2130) {
        previousMillis = currentMillis;
        static int state = LOW;
        if (state == LOW) {
          state = HIGH;
        } else {
          state = LOW;
        }
        digitalWrite(buzzer, state);
        digitalWrite(led, state);
      }
      pwm.setPWM(13, 0, i+1);
      //pwm.setPWM(14, 0, i);
      digitalWrite(laser, HIGH);
    } else {
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);
      digitalWrite(laser, LOW);
    }
  }
}

int calculateDistance(){ 

  digitalWrite(trigger, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  speed = 331.4 + (0.606 * DHT.temperature) + (0.0124 * DHT.humidity);
  distance = (duration / 2) * (speed / 10000);
  return distance;
}