#include "body.h"

Body::Body() {
	// 0
	Body::mohoAxis = 5263138304;
	Body::mohoVel = 1161;
	// 1
	Body::eveAxis = 9832684544;
	Body::eveVel = 4831;
	// 2
	Body::kerbinAxis = 13599840256;
	Body::kerbinVel = 3431;
	// 3
	Body::dunaAxis = 20726155264;
	Body::dunaVel = 1372;
	// 4
	Body::dresAxis = 40839348203;
	Body::dresVel = 558;
	// 5
	Body::joolAxis = 68773560320;
	Body::joolVel = 9704;
	// 6
	Body::eelooAxis = 90118820000;
	Body::eelooVel = 841;
}


int Body::getAxis(std::string x) {
	if (x == "0") {
		return mohoAxis;
	}
	else if (x == "1") {
		return eveAxis;
	}
	else if (x == "2") {
		return kerbinAxis;
	}
	else if (x == "3") {
		return dunaAxis;
	}
	else if (x == "4") {
		return dresAxis;
	}
	else if (x == "5") {
		return joolAxis;
	}
	else {
		return eelooAxis;
	}
}


int Body::getVel(std::string x) {
	if (x == "0") {
		return mohoVel;
	}
	else if (x == "1") {
		return eveVel;
	}
	else if (x == "2") {
		return kerbinVel;
	}
	else if (x == "3") {
		return dunaVel;
	}
	else if (x == "4") {
		return dresVel;
	}
	else if (x == "5") {
		return joolVel;
	}
	else {
		return eelooVel;
	}
}
