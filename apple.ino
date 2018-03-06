/***************************************************
  This is a library for the CAP1188 I2C/SPI 8-chan Capacitive Sensor

  Designed specifically to work with the CAP1188 sensor from Adafruit
  ----> https://www.adafruit.com/products/1602

  These sensors use I2C/SPI to communicate, 2+ pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_CAP1188.h>

// Reset Pin is used for I2C or SPI
#define CAP1188_RESET  9

// CS pin is used for software or hardware SPI
#define CAP1188_CS  10

// These are defined for software SPI, for hardware SPI, check your
// board's SPI pins in the Arduino documentation
#define CAP1188_MOSI  11
#define CAP1188_MISO  12
#define CAP1188_CLK  13

// For I2C, connect SDA to your Arduino's SDA pin, SCL to SCL pin
// On UNO/Duemilanove/etc, SDA == Analog 4, SCL == Analog 5
// On Leonardo/Micro, SDA == Digital 2, SCL == Digital 3
// On Mega/ADK/Due, SDA == Digital 20, SCL == Digital 21

// Use I2C, no reset pin!
Adafruit_CAP1188 cap = Adafruit_CAP1188();

// Or...Use I2C, with reset pin
//Adafruit_CAP1188 cap = Adafruit_CAP1188(CAP1188_RESET);

// Or... Hardware SPI, CS pin & reset pin
// Adafruit_CAP1188 cap = Adafruit_CAP1188(CAP1188_CS, CAP1188_RESET);

// Or.. Software SPI: clock, miso, mosi, cs, reset
//Adafruit_CAP1188 cap = Adafruit_CAP1188(CAP1188_CLK, CAP1188_MISO, CAP1188_MOSI, CAP1188_CS, CAP1188_RESET);

int capPad[8];

void setup() {
  Serial.begin(9600);
  Serial.println("CAP1188 test!");

  // Initialize the sensor, if using i2c you can pass in the i2c address

  if (!cap.begin()) {
    Serial.println("CAP1188 not found");
    while (1);
  }
  Serial.println("CAP1188 found!");
  pinMode(13, OUTPUT);
}

void loop() {
  byte touched = cap.touched();
  
  //capture values of capacitive sensors in an array
  for (byte i = 0; i < 8; i++) {
    byte mask = 1 << i; 
    if (touched & mask) { 
      capPad[i] = 1;
      //String Mystring = String(mask);
      //int outData = Mystring.toInt();
      //Serial.write(outData);

    } else {
      capPad[i] = 0;
    }

    //Serial.print(capPad[i]);
  }
  //Serial.println();
  //String mystring = String((char*)capPad);
  //Serial.println('here is my data '+mystring);
  

  // sensor values are now accessible - capPad[0] through capPad[7]
  if (capPad[1] == 1) {
    Serial.write(1);
    Serial.print(1);
  } 
  if (capPad[3] == 1) {
    Serial.write(3);
    Serial.print(3);
  } 
 
  if (capPad[5] == 1) {
    Serial.write(5);
    Serial.print(5);
  } 
  if (capPad[6] == 1) {
    Serial.write(6);
    Serial.print(6);
  } 
  else{
    Serial.write(0);
  }
  delay(50);
}

