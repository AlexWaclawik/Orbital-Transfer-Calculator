// Alex Waclawik
// May 11th 2021
// Orbital Transfer Calculator

// c++ libraries
#include <iostream>
#include <fstream>
#include <cmath>

// global variables
#define MU 1172332800000000000
int current;
int target;

// function prototypes
void bodyMenu();
void calPeriod();
void calPhaseAngle();
void calTransferAngle();


int main() {

	// initialize class pointers
	body b;

	// program title and splash screen
	std::cout << "-------------------------" << std::endl;
	std::cout << "KSP Orbital Transfer Tool" << std::endl;
	std::cout << "-------------------------" << std::endl;
	
	bool keepGoing = true;
	while (keepGoing) {

		std::cout << " " << std::endl;
		std::cout << "0) Calculate Orbit" << std::endl;
		std::cout << "1) Help" << std::endl;
		std::cout << "2) Quit" << std::endl;
		std::cin >> userInput;
	
		// calculate orbit
		if (userInput == "0") {
	
			// get current planet
			std::cout << "What planet are you currently orbiting?" << std::endl;
			std::string currentInput;
			bodyMenu();
			std::cin >> currentInput;
			
			// gets user's current altitude
			std::string orbitInput;
			std::cout << "Current Orbiting Altitude (in meters):" << std::endl;
			std::cin >> orbitInput;
			// checks if input is a valid integer
			// source for this portion: "https://stackoverflow.com/a/18728791"
			while (std::cin.fail()) {
				std::cout << "Invalid Input" << std::endl;
				std::cin.ignore(256, '\n');
				std::cin >> orbitInput;
			}

			// get target planet
			std::cout << "What planet would you like to transfer to?" << std::endl;
			std::string targetInput;
			bodyMenu();
			std::cin >> targetInput;
			// checks if input is a valid integer
			// source for this portion: "https://stackoverflow.com/a/18728791"
			while (std::cin.fail()) {
				std::cout << "Invalid Input" << std::endl;
				std::cin.ignore(256, '\n');
				std::cin >> targetInput;
			}

			// outputs the orbital values needed to make a successful transfer
			std::cout << "------------" << std::endl;
			std::cout << "current" << " --> " << "target" << std::endl;
			std::cout << "------------" << std::endl;
			std::cout << "Ejection Burn (v1): " << "ejectburn" << std::endl;
			std::cout << "Insertion Burn (v2): " << "insertburn" << std::endl;
			std::cout << "Phase Angle: " << "phaseangle" << std::endl;
		}

		// credits
		else if (userInput == "1") {
			std::cout << "Written by Alex Waclawik" << std::endl;
		}
		
		// quit
		else if (userInput == "2") {
			std::cout << "Goodbye!" << std::endl;
			keepGoing = false;
		}

		// catches input errors
		else {
			std::cout << "Invalid Input" << std::endl;	
		}	
	}
	return 0;
} // end main


void planetMenu() {
	std::cout << "Choose Planet:" << std::endl;
	std::cout << "0) Moho" << std::endl;
	std::cout << "1) Eve" << std::endl; 
	std::cout << "2) Kerbin" << std::endl; 
	std::cout << "3) Duna" << std::endl; 
	std::cout << "4) Dres" << std::endl; 
	std::cout << "5) Jool" << std::endl; 
	std::cout << "6) Eeloo" << std::endl;
}


// calculates Target's Orbital Period, Transfer Orbit's Period, and Semi-Major Axis of Trabsfer Orbit using values:
// 	*Semi-Major Axis of Target
// 	*Semi-Major Axis of Current Orbit
// 	*Standard Gravitational Parameter of Origin Object
void calPeriod() {
	float tempTargetAxis = u.getTargetAxis();
	float tempCurrentAxis = u.getUserAxis();
	float tempMu = u.getCurrentMu();
	float tempTargetPeriod = 6.28 * sqrt(pow(tempTargetAxis, 3) / tempMu);
	u.setTargetPeriod(tempTargetPeriod);
	float tempTransferPeriod = 6.28 * sqrt(pow(((tempTargetAxis + tempCurrentAxis) / 2), 3) / tempMu);
	u.setTransferPeriod(tempTransferPeriod);
	float tempTransferAxis = (tempCurrentAxis + tempTargetAxis) / 2;
	u.setTransferAxis(tempTransferAxis);
} // end function


// calculates Ejection Phase Angle using values:
// 	*Semi-Major Axis of Target Object
// 	*Semi-Major Axis of Transfer Orbit
void phaseAngle() {
	float tempTargetAxis = u.getTargetAxis();
	float tempTransferAxis = u.getTransferAxis();
	float tempPhaseAngle = 1 / (2 * sqrt((pow(tempTargetAxis, 3) / pow(tempTransferAxis, 3)));
	u.setPhaseAngle(tempPhaseAngle);
} // end function


// calculates Transfer Orbit Angle using values:
// 	*Orbital Period of Target Object
// 	*Orbital Period of Transfer Orbit
void transferAngle() {
	float tempTargetPeriod = u.getTargetPeriod()
	float tempTransferPeriod = u.getTransferPeriod()
	float tempTransferAngle = 360 * (0.5 - (tempTransferPeriod / (2 * tempTargetPeriod)));
	u.setTransferAngle(tempTransferAngle);
} // end function
