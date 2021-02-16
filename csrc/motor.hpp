#ifndef MOTOR_H
#define MOTOR_H

#include "pch.hpp"
#include "helpers.hpp"

class Motor {
private:
    Pin mEnable, mPin1, mPin2;
    int mSpeed;
public:
    Motor() = default;
    Motor(Pin enable, Pin pin1, Pin pin2);
    ~Motor() = default;

    int getSpeed() const;
    void setSpeed(int speed);

    void drive() const;
    void stop(bool full=false) const;
};

#endif