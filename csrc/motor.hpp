#ifndef MOTOR_H
#define MOTOR_H

// #include "pch.hpp"
// #include "helpers.hpp"

#include "helpers.hpp"
#include <iostream>
#include <wiringPi.h>

class Motor {
private:
    Pin mEnable, mPin1, mPin2;
public:
    Motor() = default;
    Motor(Pin enable, Pin pin1, Pin pin2);
    ~Motor();

    void swap();
    void drive(bool dir, int speed) const;
    void stop() const;
};

Motor::Motor(Pin enable, Pin pin1, Pin pin2) 
    : mEnable(enable), mPin1(pin1), mPin2(pin2) {
    pinMode(mEnable, OUTPUT);
    pinMode(mPin1, OUTPUT);
    pinMode(mPin2, OUTPUT);

    // softPwmCreate(mEnable, 0, 100);
}

Motor::~Motor() {
    // softPwmWrite(mEnable, 0);
    // softPwmStop(mEnable);
    digitalWrite(mPin1, LOW);
    digitalWrite(mPin2, LOW);
}

void Motor::swap() {
    Pin temp = mPin1;
    mPin1 = mPin2;
    mPin2 = temp;
}

void Motor::drive(bool dir, int speed) const {
    // softPwmWrite(mEnable, speed);
    digitalWrite(mPin1, dir);
    digitalWrite(mPin2, dir ^ 1);
}

void Motor::stop() const {
    drive(0, 0);
}

#endif


// int getSpeed() const;
// void setSpeed(int speed);

// int Motor::getSpeed() const {
//     return mSpeed;
// }
// void Motor::setSpeed(int speed) {
//     mSpeed = speed;
// }


// void Motor::drive() const {
//     drive(*mSpeed);
// }