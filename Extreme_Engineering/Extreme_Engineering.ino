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
int posTop=90; // variable to store the servo position
int posBottom=90;
int Speed=15; // Number of degrees to move each time a left/right button is pressed
int acceleration;
long Previous; // Stores previous code to handle NEC repeat codes
int ignition = 2;
int engine = 3;
boolean engineOn = false;
void setup() {
  setupIR();
  setupPorts();
}

void loop() {
  if (irrecv.decode(&results)) {
    if(results.value==0xFFFFFFFF)
      results.value=Previous;
    if (results.value == NINE){
      ignitionLoop();
    }
    else {
      sailLoop();
    }
    irrecv.resume();
  }
  delay(100);
}

void setupIR() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("start IR");
}

void setupPorts() {
  Rudder.attach(A1);
  Sail.attach(A2);  //attaches the servo on pin 1  the servo object
  pinMode(ignition, OUTPUT);
  pinMode(engine, OUTPUT);
}

void sailLoop() {
  
  switch(results.value) {
        case LEFT:
          posTop=min(360,posTop+Speed);
          Serial.println("left");
          break;
        case RIGHT: 
          posTop=max(0,posTop-Speed);
          Serial.println("right");
          break;
        case FOUR:
          posBottom=min(360,posBottom+Speed);
          Serial.println("four");
          break;
        case SIX:
          posBottom=max(0,posBottom - Speed);
          Serial.println("six");
          break;
      }
      Sail.write(posTop); // tell servo to go to position in variable 'pos'
      Rudder.write(posBottom);
      Previous=results.value;
}


void ignitionLoop() {
  Sail.write(90);
  Rudder.write(90);
    digitalWrite(ignition, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100); 
    digitalWrite(ignition, LOW);
    delay(2500);
    Sail.write(posTop);
}

