// 2020-4-28
// user.cpp

#include "user.h"
#include "body.h"
#include "moon.h"

User::User() {
} // end constructor


void User::setUserAxis(float newAxis) {
	User::userAxis = newAxis;
}
float User::getUserAxis() {
	return User::userAxis;
}


void User::setCurrentMu(float newMu) {
	User::currentMu = newMu;
}
float User::getCurrentMu() {
	return User::currentMu;
}


void User::setCurrentBody(std::string newCurrent) {
	User::currentBody = newCurrent;
}
std::string User::getCurrentBody() {
	return User::currentBody;
}



void User::setTargetBody(std::string newTarget) {
	User::targetBody = newTarget;
}
std::string User::getTargetBody() {
	return User::targetBody;
}


void User::setTargetAxis(float newTargetAxis) {
	User::targetAxis = newTargetAxis;
}
float User::getTargetAxis() {
	return User::targetAxis;
}

void User::setTargetSOI(float newTargetSOI) {
	User::targetSOI = newTargetSOI;
}
float User::getTargetSOI() {
	return User::targetSOI;
}

void User::setTargetVel(float newTargetVel) {
	User::targetVel = newTargetVel;
}
float User::getTargetVel() {
	return User::targetVel;
}


void User::setTransferAxis(float newTransferAxis) {
	User::transferAxis = newTransferAxis;
}
float User::getTransferAxis() {
	return User::transferAxis;
}


void User::setTargetPeriod(float newTarPeriod) {
	User::targetPeriod = newTarPeriod;
}
float User::getTargetPeriod() {
	return User::targetPeriod;
}



void User::setTransferPeriod(float newTranPeriod) {
	User::transferPeriod = newTranPeriod;
}
float User::getTransferPeriod() {
	return User::transferPeriod;
}



void User::setPhaseAngle(float newPhase) {
	User::phaseAngle = newPhase;
}
float User::getPhaseAngle() {
	return User::phaseAngle;
}


void User::setTransferAngle(float newAngle) {
	User::transferAngle = newAngle;
}
float User::getTransferAngle() {
	return User::transferAngle;
}
