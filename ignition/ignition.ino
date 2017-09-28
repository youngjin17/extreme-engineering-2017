#include <IRremote.h>
#include <Servo.h>

#define ONE 0xFFA25D
#define TWO 0xFF629D
#define THREE 0xFFE21D
#define FOUR 0xFF22DD
#define FIVE 0xFF02FD
#define SIX 0xFFC23D
#define SEVEN 0xFFE01F
#define EIGHT 0xFFA857
#define NINE 0xFF906F

#define RIGHT 0xFF5AA5
#define LEFT 0xFF10EF
#define UP 0xFF18E7
#define DOWN 0xFF4AB5


IRrecv irrecv(11);//Receive on pin 11
decode_results results;
int ignition = 2;

void setup() {
  Serial.println("start");
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(ignition, OUTPUT);

}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == NINE) {
    Serial.println("nice");
    digitalWrite(ignition, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);             // wait for a tenth of a second
    }
    irrecv.resume(); // Receive the next value

  }
  digitalWrite(ignition, LOW);
  delay(100);
}
