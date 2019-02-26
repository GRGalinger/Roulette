#include "PlayerDeclaration.h"
#include <iostream>	
using namespace std;

int main() {
	bool again = true;
	int range;
	int ans;
	int ballPlayer, ballHouse;
	double moneyStart, bet, betInc;
	
	cout << "Would you like to play this roulette game in Regular mode or Hard mode? (0 for Regular, 1 for Hard)" << endl;
	cin >> ans;

	//Checks to make sure answer is valid
	while (ans != 0 && ans != 1) {
		cout << "Invalid choice! Please re-enter selection." << endl;
		cin >> ans;
	}

	cout << "How many values would you like on the wheel (minimum 6, maximum 20)?" << endl;
	cin >> range;

	//Checks to make sure range is on [6,20]
	while (range < 6 || range > 20) {
		cout << "Invalid range! Range must be between 6 and 20, inclusive. Please re-enter." << endl;
		cin >> range;
	}

	cout << "How much money do you want to play with?" << endl;
	cin >> moneyStart;

	//Checks to ensure bank balance is valid
	while (moneyStart < 1) {
		cout << "Invalid! Please enter value of at least $1." << endl;
		cin >> moneyStart;
	}
	
	Player player1(moneyStart, range);
	Player house;
	house.setRange(range);

	//If statement for entering into hard mode based on response to question above
	if (ans) {
		//HARD MODE
		while (player1.getBank() > 0 && again) {
			//Loops until player runs out of money or he/she cashes out
			cout << "Your wheel has values 1 to " << player1.getRange() << endl;
			cout << "The house's wheel has values 1 to " << house.getRange() << endl;
			
			cout << "How much money would you like bet that your ball will land on a higher space than the house's?" << endl;
			cout << "(Your bank balance is $" << player1.getBank() << ")" << endl;
			cin >> bet;

			//Checks to ensure bet is valid
			while (bet < 0 || bet > player1.getBank()) {
				cout << "Invalid bet! Please re-enter valid amount." << endl;
				cin >> bet;
			}

			cout << "Spinning wheel..." << endl;

			//Sets values for each of the balls
			ballPlayer = player1.spin();
			ballHouse = house.spin(ballPlayer, player1.getRange());

			cout << "Your ball landed on " << ballPlayer << "!" << endl;

			cout << "Would you like to increase your wager up to 2x, betting on the fact the house's ball will land on a lower space?" << endl;
			cout << "(1 for yes, 0 for no)" << endl;
			cin >> ans;

			if (ans == 1) {		
				//Player wants to increase wager
				if (2 * bet > player1.getBank()) {		
					//Maximum bet is only however much money they have left
					cout << "By how much would you like to increase your wager?" << endl;
					cout << "(maximum of $" << player1.getBank() - bet << ")" << endl;
					cin >> betInc;

					//Checks to make sure extra bet is valid amount
					while (betInc < 0 || betInc > player1.getBank() - bet) {
						cout << "Invalid wager! Please enter wager again (maximum of $" << player1.getBank() - bet << ")" << endl;
						cin >> betInc;
					}
				}
				else {	
					//Maximum bet is double their original bet, per the instructions
					cout << "By how much would you like to increase your wager?" << endl;
					cout << "(maximum of $" << bet << ")" << endl;
					cin >> betInc;

					//Checks to make sure extra bet is valid amount
					while (betInc < 0 || betInc > bet) {
						cout << "Invalid wager! Please enter wager again (maximum of $" << bet << ")" << endl;
						cin >> betInc;
					}
				}
			}
			else {
				//Player chooses not to increase bet
				betInc = 0;
			}

			//Adds the increased bet to the original
			bet += betInc; 

			cout << "Spinning house's ball..." << endl;
			cout << "Ball landed on a " << ballHouse << "!" << endl;

			if (ballPlayer > ballHouse) {
				//Player wins!
				player1.setBank(player1.getBank() + bet);

				cout << "Congratulations! You won! Your balance is now $" << player1.getBank() << "!" << endl;
			}
			else {
				//Player loses :(
				player1.setBank(player1.getBank() - bet);

				cout << "Sorry, you lost. Better luck next time. Your balance is now $" << player1.getBank() << endl;
			}

			if (player1.getBank() == 0) {
				//Player runs out of money
				cout << "You are out of cash! You lost $" << moneyStart << ". Thanks for playing!" << endl;
				again = false;
			}
			else {
				//Player has money left
				cout << "Would you like to continue playing or cash out?" << endl;
				cout << "(1 to continue, 0 to cash out)" << endl;
				cin >> ans;

				//Ensures answer is valid
				while (ans != 0 && ans != 1) {
					cout << "Invalid entry! Please re-enter choice." << endl;
					cin >> ans;
				}

				if (ans == 0) {
					//Player cashes out
					cout << "Thanks for playing! You left with $" << player1.getBank() << ", for a total winnings of " << player1.getBank() - moneyStart << " dollars." << endl;
					again = false;
				}
				else {
					//Player keeps playing
					again = true;
				}
			}
		}
	}
	else {
		//REGULAR MODE
		while (player1.getBank() > 0 && again) {
			//Loops until player runs out of money or he/she cashes out
			cout << "How much money would you like bet that your ball will land on a higher space than the house's?" << endl;
			cout << "(Your bank balance is $" << player1.getBank() << ")" << endl;
			cin >> bet;

			//Checks to ensure bet is valid
			while (bet < 0 || bet > player1.getBank()) {
				cout << "Invalid bet! Please re-enter valid amount." << endl;
				cin >> bet;
			}

			cout << "Spinning wheel..." << endl;

			//Sets values for each of the balls
			ballPlayer = player1.spin();
			ballHouse = house.spin();

			cout << "Your ball landed on " << ballPlayer << "!" << endl;

			cout << "Would you like to increase your wager up to 2x, betting on the fact the house's ball will land on a lower space?" << endl;
			cout << "(1 for yes, 0 for no)" << endl;
			cin >> ans;

			if (ans == 1) {
				//Player wants to increase wager
				if (2 * bet > player1.getBank()) {
					//Maximum bet is only however much money player has left
					cout << "By how much would you like to increase your wager?" << endl;
					cout << "(maximum of $" << player1.getBank() - bet << ")" << endl;
					cin >> betInc;

					//Checks to make sure extra bet is valid amount
					while (betInc < 0 || betInc > player1.getBank() - bet) {
						cout << "Invalid wager! Please enter wager again (maximum of $" << player1.getBank() - bet << ")" << endl;
						cin >> betInc;
					}
				}
				else {
					//Maximum bet is double their original bet, per the instructions
					cout << "By how much would you like to increase your wager?" << endl;
					cout << "(maximum of $" << bet << ")" << endl;
					cin >> betInc;

					//Checks to make sure extra bet is valid amount
					while (betInc < 0 || betInc > bet) {
						cout << "Invalid wager! Please enter wager again (maximum of $" << bet << ")" << endl;
						cin >> betInc;
					}
				}
			}
			else {
				//User chooses not to increase bet
				betInc = 0;
			}

			//Adds the increased bet to the original
			bet += betInc;

			cout << "Spinning house's ball..." << endl;
			cout << "Ball landed on a " << ballHouse << "!" << endl;

			if (ballPlayer > ballHouse) {
				//Player wins!
				player1.setBank(player1.getBank() + bet);

				cout << "Congratulations! You won! Your balance is now $" << player1.getBank() << "!" << endl;
			}
			else {
				//Player loses :(
				player1.setBank(player1.getBank() - bet);

				cout << "Sorry, you lost. Better luck next time. Your balance is now $" << player1.getBank() << endl;
			}

			if (player1.getBank() == 0) {
				//Player runs out of money
				cout << "You are out of cash! You lost $" << moneyStart << ". Thanks for playing!" << endl;
				again = false;
			}
			else {
				//Player has money left
				cout << "Would you like to continue playing or cash out?" << endl;
				cout << "(1 to continue, 0 to cash out)" << endl;
				cin >> ans;

				//Ensure answer is valid
				while (ans != 0 && ans != 1) {
					cout << "Invalid entry! Please re-enter choice." << endl;
					cin >> ans;
				}

				if (ans == 0) {
					//Player cashes out
					cout << "Thanks for playing! You left with $" << player1.getBank() << ", for a total winnings of " << player1.getBank() - moneyStart << " dollars." << endl;
					again = false;
				}
				else {
					//Player keeps playing
					again = true;
				}
			}
		}
	}
	return 0;
}