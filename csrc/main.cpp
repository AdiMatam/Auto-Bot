#include "pch.hpp"
#include "helpers.hpp"
#include "robot.hpp"

void testRun(Motor* left, int speed) {
    left->setSpeed(speed);
    left->drive();
    delay(250);
}

int main() {   
    wiringPiSetup();

    Motor left(P11, P13, P15);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 100; j += 5) testRun(&left, j);
        for (int j = 100; j > 0; j -= 5) testRun(&left, j);
    }
    left.stop();
}
