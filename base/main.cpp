// Alex Waclawik
// May 11th 2021
// Orbital Transfer Calculator

// c++ libraries
#include <iostream>
#include <fstream>
#include <cmath>

// include body class
#include "body.h"

// initialize object
Body b;

// global variables
long MU = 117233280;
std::string current;
int orbit;
std::string target;
int v1;
int v2;
int phaseAngle;

// function prototypes
void planetMenu();
void calculate();

int main() {

	// program title and splash screen
	std::cout << "-------------------------" << std::endl;
	std::cout << "KSP Orbital Transfer Tool" << std::endl;
	std::cout << "-------------------------" << std::endl;
	
	bool keepGoing = true;
	while (keepGoing) {

		std::string userInput;
		std::cout << " " << std::endl;
		std::cout << "1) Calculate Orbit" << std::endl;
		std::cout << "2) Quit" << std::endl;
		std::cin >> userInput;
	
		// calculate orbit
		if (userInput == "1") {
	
			// get current planet
			std::cout << "What planet are you currently orbiting?" << std::endl;
			std::string currentInput;
			planetMenu();
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
			planetMenu();
			std::cin >> targetInput;
			target = targetInput;

			calculate();

			// outputs the orbital values needed to make a successful transfer
			std::cout << "------------" << std::endl;
			std::cout << "Trajectories" << std::endl;
			std::cout << "------------" << std::endl;
			std::cout << "Ejection Burn (v1): " << v1 << " m/s" << std::endl;
			std::cout << "Insertion Burn (v2): " << v2 << " m/s" << std::endl;
			std::cout << "Phase Angle: " << phaseAngle << " Degrees" << std::endl;
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
	v1 = std::abs (orbit - currentVel);

	// calculate v2
	float currentAxis = b.getAxis(current);
	float targetAxis = b.getAxis(target);
	int v2p1 = (MU / targetAxis);
	long v2p2 = (sqrt(v2p1));
	
	// part two
	float v2p3 = 2 * currentAxis;
	float v2p4 = currentAxis + targetAxis;
	float v2p5 = v2p3 / v2p4;
	float v2p6 = sqrt(v2p5);
	
	// part three
	v2 = v2p2 * (1 - v2p6);

	// calculate transfer period
	float transferAxis = v2p4 / 2;
	//std::cout << "Transfer Axis: " << transferAxis << std::endl;
	float trp1 = (pow(transferAxis, 3) / MU);
	float trp2 = sqrt(trp1);
	float transferPeriod = (2 * 3.14) * trp2;
	//std::cout << "Transfer Period: " << transferPeriod << std::endl;


	// calculate angular velocity of target
	float angv1 = pow(targetAxis, 3);
	//std::cout << "angv1: " << angv1 << std::endl;
	float angv2 = sqrt(MU / angv1);
	//std::cout << "angv2: " << angv2 << std::endl;
	float angv3 = sqrt(angv2);
	//std::cout << "angv3: " << angv3 << std::endl;
	float angv4 = (360 / (2 * 3.14));
	//std::cout << "angv4: " << angv4 << std::endl;
	float targetVel = angv4 * angv3;
	//std::cout << "Target Vel: " << targetVel << std::endl;

	// calculate phaseAngle
	phaseAngle = 180 - (0.5 * transferPeriod * targetVel);
}
