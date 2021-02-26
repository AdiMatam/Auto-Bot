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

Robot::Robot(Motor* lhs, Motor* rhs) {
    mLhs = lhs; 
    mRhs = rhs;
}

void Robot::drive(bool dir, int speed, int duration, bool seconds) const {
    if (seconds) duration *= 1000;
    mLhs->drive(dir, speed);
    mRhs->drive(dir, speed);
    delay(duration);
    mLhs->stop();
    mRhs->stop();   
}

void Robot::forward(int speed, int duration, bool seconds) const {
    drive(true, speed, duration, seconds);
}

void Robot::reverse(int speed, int duration, bool seconds) const {
    drive(false, speed, duration, seconds);
}

#endif