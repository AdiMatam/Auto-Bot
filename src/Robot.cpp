#include "Robot.h"

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
