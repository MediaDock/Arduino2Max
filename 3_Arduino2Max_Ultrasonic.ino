/*
  Example modified, just putting out a integer value through serial output. 

  Based_On: 
  https://dronebotworkshop.com/hc-sr04-ultrasonic-distance-sensor-arduino/
  https://www.youtube.com/watch?v=6F1B_N6LuKw
  
  HC-SR04 Basic Demonstration
  HC-SR04-Basic-Demo.ino
  Demonstrates functions of HC-SR04 Ultrasonic Range Finder
  Displays results on Serial Monitor  
*/

// This uses Serial Monitor to display Range Finder distance readings
// Hook up HC-SR04 with trigger to Arduino Pin 10, Echo to Arduino pin 13

#define triggerPin 10
#define echoPin 13

float duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
   
  // Write a pulse to the HC-SR04 triggergerger Pin
  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
 
  duration = pulseIn(echoPin, HIGH);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  
  distance = (duration / 2) * 0.0343;
  
  // Send results to Serial Monitor
  
  if (distance >= 400 || distance <= 2) {
     Serial.println(0);
  }
  else {
    Serial.print(distance);
    delay(500);
  }
  delay(500);
}
