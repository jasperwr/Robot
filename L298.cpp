#include "L298.h"



L298::L298(int motorA, int pinA1, int pinA2, int motorB, int pinB1, int pinB2)
:
	_motorA(motorA), _pinA1(pinA1), _pinA2(pinA2), _motorB(motorB), _pinB1(pinB1), _pinB2(pinB2)
{
	pinMode(motorA, OUTPUT);
	pinMode(pinA1, OUTPUT);
	pinMode(pinA2, OUTPUT);
	pinMode(motorB, OUTPUT);
	pinMode(pinB1, OUTPUT);
	pinMode(pinB2, OUTPUT);
}



void L298::forward(int speed)
{
	digitalWrite(_pinB2, HIGH);
	digitalWrite(_pinB1, LOW);

	digitalWrite(_pinA2, HIGH);
	digitalWrite(_pinA1, LOW);
	
	_setSpeedMotorA(speed);
	_setSpeedMotorB(speed);

}



void L298::backward(int speed)
{
	digitalWrite(_pinB2, LOW);
	digitalWrite(_pinB1, HIGH);

	digitalWrite(_pinA2, LOW);
	digitalWrite(_pinA1, HIGH);
	
	_setSpeedMotorA(speed);
	_setSpeedMotorB(speed);
}



void L298::turnRight(int speed)
{
	digitalWrite(_pinB2, HIGH);
	digitalWrite(_pinB1, LOW);

	digitalWrite(_pinA2, LOW);
	digitalWrite(_pinA1, HIGH);
	
	_setSpeedMotorA(speed);
	_setSpeedMotorB(speed);
}



void L298::turnLeft(int speed)
{
	digitalWrite(_pinB2, LOW);
	digitalWrite(_pinB1, HIGH);

	digitalWrite(_pinA2, HIGH);
	digitalWrite(_pinA1, LOW);
	
	_setSpeedMotorA(speed);
	_setSpeedMotorB(speed);
}



void L298::stop()
{
	digitalWrite(_pinA1, LOW);
	digitalWrite(_pinA2, LOW);
	digitalWrite(_pinB1, LOW);
	digitalWrite(_pinB2, LOW);

	_setSpeedMotorA(0);
	_setSpeedMotorB(0);
}

void L298::test(int speed)
{
  digitalWrite(_pinB2, HIGH);
  digitalWrite(_pinB1, LOW);

  digitalWrite(_pinA2, HIGH);
  digitalWrite(_pinA1, LOW);
  
  _setSpeedMotorA(speed);
  _setSpeedMotorB(speed*0.925);
  }
/*
  Left is MotorA
  Right is MotorB
*/
/*
	PRIVATE
*/
void L298::_setSpeedMotorA(int speed)
{
	analogWrite(_motorA, speed);
}


void L298::_setSpeedMotorB(int speed)
{
	analogWrite(_motorB, speed);
}


