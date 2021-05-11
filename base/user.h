// 2020-4-28 
// user.h

#ifndef USER_H_EXISTS
#define USER_H_EXISTS

#include <iostream>

class User {
	private:
		float userAxis;
		float currentMu;
		std::string currentBody;
		std::string targetBody;

		float targetAxis;
		float targetSOI;
		float targetVel;
		
		float transferAxis;
		float targetPeriod;
		float transferPeriod;
		float phaseAngle;
		float transferAngle;

	public:

		User();

		void setUserAxis(float newAxis);
		float getUserAxis();

		void setCurrentMu(float newMu);
		float getCurrentMu();

		void setCurrentBody(std::string newCurrent);
		std::string getCurrentBody();

		void setTargetBody(std::string newTarget);
		std::string getTargetBody();
		
		void setTargetAxis(float newTargetAxis);
		float getTargetAxis();

		void setTargetSOI(float newTargetAxis);
		float getTargetSOI();

		void setTargetVel(float newTargetVel);
		float getTargetVel();

		void setTransferAxis(float newTransferAxis);
		float getTransferAxis();

		void setTargetPeriod(float newTarPeriod);
		float getTargetPeriod();
		
		void setTransferPeriod(float newTranPeriod);
		float getTransferPeriod();

		void setPhaseAngle(float newPhase);
		float getPhaseAngle();

		void setTransferAngle(float newAngle);
		float getTransferAngle();
};
