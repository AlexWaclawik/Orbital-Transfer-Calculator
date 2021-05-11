// Alex Waclawik
// May 11th 2021
// Orbital Transfer Calculator

// c++ libraries
#include <iostream>
#include <fstream>
#include <cmath>

// global variables


// data structures
struct body {
	int mohoMu = 168609380000;
	int mohoAxis = 5263138304;
	int mohoSOI = 9646663;
	int mohoVel = 1161;
	int eveMu = 8171730200000;
	int eveAxis = 9832684544;
	int eveSOI = 85109365;
	int eveVel = 4831;
	int kerbinMu = 3531600000000;
	int kerbinAxis = 13599840256;
	int kerbinSOI = 84159286;
	int kerbinVel = 3431;
	int dunaMu = 301363210000;
	int dunaAxis = 20726155264;
	int dunaSOI = 47921949;
	int dunaVel = 1372;
	int dresMu = 21484489000;
	int dresAxis = 40839348203;
	int dresSOI = 47921949;
	int dresVel = 1372;
	int joolMu = 282528000000000;
	int joolAxis = 68773560320;
	int joolSOI = 2455985200;
	int joolVel = 9704;
	int eelooMu = 74410815000;																					
	int eelooAxis = 90118820000;
	int eelooSOI = 119082940;
	int eelooVel = 841;
}

struct moon {
	int gillyMu = 8289449;
	int gillyAxis = 31500000;
	int gillySOI = 126123;
	int gillyVel = 35;
	int munMu = 65138398000;
	int munAxis = 12000000;
	int munSOI = 2429559;
	int munVel = 807;
	int minmusMu = 1765800000;
	int minmusAxis = 47000000;
	int minmusSOI = 2247428;
	int minmusVel = 242;
	int ikeMu = 18568369000;
	int ikeAxis = 3200000;
	int ikeSOI = 1049590;
	int ikeVel = 534;
	int laytheMu = 1962000000000;
	int laytheAxis = 27184000;
	int laytheSOI = 3723645;
	int laytheVel = 2801; 
	int vallMu = 207481500000;
	int vallAxis = 43152000;
	int vallSOI = 2406401;
	int vallVel = 1176;
	int tyloMu = 2825280000000;
	int tyloAxis = 68500000;
	int tyloSOI = 10856518;
	int tyloVel = 3068;
	int bopMu = 2486834900;
	int bopAxis = 128500000;
	int bopSOI = 1221060;
	int bopVel = 267;
	int polMu = 721702080;
	int polAxis = 179890000;
	int polSOI = 1042138;
	int polVel = 181;
}

// function prototypes
void currentMenu();
void targetMenu();
void calPeriod();
void calPhaseAngle();
void calTransferAngle();

int main() {

	// initalize values
	bool keepGoing = true;
	std::string userInput;
	
	// program title and splash screen
	std::cout << "-------------------------" << std::endl;
	std::cout << "KSP Orbital Transfer Tool" << std::endl;
	std::cout << "-------------------------" << std::endl;
	
	// core of main function, keeps the entire program moving and calls the remaining necessary functions
	while (keepGoing) {

		std::cout << " " << std::endl;
		std::cout << "0) Calculate Orbit" << std::endl;
		std::cout << "1) Help" << std::endl;
		std::cout << "2) Quit" << std::endl;
		std::cin >> userInput;
	
		// calculate orbit
		if (userInput == "0") {
			// gets info about user's current and target objects
			currentMenu();
			targetMenu();
			// calculates the necessary orbital values
			calPeriod;
			calPhaseAngle;
			calTransferAngle;
			// outputs the orbital values needed to make a successful transfer
			std::cout << "------------" << std::endl;
			std::cout << "Trajectories" << std::endl;
			std::cout << "------------" << std::endl;
			std::cout << " " << std::endl;
			std::cout << u.getCurrentBody << " ----> " << u.getTargetBody << std::endl;
			std::cout << "Phase Angle: " << u.getPhaseAngle() << std::endl;
			std::cout << "Ejection Period: " << u.getTransferPeriod() << std::endl;
			std::cout << "Ejection Angle: " << u.getTransferAngle() << std::endl;
		} // end if

		// credits
		else if (userInput == "1") {
			std::cout << "Written by Alex Waclawik" << std::endl;
			std::cout << "Credit to Chemistpp for the integer check loop" << std::endl;
		} // end elif
		
		// quits program
		else if (userInput == "2") {
			std::cout << "Goodbye!" << std::endl;
			keepGoing = false;
		} // end elif

		// catches user errors
		else {
			std::cout << "Invalid Input" << std::endl;	
		} // end else
	return 0; // ends main by returning 0
	} // end while loop
} // end main

