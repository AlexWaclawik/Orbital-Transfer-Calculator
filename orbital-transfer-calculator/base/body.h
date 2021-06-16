#include <iostream>

class Body {
	public:
		Body();
		// 0
		float mohoAxis;
		int mohoVel;
		// 1
		float eveAxis;
		int eveVel;
		// 2
		float kerbinAxis;
		int kerbinVel;
		// 3
		float dunaAxis;
		int dunaVel;
		// 4
		float dresAxis;
		int dresVel;
		// 5
		float joolAxis;
		int joolVel;
		// 6
		float eelooAxis;
		int eelooVel;
	public:
		float getAxis(std::string x);
		int getVel(std::string x);
};

