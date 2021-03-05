#include "Pch.h"
#include "Helpers.h"
#include "Robot.h"

int main() {
    wiringPiSetup();

    Motor left(P11, P13, P15);
    // Motor right();
    // Robot robot(&left, &right);

    left.drive(true, 80);
    delay(1000);
    left.stop();
}