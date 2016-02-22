#ifndef INCLUDED_L298_H
#define INCLUDED_L298_H

#include <Arduino.h>

class L298
{
    public:
        L298(int motor, int pinA1, int pinA2, int motorB, int pinB1, int pinB2);      

        void forward(int speed);
        void backward(int speed);
        void turnLeft(int speed);
        void turnRight(int speed);
        void test(int speed);
        void stop();

        //void break();
    private:
        int _speed;
        int _motorA, _pinA1, _pinA2;
        int _motorB, _pinB1, _pinB2;

        void _setSpeedMotorA(int speed);
        void _setSpeedMotorB(int speed);        
};

        
#endif
