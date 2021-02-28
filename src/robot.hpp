#ifndef ROBOT_H
#define ROBOT_H

#include "pch.hpp"
#include "helpers.hpp"
#include "motor.hpp"

class Robot {
private:
    Motor* mLhs;
    Motor* mRhs;
public:
    Robot() = default;
    Robot(Motor* lhs, Motor* rhs);
    ~Robot() = default;

    void drive(bool dir, int speed, int duration, bool seconds=false) const;
    void forward(int speed, int duration, bool seconds=false) const;
    void reverse(int speed, int duration, bool seconds=false) const;
};
#endif