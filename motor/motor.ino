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
const int in_1 = 3 ;
const int in_2 = 4 ;

void setup() {
  Serial.println("start");
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(in_1,OUTPUT) ;  //Logic pins are also set as output
  pinMode(in_2,OUTPUT) ;
}

void loop()
{
//For Clock wise motion , in_1 = High , in_2 = Low

  digitalWrite(in_1,HIGH) ;
  digitalWrite(in_2,LOW) ;

/*setting pwm of the motor to 255
we can change the speed of rotaion
by chaning pwm input but we are only
using arduino so we are using higest
value to driver the motor  */

  //Clockwise for 3 secs
  delay(3000) ;     
 }
