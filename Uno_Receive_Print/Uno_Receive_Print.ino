#include <SoftwareSerial.h>

#include "Adafruit_Thermal.h"

#define TO_PRINT_TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define TO_PRINT_RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial cSerial(2, 4); // RX, TX
SoftwareSerial pSerial(TO_PRINT_RX_PIN, TO_PRINT_TX_PIN);
Adafruit_Thermal printer(&pSerial);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.flush();
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  delay(100);
  Serial.println("Local: Elegoo");

  // set the data rate for the SoftwareSerial port
  cSerial.begin(9600);
  cSerial.flush();
  delay(100);
  cSerial.println("Elegoo to Feather");

  
  //delay(100);
  printer.begin();
  pSerial.begin(19200);
  delay(100);
  printer.println("a");
  printer.feed(4);
  Serial.println("Setup Done");
}

void loop() { // run over and over
  int a;
  if (cSerial.available()) {
    a = cSerial.read();
    Serial.println(a);
    pSerial.begin(19200);
    delay(100);
    printer.println(a);
    printer.feed(4);
    Serial.write(a);
  }
  if (Serial.available()) {
    cSerial.write(Serial.read());
    pSerial.begin(19200);
    delay(100);
    printer.println(a);
    printer.feed(4);
  }
}
