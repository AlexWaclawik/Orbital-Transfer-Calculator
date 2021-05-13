// Alex Waclawik
// May 11th 2021
// Orbital Transfer Calculator

// c++ libraries
#include <iostream>
#include <fstream>
#include <cmath>

// include body class
#include "body.h"

// global variables
#define MU 1172332800000000000
int current;
int orbit;
int target;
int v1;
int v2;
int phaseAngle;

// function prototypes
void bodyMenu();
void calculate();

int main() {

	// initialize class pointers
	Body b;

	// program title and splash screen
	std::cout << "-------------------------" << std::endl;
	std::cout << "KSP Orbital Transfer Tool" << std::endl;
	std::cout << "-------------------------" << std::endl;
	
	bool keepGoing = true;
	while (keepGoing) {

		std::cout << " " << std::endl;
		std::cout << "1) Calculate Orbit" << std::endl;
		std::cout << "2) Quit" << std::endl;
		std::cin >> userInput;
	
		// calculate orbit
		if (userInput == "1") {
	
			// get current planet
			std::cout << "What planet are you currently orbiting?" << std::endl;
			std::string currentInput;
			bodyMenu();
			std::cin >> currentInput;
			current = currentInput;
			// gets user's current altitude
			int orbitInput;
			std::cout << "Current Velocity (in m/s):" << std::endl;
			std::cin >> orbitInput;
			orbit = orbitInput;

			// get target planet
			std::cout << "What planet would you like to transfer to?" << std::endl;
			std::string targetInput;
			bodyMenu();
			std::cin >> targetInput;
			target = targetInput;

			calculate();

			// outputs the orbital values needed to make a successful transfer
			std::cout << "------------" << std::endl;
			std::cout << "Trajectories" << std::endl;
			std::cout << "------------" << std::endl;
			std::cout << "Ejection Burn (v1): " << v1 << std::endl;
			std::cout << "Insertion Burn (v2): " << v2 << std::endl;
			std::cout << "Phase Angle: " << phaseAngle << std::endl;
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


void calculate() {
	
	// calculate v1
	int currentVel = b.getVel(current);
	v1 = currentVel - orbit;
	
	// calculate v2
	int currentAxis = b.getAxis(current);
	int targetAxis = b.getAxis(target);
	// part one
	int v2p1 = sqrt((MU / targetAxis));
	// part two
	int v2p2 = 1 - sqrt(((2 * currentAxis) / (currentAxis + targetAxis)));
	// part three
	v2 = v2p1 * v2p2;

	// calculate transfer period
	int transferAxis = (currentAxis + targetAxis) / 2;
	int transferPeriod = (2 * 3.14) * sqrt((pow(transferAxis, 3) / MU));

	// calculate angular velocity of target
	int targetVel = (360 / (2 * 3.14)) * sqrt((MU / pow(targetAxis, 3)));

	// calculate phaseAngle
	phaseAngle = 180 - 0.5 * transferPeriod * targetVel;
}
