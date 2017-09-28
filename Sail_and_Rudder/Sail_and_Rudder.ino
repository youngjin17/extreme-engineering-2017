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
Servo Sail; // create servo object to control a servo
Servo Rudder;
int posTop; // variable to store the servo position
int posBottom;
int Speed; // Number of degrees to move each time a left/right button is pressed
int acceleration;
long Previous; // Stores previous code to handle NEC repeat codes

void setup() {
  Serial.println("start");
  Serial.begin(9600);
  Sail.attach(A2);  //attaches the servo on pin 1  the servo object
  Rudder.attach(A1);
  Serial.println("Enabling IRin");
  posTop = 90;
  Speed = 15;
  Sail.write(posTop); // Set initial position
  irrecv.enableIRIn(); // Start the receiver
    Serial.println("Enabled IRin");
    
}

void loop() {
  if (irrecv.decode(&results)) {
      if(results.value==0xFFFFFFFF)
        results.value=Previous;
      
    }
    delay(100);
    
  }
