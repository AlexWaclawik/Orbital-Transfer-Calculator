// 2020-4-28
// body.cpp

#include "body.h"

Body::Body() {

	Body::MohoMu = 168609380000.00;
	Body::MohoAxis = 5263138304.00;
	Body::MohoSOI = 9646663.00;
	Body::MohoVel = 1161.41;

	Body::EveMu = 8171730200000.00;
	Body::EveAxis = 9832684544.00;
	Body::EveSOI = 85109365.00;
	Body::EveVel = 4831.96;

	Body::KerbinMu = 3531600000000.00;
	Body::KerbinAxis = 13599840256.00;
	Body::KerbinSOI = 84159286.00;
	Body::KerbinVel = 3431.03;

	Body::DunaMu = 301363210000.00;
	Body::DunaAxis = 20726155264.00;
	Body::DunaSOI = 47921949.00;
	Body::DunaVel = 1372.41;

	Body::DresMu = 21484489000.00;
	Body::DresAxis = 40839348203.00;
	Body::DresSOI = 47921949.00;
	Body::DresVel = 1372.41;

	Body::JoolMu = 282528000000000.00;
	Body::JoolAxis = 68773560320.00;
	Body::JoolSOI = 2455985200.00;
	Body::JoolVel = 9704.43;

	Body::EelooMu = 74410815000.00;
	Body::EelooAxis = 90118820000.00;
	Body::EelooSOI = 119082940.00;
	Body::EelooVel = 841.83;

} // end constructor

static float Body::getMohoMu() {
	return Body::MohoMu;
} 
static float Body::getMohoAxis() {
	return Body::MohoAxis
}
static float Body::getMohoSOI() {
	return Body::MohoSOI;
}
static float Body::getMohoVel() {
	return Body::MohoVel;
}


static float Body::getEveMu() {
	return Body::EveMu;
}
static float Body::getEveAxis() {
	return Body::EveAxis;
}
static float Body::getEveSOI() {
	return Body::EveSOI;
}
static float Body::getEveVel() {
	return Body::EveVel;
}


static float Body::getKerbinMu() {
	return Body::KerbinMu;
}
static float Body::getKerbinAxis() {
	return Body::KerbinAxis;
}
static float Body::getKerbinSOI() {
	return Body::KerbinSOI;
}
static float Body::getKerbinVel() {
	return Body::KerbinVel;
}

static float Body::getDunaMu() {
	return Body::DunaMu;
}
static float Body::getDunaAxis() {
	return Body::DunaAxis;
}
static float Body::getDunaSOI() {
	return Body::DunaSOI;
}
static float Body::getDunaVel() {
	return Body::DunaVel;
}


static float Body::getDresMu() {
	return Body::DresMu;
}
static float Body::getDresAxis() {
	return Body::DresAxis;
}
static float Body::getDresSOI() {
	return Body::DresSOI;
}
static float Body::getDresVel() {
	return Body::DresVel;
}


static float Body::getJoolMu() {
	return Body::JoolMu;
}
static float Body::getJoolAxis() {
	return Body::JoolAxis;
}
static float Body::getJoolSOI() {
	return Body::JoolSOI;
}
static float Body::getJoolVel() {
	return Body::JoolVel;
}


static float Body::getEelooMu() {
	return Body::EelooMu;
}
static float Body::getEelooAxis() {
	return Body::EelooAxis;
}
static float Body::getEelooSOI() {
	return Body::EelooSOI;
}
static float Body::getEelooVel() {
	return Body::EelooVel;
}
