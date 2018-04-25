/*
  Ultrasonic/Ping sensor (trig + echo combined into 1 pin)

  Code inspired by the Ping))) Sensor of the public domain and the 
  Light-up distance sensor (available at instructables, posted by 
  jreeve17, March 9, 2013).

  http://www.arduino.cc/en/Tutorial/Ping
  http://www.instructables.com/id/How-to-make-A-light-up-distance-sensor/

  written April 22, 2018
  By Carol Cheung

*/

// Ping sensor pins
int vcc = 2;
const int pingPin = 3; //setup pingpin as 3
int gnd = 5;

// Neopixel code

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 6);

// Neopixel pin
const int neopixelPin = 6; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into

void setup() {
  pinMode(vcc, OUTPUT);
  pinMode(gnd, OUTPUT);
  Serial.begin(9600);

  strip.begin();
  strip.show();

}
void loop() {

  digitalWrite(vcc, HIGH);
 
  long duration, inches;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);

  Serial.print(inches);
  Serial.print(" in");
  Serial.println();
  
  if (inches == 5) {
      //internet colours
      
      //red
      strip.setPixelColor(0, 255, 0, 0);
    } else if (inches == 6) {
      //orange
      strip.setPixelColor(0, 0xFF, 0xA5, 0x0); 
    } else if (inches == 7) {
      //yellow
      strip.setPixelColor(0, 0xFF, 0xFF, 0x0); 
    } else if (inches == 8) {
      //green
      strip.setPixelColor(0, 0, 255, 0);
    } else if (inches == 9) {
      //blue
      strip.setPixelColor(0, 0, 0, 255);
    } else if (inches == 10) {
      //indigo
      strip.setPixelColor(0, 0x4B, 0x0, 0x82);
    } else if (inches == 11) {
      //violet
      strip.setPixelColor(0, 0xEE, 0x82, 0xEE);
    } else {
      strip.setPixelColor(0, 0, 0, 0);
    }

  strip.setBrightness(60); 
  strip.show();
 
  delay(100);
}

long microsecondsToInches(long microseconds) {
  return microseconds/74/2;
}
