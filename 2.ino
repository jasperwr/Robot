#include "L298.h"
#include "NewPing.h"
L298 robot(5, 2, 4, 6, 7, 8);

#define TRIGGER_PIN 11
#define ECHO_PIN 10
#define MAX_DISTANCE 400

NewPing sonarleft(11, 10, MAX_DISTANCE);
NewPing sonarcenter(7, 6, MAX_DISTANCE);
NewPing sonrright(3, 2, MAX_DISTANCE);

void setup() 
{
  Serial.begin(9600);
} 

void loop() {
  delay(100);
  int uS = sonar.ping();
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
  
  int distance = uS / US_ROUNDTRIP_CM;
  
  if ( distance < 35 ) {
    robot.turnLeft(200);
  }
  else {
    robot.test(255);
  }
}
// Afwijking correctie!
