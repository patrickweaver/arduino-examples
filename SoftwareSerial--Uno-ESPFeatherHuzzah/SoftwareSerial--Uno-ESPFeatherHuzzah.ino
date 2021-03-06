// https://www.arduino.cc/en/Tutorial/SoftwareSerialExample

/* 
 *  Tested on two Arduino Unos, they must be wired with common ground
 *  When one of the Arduinos is programmed with a Raspberry Pi there is an extra
 *  '⸮' character preceeding the received transmission.
 */


/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo and Micro support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>

SoftwareSerial cSerial(12, 13); // RX, TX


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.flush();
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  delay(100);
  Serial.println("Local: Feather");

  // set the data rate for the SoftwareSerial port
  cSerial.begin(9600);
  cSerial.flush();
  delay(100);
  cSerial.println("Feather to Elegoo");
  cSerial.println("abcdefghijlkmnopqrstuvwxyz1234567890abcdefghijlkmnopqrstuvwxyz1234567890");
  
}

void loop() { // run over and over
  if (cSerial.available()) {
    Serial.write(cSerial.read());
  }
  if (Serial.available()) {
    cSerial.write(Serial.read());
  }
}
