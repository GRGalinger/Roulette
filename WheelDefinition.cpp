#include "WheelDeclaration.h"
#include <cstdlib>
#include <ctime>

//Constructors
Wheel::Wheel() {
	wheelRange = 10;
	srand(time(NULL));
}

Wheel::Wheel(int range) {
	wheelRange = range;
	srand(time(NULL));
}

//Getter and Setter
int Wheel::getRange() {
	return wheelRange;
}
void Wheel::setRange(int range) {
	wheelRange = range;
}

//Returns random value indicating where ball landed on wheel
int Wheel::spin() {
	return (rand() % wheelRange) + 1;
}