// gets the user's current position and altitude
void currentMenu() {
	// initalize sentry variable
	bool currentMenuLoop = true;
	// while loop keeps function going
	while (currentMenuLoop) {
		
		std::string currentMenuInput;
		std::cout << "Are you currently orbiting a planet or a moon?" << std::endl;
		std::cout << "0) Planet" << std::endl;
		std::cout << "1) Moon" << std::endl;
		std::cin currentMenuInput;
	
		// if user selects "Planet"
		if (currentMenuInput = "0") {
			std::string currentPlanetInput;
			int currentOrbitInput;
			std::cout << "Choose Planet:" << std::endl;
			std::cout << "0) Moho" << std::endl;
			std::cout << "1) Eve" << std::endl; 
			std::cout << "2) Kerbin" << std::endl; 
			std::cout << "3) Duna" << std::endl; 
			std::cout << "4) Dres" << std::endl; 
			std::cout << "5) Jool" << std::endl; 
			std::cout << "6) Eeloo" << std::endl;
			std::cin >> currentPlanetInput;
			
			// gets user's current orbit
			std::cout << "Current Orbiting Altitude (in meters):" << std::endl;
			std::cin >> currentOrbitInput;
			
			// checks if input is a valid integer
			// source for this small part https://stackoverflow.com/a/18728791
			while (std::cin.fail()) {
				std::cout << "Invalid Input" << std::endl;
				std::cin.ignore(256, '\n');
				std::cin >> currentOrbitInput;
			} // end while
			
			// Moho
			if (currentPlanetInput = "0") {
				std::string newCurrent = "Moho";
				float newUserAxis = Body::getMohoAxis();
				newUserAxis = newUserAxis + currentOrbitInput;
				u.setCurrentBody(newCurrent);
				u.setUserAxis(newUserAxis);
				float newMu = Body::getMohoMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end if
			
			// Eve
			else if (currentPlanetInput = "1") {
				std::string newCurrent = "Eve";
				float newUserAxis = Body::getEveAxis();
				newUserAxis = newUserAxis + currentOrbitInput;
				u.setCurrentBody(newCurrent);
				u.setUserAxis(newUserAxis);
				float newMu = Body::getEveMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif

			// Kerbin
			else if (currentPlanetInput = "2") {
				std::string newCurrent = "Kerbin";
				float newUserAxis = Body::getKerbinAxis();
				newUserAxis = newUserAxis + currentOrbitInput;
				u.setCurrentBody(newCurrent);
				u.setUserAxis(newUserAxis);
				float newMu = Body::getKerbinMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif

			// Duna
			else if (currentPlanetInput = "3") {
				std::string newCurrent = "Duna";
				float newUserAxis = Body::getDunaAxis();
				newUserAxis = newUserAxis + currentOrbitInput;
				u.setCurrentBody(newCurrent);
				u.setUserAxis(newUserAxis);
				float newMu = Body::getDunaMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif

			// Dres
			else if (currentPlanetInput = "4") {
				std::string newCurrent = "Dres";
				float newUserAxis = Body::getDresAxis();
				newUserAxis = newUserAxis + currentOrbitInput;
				u.setCurrentBody(newCurrent);
				u.setUserAxis(newUserAxis);
				float newMu = Body::getDresMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif

			// Jool
			else if (currentPlanetInput = "5") {
				std::string newCurrent = "Jool";
				float newUserAxis = Body::getJoolAxis();
				newUserAxis = newUserAxis + currentOrbitInput;	
				u.setCurrentBody(newCurrent);
				u.setUserAxis(newUserAxis);
				float newMu = Body::getJoolMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif

			// Eeloo
			else if (currentPlanetInput = "6") {
				std::string newCurrent = "Eeloo";
				float newUserAxis = Body::getEelooAxis();
				newUserAxis = newUserAxis + currentOrbitInput;
				u.setCurrentBody(newCurrent);
				u.setUserAxis(newUserAxis);
				float newMu = Body::getEelooMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif
	
			// catches input error
			else {
				std::cout << "Invalid Input" << std::endl;
			} // end else			
		} // end if

		// if user selects "Moon"
		else if (currentMenuInput = "1") {
			
			std::string currentMoonInput;
			int currentOrbitInput;
			std::cout << "Choose Moon" << std::endl;
			std::cout << "0) Gilly" << std::endl;
			std::cout << "1) Mun" << std::endl;
			std::cout << "2) Minmus" << std::endl;
			std::cout << "3) Ike" << std::endl;
			std::cout << "4) Laythe" << std::endl;
			std::cout << "5) Vall" << std::endl;
			atd::cout << "6) Tylo" << std::endl;
			std::cout << "7) Bop" << std::endl;
			std::cout << "8) Pol" << std::endl;
			std::cin >> currentMoonInput;
			
			// same as above, catches input error for altitude
			std::cout << "Current Orbiting Altitude (in meters): " << std::endl;
			std::cin currentOrbitInput;
			while (std::cin.fail()) {
				std::cout << "Invalid Input" << std::endl;
				std::cin.ignore(256, '\n');
				std::cin >> currentOrbitInput;
			} // end while
			
			// Gilly
			if (currentMoonInput = "0") {
				std::string newCurrent = "Gilly";
				float newUserAxis = Moon::getGillyAxis();
				newUserAxis = newUserAxis + currentOrbitInput;
				u.setCurrentBody(newCurrent);
				u.setUserAxis(newUserAxis);
				float newMu = Moon::getGillyMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end if
			
			// Mun
			else if (currentMoonInput = "1") {
				std::string newCurrent = "Mun";
				float newUserAxis = Moon::getMunAxis();
				newUserAxis = newUserAxis + currentOrbitInput;                                                                                                                                                                                               u.setCurrentBody(newCurrent);                                                                                                                                                                                                                u.setUserAxis(newUserAxis);
                                float newMu = Moon::getMunMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif
			
			// Minmus
			else if (currentMoonInput = "2") {
				std::string newCurrent = "Minmus";
				float newUserAxis = Moon::getMinmusAxis();
				newUserAxis = newUserAxis + currentOrbitInput;                                                                                                                                                                                               u.setCurrentBody(newCurrent);                                                                                                                                                                                                                u.setUserAxis(newUserAxis);
                                float newMu = Moon::getMinmusMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif

			// Ike
			else if (currentMoonInput = "3") {
				std::string newCurrent = "Ike";
				float newUserAxis = Moon::getIkeAxis();
				newUserAxis = newUserAxis + currentOrbitInput;                                                                                                                                                                                               u.setCurrentBody(newCurrent);                                                                                                                                                                                                                u.setUserAxis(newUserAxis);
                                float newMu = Moon::getIkeMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif

			// Laythe
			else if (currentMoonInput = "4") {
				std::string newCurrent = "Laythe";
				float newUserAxis = Moon::getLaytheAxis();
				newUserAxis = newUserAxis + currentOrbitInput;                                                                                                                                                                                               u.setCurrentBody(newCurrent);                                                                                                                                                                                                                u.setUserAxis(newUserAxis);
                                float newMu = Moon::getLaytheMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif

			// Vall
			else if (currentMoonInput = "5") {
				std::string newCurrent = "Vall";
				float newUserAxis = Moon::getVallAxis();
				newUserAxis = newUserAxis + currentOrbitInput;                                                                                                                                                                                               u.setCurrentBody(newCurrent);                                                                                                                                                                                                                u.setUserAxis(newUserAxis);
                                float newMu = Moon::getVallMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif

			// Tylo
			else if (currentMoonInput = "6") {
				std::string newCurrent = "Tylo";
				float newUserAxis = Moon::getTyloAxis();
				newUserAxis = newUserAxis + currentOrbitInput;                                                                                                                                                                                               u.setCurrentBody(newCurrent);                                                                                                                                                                                                                u.setUserAxis(newUserAxis);
                                float newMu = Moon::getTyloMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif

			// Bop
			else if (currentMoonInput = "7") {
				std::string newCurrent = "Bop";
				float newUserAxis = Moon::getBopAxis();
				newUserAxis = newUserAxis + currentOrbitInput;                                                                                                                                                                                               u.setCurrentBody(newCurrent);                                                                                                                                                                                                                u.setUserAxis(newUserAxis);
                                float newMu = Moon::getBopMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif

			// Pol
			else if (currentMoonInput = "8") {
				std::string newCurrent = "Pol";
				float newUserAxis = Moon::getPolAxis();
				newUserAxis = newUserAxis + currentOrbitInput;
				u.setCurrentBody(newCurrent);
				u.setUserAxis(newUserAxis);
				float newMu = Moon::getPolMu();
				u.setCurrentMu(newMu);
				currentMenuLoop = false;
			} // end elif
	
			// catches input error
			else {
				std::cout << "Invalid Input" << std::endl;
			} // end else
		
		// catches input error
		else {
			std::cout << "Invalid Input" << std::endl;
		} // end else
	} // end while
} // end function



// similiar to previous function, obtains the user's target body
// also sets the values that will be used for the actual calculations
void targetMenu() {
	bool targetMenuLoop = true;
	while (targetMenuLoop) {

		std::string targetMenuInput;
		std::cout << "Is your destination a planet or a moon?" << std::endl;
		std::cout << "0) Planet" << std::endl;
		std::cout << "1) Moon" << std::endl;
		std::cin targetMenuInput;

		if (targetMenuInput = "0") {
			std::string targetPlanetInput;
			std::cout << "Choose Planet:" << std::endl;
			std::cout << "0) Moho" << std::endl;
			std::cout << "1) Eve" << std::endl; 
			std::cout << "2) Kerbin" << std::endl; 
			std::cout << "3) Duna" << std::endl; 
			std::cout << "4) Dres" << std::endl; 
			std::cout << "5) Jool" << std::endl; 
			std::cout << "6) Eeloo" << std::endl;
			std::cin >> targetPlanetInput;

			// no target altitude needed, not necessary for the calculations
				
			if (targetPlanetInput = "0") {
				std::string newTarget = "Moho";
				float newTargetAxis = Body::getMohoAxis();
				float newTargetSOI = Body::getMohoSOI();
				float newTargetVel = Body::getMohoVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end if

			else if (targetPlanetInput = "1") {
				std::string newTarget = "Eve";
				float newTargetAxis = Body::getEveAxis();
				float newTargetSOI = Body::getEveSOI();
				float newTargetVel = Body::getEveVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif

			else if (targetPlanetInput = "2") {
				std::string newTarget = "Kerbin";
				float newTargetAxis = Body::getKerbinAxis();
				float newTargetSOI = Body::getKerbinSOI();
				float newTargetVel = Body::getKerbinVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif

			else if (targetPlanetInput = "3") {
				std::string newTarget = "Duna";
				float newTargetAxis = Body::getDunaAxis();
				float newTargetSOI = Body::getDunaSOI();
				float newTargetVel = Body::getDunaVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif

			else if (targetPlanetInput = "4") {
				std::string newTarget = "Dres";
				float newTargetAxis = Body::getDresAxis();
				float newTargetSOI = Body::getDresSOI();
				float newTargetVel = Body::getDresVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif

			else if (targetPlanetInput = "5") {
				std::string newTarget = "Jool";
				float newTargetAxis = Body::getJoolAxis();
				float newTargetSOI = Body::getJoolSOI();
				float newTargetVel = Body::getJoolVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif

			else if (targetPlanetInput = "6") {
				std::string newTarget = "Eeloo";
				float newTargetAxis = Body::getEelooAxis();
				float newTargetSOI = Body::getEelooSOI();
				float newTargetVel = Body::getEelooVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif
	
			else {
				std::cout << "Invalid Input" << std::endl;
			} // end else			
		} // end if

		else if (targetMenuInput = "1") {
			
			std::string targetMoonInput;
			std::cout << "Choose Moon" << std::endl;
			std::cout << "0) Gilly" << std::endl;
			std::cout << "1) Mun" << std::endl;
			std::cout << "2) Minmus" << std::endl;
			std::cout << "3) Ike" << std::endl;
			std::cout << "4) Laythe" << std::endl;
			std::cout << "5) Vall" << std::endl;
			atd::cout << "6) Tylo" << std::endl;
			std::cout << "7) Bop" << std::endl;
			std::cout << "8) Pol" << std::endl;
			std::cin >> targetMoonInput;
				
			if (targetMoonInput = "0") {
				std::string newTarget = "Gilly";
				float newTargetAxis = Moon::getGillyAxis();
				float newTargetSOI = Moon::getGillySOI();
				float newTargetVel = Moon::getGillyVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end if
	
			else if (targetMoonInput = "1") {
				std::string newTarget = "Mun";
				float newTargetAxis = Moon::getMunAxis();
				float newTargetSOI = Moon::getMunSOI();
				float newTargetVel = Moon::getMunVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif
			
			else if (targetMoonInput = "2") {
				std::string newTarget = "Minmus";
				float newTargetAxis = Moon::getMinmusAxis();
				float newTargetSOI = Moon::getMinmusSOI();
				float newTargetVel = Moon::getMinmusVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif

			else if (targetMoonInput = "3") {
				std::string newTarget = "Ike";
				float newTargetAxis = Moon::getIkeAxis();
				float newTargetSOI = Moon::getIkeSOI();
				float newTargetVel = Moon::getIkeVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif

			else if (targetMoonInput = "4") {
				std::string newTarget = "Laythe";
				float newTargetAxis = Moon::getLaytheAxis();
				float newTargetSOI = Moon::getLaytheSOI();
				float newTargetVel = Moon::getLaytheVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif

			else if (targetMoonInput = "5") {
				std::string newTarget = "Vall";
				float newTargetAxis = Moon::getVallAxis();
				float newTargetSOI = Moon::getVallSOI();
				float newTargetVel = Moon::getVallVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif

			else if (targetMoonInput = "6") {
				std::string newTarget = "Tylo";
				float newTargetAxis = Moon::getTyloAxis();
				float newTargetSOI = Moon::getTyloSOI();
				float newTargetVel = Moon::getTyloVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif

			else if (targetMoonInput = "7") {
				std::string newTarget = "Bop";
				float newTargetAxis = Moon::getBopAxis();
				float newTargetSOI = Moon::getBopSOI();
				float newTargetVel = Moon::getBopVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif

			else if (targetMoonInput = "8") {
				std::string newTarget = "Pol";
				float newTargetAxis = Moon::getPolAxis();
				float newTargetSOI = Moon::getPolSOI();
				float newTargetVel = Moon::getPolVel();
				u.setTargetBody(newTarget);
				u.setTargetAxis(newTargetAxis);
				u.setTargetSOI(newTargetSOI);
				u.setTargetVel(newTargetVel);
				targetMenuLoop = false;
			} // end elif
	
			else {
				std::cout << "Invalid Input" << std::endl;
			} // end else 
		} // end elif
		
		else {
			std::cout << "Invalid Input" << std::endl;
		} // end else
	} // end while
} // end function




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
void calPhaseAngle() {
	float tempTargetAxis = u.getTargetAxis();
	float tempTransferAxis = u.getTransferAxis();
	float tempPhaseAngle = 1 / (2 * sqrt((pow(tempTargetAxis, 3) / pow(tempTransferAxis, 3)));
	u.setPhaseAngle(tempPhaseAngle);
} // end function


// calculates Transfer Orbit Angle using values:
// 	*Orbital Period of Target Object
// 	*Orbital Period of Transfer Orbit
void calTransferAngle() {
	float tempTargetPeriod = u.getTargetPeriod()
	float tempTransferPeriod = u.getTransferPeriod()
	float tempTransferAngle = 360 * (0.5 - (tempTransferPeriod / (2 * tempTargetPeriod)));
	u.setTransferAngle(tempTransferAngle);
} // end function
