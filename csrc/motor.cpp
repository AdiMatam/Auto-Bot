#include "motor.hpp"


Motor::Motor(Pin enable, Pin pin1, Pin pin2) 
    : mEnable(enable), mPin1(pin1), mPin2(pin2) {
    pinMode(mEnable, OUTPUT);
    pinMode(mPin1, OUTPUT);
    pinMode(mPin2, OUTPUT);

    mSpeed = 75;
    assert(softPwmCreate(mEnable, mSpeed, 100) == 0);
}

int Motor::getSpeed() const {
    return mSpeed;
}
void Motor::setSpeed(int speed) {
    mSpeed = speed;
}

void Motor::drive() const {
    softPwmWrite(mEnable, mSpeed);
    digitalWrite(mPin1, HIGH);
    digitalWrite(mPin2, LOW);
}

void Motor::stop(bool full) const {
    softPwmWrite(mEnable, 0);
    softPwmStop(mEnable);
    if (full) {
        digitalWrite(mPin1, LOW);
        digitalWrite(mPin2, LOW);
    }
}
