## Alex Waclawik
## April 27th, 2020
## Orbital Transfer Calculato


## Glossary

###### Key Terms
	1) Prograde
		* rotational motion that is in the direction of the central body's orbit
	2) Retrograde
		* rotation motion that is in the opposite direction of the central body's orbit
	3) Apoapsis
		* highest point in an orbit where kinetic energy is lowest and potential energy is highest
	4) Periapsis
		* lowest point in an orbit where kinetic energy is highest and potential energy is lowest
	5) Orbital Period
		* time it takes for an object to complete a single orbit around a body
	6) [Semi-Major Axis](https://en.wikipedia.org/wiki/Semi-major_and_semi-minor_axes)
		* longest radius of an orbit
	7) [Standard Gravitational Parameter](https://en.wikipedia.org/wiki/Standard_gravitational_parameter)
		* represented by Mu, it is the product of the gravitational constant G and the mass of the body
	8) [Sphere of Influence](https://en.wikipedia.org/wiki/Sphere_of_influence_(astrodynamics))
		* the sphereical region around a body where it has gravitational influence over an orbiting object
	9) [Escape Velocity](https://en.wikipedia.org/wiki/Escape_velocity)
		* minimum speed needed to escape the gravitational influence of a body
	10) [Phase Angle](https://en.wikipedia.org/wiki/Phase_angle_(astronomy))
		* angle between the current body, target body, and the central body (sun or planet)
		* this tells you how far forward or backward the target body will be relative to you
	11) Transfer Angle
		* the angle where the ejection burn will commence
		* the angle will always be relative to the current body's prograde

###### [Hohmann Transfer](https://en.wikipedia.org/wiki/Hohmann_transfer_orbit)
	* This manuever is the most efficent way to perform an interplanetary transfer.
	* Utilizes and elliptical orbit and a periapsis burn (where you have the most kinetic energy)


## Algorithm

###### Goals
	* Given inputs about the user's current orbit, calculate the necessary trajectories to perform a Hohmann Transfer Orbit to a body of the user's choice.
	* This program is intended to be used as a companion to the game Kerbal Space Program

###### Inputs
	* primary body currently being orbited
	* apoapsis of the orbit
	* periapsis of the orbit
	* body that the user wants to transfer to

###### Outputs
	* phase angle of the manuever
	* transfer angle of the manuever

###### Variables
	* N/A

###### Libraries
	* <iostream>
	* <fstream>
	* <cmath>


## Procedure

###### Data Structures
	1) Body
		* static data structure that contains important information about each of the planets
			* Standard Gravitational Parameter (m^2*s^-2)
                        * Length of Semi-Major Axis (m)
                       	* Radius of Sphere of Influence (m)
                        * Sphere of Influence Exit Velocity (m/s)
	2) Moon
		* static data structure that contains important information about each of the planets
			* Standard Gravitational Parameter (m^2*s^-2)
                        * Length of Semi-Major Axis (m)
                        * Radius of Sphere of Influence (m)
                        * Sphere of Influence Exit Velocity (m/s)

###### Calculation
	1) After user input is taken, several values will be directly and indirectly extrapolated
		* Current Body
			* semi-major axis of current orbit (r_current)
			* standard gravitational parameter of current primary body (mu_current)
		* Target Body
			* semi-major axis of target body (r_target)
			* sphere of influence of target body (soi_target)
			* escape velocity of target body (v_e)
	2) Using these values, the program will then calculate the following information:
		* semi-major axis of transfer orbit
			* r_transfer = (r_current + r_target) / 2
		* orbital period of target body
			* T_target = 2pi * sqrt[r_target^3 / mu_current]
		* orbital period of transfer orbit
			* T_transfer = 2pi * sqrt[(r_transfer)^3/mu_current]
		* phase angle
			* P_angle = 1 / [2 * sqrt(r_target^3 / r_transfer^3)]
		* transfer angle 
			* T_angle = 360 * (1/2 - (T_transfer/2 * T_target))
