#include "L298.h"
#include "NewPing.h"
L298 robot(5, 2, 4, 6, 7, 8);

#define TRIGGER_PIN 11
#define ECHO_PIN 10
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

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
