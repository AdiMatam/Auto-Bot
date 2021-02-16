#include "robot.hpp"

Robot::Robot(Motor& lhs, Motor& rhs) {
    mLhs = &lhs;
    mRhs = &rhs;
}