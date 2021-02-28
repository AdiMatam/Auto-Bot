#ifndef MOTOR_H
#define MOTOR_H

#include "pch.hpp"
#include "helpers.hpp"
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
#endif