// 2020-28-4
// moon.cpp

#include "moon.h"

Moon::Moon() {
	
	Moon::GillyMu = 8289449.80;
	Moon::GillyAxis = 31500000.00;
	Moon::GillySOI = 126123.27;
	Moon::GillyVel = 35.71;

	Moon::MunMu = 65138398000.00;
	Moon::MunAxis = 12000000.00;
	Moon::MunSOI = 2429559.10;
	Moon::MunVel = 807.08;

	Moon::MinmusMu = 1765800000.00;
	Moon::MinmusAxis = 47000000.00;
	Moon::MinmusSOI = 2247428.40;
	Moon::MinmusVel = 242.61;

	Moon::IkeMu = 18568369000.00;
	Moon::IkeAxis = 3200000.00;
	Moon::IkeSOI = 1049598.9;
	Moon::IkeVel = 534.48;

	Moon::LaytheMu = 1962000000000.00;
	Moon::LaytheAxis = 27184000.00;
	Moon::LaytheSOI = 3723645.80;
	Moon::LaytheVel = 2801.43; 

	Moon::VallMu = 207481500000.00;
	Moon::VallAxis = 43152000.00;
	Moon::VallSOI = 2406401.40;
	Moon::VallVel = 1176.10;

	Moon::TyloMu = 2825280000000.00;
	Moon::TyloAxis = 68500000.00;
	Moon::TyloSOI = 10856518.00;
	Moon::TyloVel = 3068.81;

	Moon::BopMu = 2486834900.00;
	Moon::BopAxis = 128500000.00;
	Moon::BopSOI = 1221060.90;
	Moon::BopVel = 267.62;

	Moon::PolMu = 721702080.00;
	Moon::PolAxis = 179890000.00;
	Moon::PolSOI = 1042138.90;
	Moon::PolVel = 181.12;

} // constructor



static float Moon::getGillyMu() {
	return Moon::GillyMu;
}
static float Moon::getGillyAxis() {
	return Moon::GillyAxis;
}
static float Moon::getGillySOI() {
	return Moon::GillySOI;
}
static float Moon::getGillyVel() {
	return Moon::GillyVel;
}



static float Moon::getMunMu() {
	return Moon::MunMu;
}
static float Moon::getMunAxis() {
	return Moon::MunAxis;
}
static float Moon::getMunSOI() {
	return Moon::MunSOI;
}
static float Moon::getMunVel() {
	return Moon::MunVel;
}



static float Moon::getMinmusMu() {
	return Moon::MinmusMu;
}
static float Moon::getMinmusAxis() {
	return Moon::MinmusAxis;
}
static float Moon::getMinmusSOI() {
	return Moon::MinmusSOI;
}
static float Moon::getMinmusVel() {
	return Moon::MinmusVel;
}



static float Moon::getIkeMu() {
	return Moon::IkeMu;
}
static float Moon::getIkeAxis() {
	return Moon::IkeAxis;
}
static float Moon::getIkeSOI() {
	return Moon::IkeSOI;
}
static float Moon::getIkeVel() {
	return Moon::IkeVel;
}



static float Moon::getLaytheMu() {
	return Moon::LaytheMu;
}
static float Moon::getLaytheAxis() {
	return Moon::LaytheAxis;
}
static float Moon::getLaytheSOI() {
	return Moon::LaytheAxis;
}
static float Moon::getLaytheVel() {
	return Moon::LaytheVel;
}



static float Moon::getVallMu() {
	return Moon::VallMu;
}
static float Moon::getVallAxis() {
	return Moon::VallAxis;
}
static float Moon::getVallSOI() {
	return Moon::VallSOI;
}
static float Moon::getVallVel() {
	return Moon::VallVel;
}



static float Moon::getTyloMu() {
	return Moon::TyloMu;
}
static float Moon::getTyloAxis() {
	return Moon::TyloAxis;
}
static float Moon::getTyloSOI() {
	return Moon::TyloSOI;
}
static float Moon::getTyloVel() {
	return Moon::TyloVel;
}



static float Moon::getBopMu() {
	return Moon::BopMu;
}
static float Moon::getBopAxis() {
	return Moon::BopAxis;
}
static float Moon::getBopSOI() {
	return Moon::BopSOI;
}
static float Moon::getBopVel() {
	return Moon::BopVel;
}



static float Moon::getPolMu() {
	return Moon::PolMu;
}
static float Moon::getPolAxis() {
	return Moon::PolAxis;
}
static float Moon::getPolSOI() {
	return Moon::PolSOI;
}
static float Moon::getPolVel() {
	return Moon::PolVel;
}
