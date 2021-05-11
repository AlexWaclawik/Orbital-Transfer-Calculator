April 27th, 2020
Alex Waclawik
Final Project Algorithm

Goal: To create a C++ program that can calculate trajectories to perform a Hohmann Transfer Orbit with relation to the current and target body. 

Inputs: User inputs the current orbiting body, target body, and the apoapsis and periapsis of their orbit. 

Outputs: Program will calculate the necessary orbital trajectory needed to perform a transfer orbit with the target body. 


Data Structure

	Main File // will navigate user as well as handle the actual calculations 
		Functions:

			main()
				- will call upon the other functions and act as the central hub of the program

			currentMenu()
				- will gather input from the user about their current body and orbit altitude

			targetMenu()
				- will gather input from the user about their target body

			calPeriod()
				- calculate the Orbital Period of Target Body
				- calculate Orbital Period of Transfer Orbit
				- calculate the Semi-Major Axis of Transfer Orbit

			calPhaseAngle()
				- calculate the Phase Angle

			calTransferAngle()
				- calculate the Transfer Angle

	
			
	User Class // stores the user input, information about the current and target bodies, and the results from the calculations
		- contains several properties that are used for calculations:
			- Current Body
			- Semi-Major Axis of Users Orbit
			- Standard Gravitational Parameter of Current Body
			
			- Semi-Major Axis of Target Body
			- Sphere of Influence of Target Body
			- Sphere of Influence Exit Velocity of Target Body

			- Semi-Major Axis of Transfer Orbit
			- Orbital Period of Target Body
			- Orbital Period of Transfer Orbit
			- Phase Angle
			- Angle of Transfer Orbit
		


	Body Class
		- contains the planets of the Kerbol system that orbit the central star
		- each planet has several properties that are initalized by constructor
			- Mu (Standard Gravitational Parameter)
			- Length of Semi-Major Axis
			- Radius of Sphere of Influence
			- Sphere of Influence Exit Velocity
		- static members as these values do not change
		- no other methods outside setters and getters for properties

	Moon Class
		- contains the moons that orbit around planets
		- each planet has several properties that are initalized by constructor
			- Mu (Standard Gravitational Parameter)
                        - Length of Semi-Major Axis                                                                                                                                                                                                                  - Radius of Sphere of Influence                                                                                                                                                                                                              - Sphere of Influence Exit Velocity
		- static members as these values do not change
		- no other methods outside setters and getters for properties
