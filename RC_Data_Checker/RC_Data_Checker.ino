/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
#define ONE 0xFFA25D
#define TWO FF629D
#define THREE FFE21D
#define FOUR FF22DD
#define FIVE FF02FD
#define SIX FFC23D
#define SEVEN FFE01F
#define EIGHT FFA857
#define NINE FF906F

#define RIGHT FF5AA5
#define LEFT FF10EF
#define UP FF18E7
#define DOWN FF4AB5

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    boolean factor = (results.value == ONE);
    if (factor) {
      digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
    irrecv.resume(); // Receive the next value


  }
  delay(100);
}
