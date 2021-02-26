// #include "pch.hpp"
#include <iostream>
#include <wiringPi.h>

#include "helpers.hpp"
#include "motor.hpp"


int main() {   
    wiringPiSetup();

    Motor left(P11, P13, P15);
    Motor right(P18, P12, P16);
    // Robot robot(&left, &right);

}
