#pragma once
#include "WheelDeclaration.h"

class Player:public Wheel {
	private:
		double bankTotal;
		int consecWins;

	public:
		//Constructors
		Player();
		Player(double money, int val);

		//Getter and Setter
		double getBank();
		void setBank(double money);

		//Overloaded spin function for Hard mode
		//Learned from https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/overload_member_fn_base_derived.htm
		using Wheel::spin; 
		int spin(int resultValue, int playerRange);
};