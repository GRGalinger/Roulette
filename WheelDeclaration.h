#pragma once

class Wheel {
	protected:
		int wheelRange;  //Where the possible values on the wheel are 1 to wheelRange, inclusive
	
	public:
		//Constructors
		Wheel();
		Wheel(int range);

		//Getter and Setter
		int getRange();
		void setRange(int range);

		//For use in Regular mode
		int spin();

};