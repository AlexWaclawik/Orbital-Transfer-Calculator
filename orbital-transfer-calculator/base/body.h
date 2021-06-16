#include <iostream>

class Body {
	public:
		Body();
		// 0
		long mohoAxis;
		long mohoVel;
		// 1
		long eveAxis;
		long eveVel;
		// 2
		float kerbinAxis;
		int kerbinVel;
		// 3
		float dunaAxis;
		int dunaVel;
		// 4
		long dresAxis;
		long dresVel;
		// 5
		long joolAxis;
		long joolVel;
		// 6
		long eelooAxis;
		long eelooVel;
	public:
		float getAxis(std::string x);
		int getVel(std::string x);
};

