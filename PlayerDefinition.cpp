#include "PlayerDeclaration.h"
#include <cstdlib>

//Default Constructor
Player::Player() {
	bankTotal = 100.00;
	consecWins = 0;
}

//Overloaded Constructor
Player::Player(double money, int val):Wheel(val) {
	bankTotal = money;
	consecWins = 0;
}

//Getter and Setter
double Player::getBank() {
	return bankTotal;
}

void Player::setBank(double money) {
	bankTotal = money;
}

//Overloaded Spin function for use in hard mode
int Player::spin(int resultValue, int playerRange) {
	int spinVal = (rand() % wheelRange) + 1;  //Spins the house's wheel
	if (resultValue > spinVal) {
		//House loses so wheel range increases
		wheelRange += 1;
		consecWins = 0;
	}
	else {
		//House wins (resultVal <= spinVal)
		consecWins += 1;
		if (consecWins % 2 == 0) {
			//Every time house wins two in a row, wheel range decreases
			if (wheelRange > playerRange) {
				wheelRange -= 1;
			}
		}
	}
	return spinVal;
}