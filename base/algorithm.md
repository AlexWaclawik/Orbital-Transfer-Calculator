## Algorithm

###### Alex Waclawik
###### May 11th, 2021
###### Orbital Transfer Calculator


## Glossary

###### Prograde
	* rotational motion that is in the direction of the central body's orbit

###### Retrograde
	* rotation motion that is in the opposite direction of the central body's orbit

###### Apoapsis
	* highest point in an orbit where kinetic energy is lowest and potential energy is highest

###### Periapsis
	* lowest point in an orbit where kinetic energy is highest and potential energy is lowest

###### Orbital Period
	* time it takes for an object to complete a single orbit around a body

###### [Semi-Major Axis](https://en.wikipedia.org/wiki/Semi-major_and_semi-minor_axes)
	* longest radius of an orbit

###### [Standard Gravitational Parameter](https://en.wikipedia.org/wiki/Standard_gravitational_parameter)
	* represented by Mu, it is the product of the gravitational constant G and the mass of the body

###### [Escape Velocity](https://en.wikipedia.org/wiki/Escape_velocity)
	* minimum speed needed to escape the gravitational influence of a body

###### [Phase Angle](https://en.wikipedia.org/wiki/Phase_angle_(astronomy))
	* angle between the current body, target body, and the central body (sun or planet)
	* this tells you how far forward or backward the target body will be relative to you
###### [Delta V](https://en.wikipedia.org/wiki/Delta-v)
	* because there is a lack of non-conservative forces (like air resistance), you maintain the same speed when performing maneuvers
	* this is why the transfer is a two steps process:
		1) calculate change in velocity needed to escape the current body (speed up)
		2) calculate change in velocity needed to be captured by target body (slow down)

###### [Hohmann Transfer](https://en.wikipedia.org/wiki/Hohmann_transfer_orbit)
	* This manuever is the most efficent way to perform an interplanetary transfer.
	* Utilizes and elliptical orbit and a periapsis burn (where you have the most kinetic energy)

###### [Kerbal Space Program](https://en.wikipedia.org/wiki/Kerbal_Space_Program)
	* A sandbox space flight simulator that features realistic orbital mechanics and physics.
	* Values for the body's are taken directly from the [Kerbal Space Program Wiki](https://wiki.kerbalspaceprogram.com/wiki/Main_Page)


## Summary

###### Goals
	* Given inputs about the user's current orbit, calculate the necessary trajectories to perform a Hohmann Transfer Orbit to a body of the user's choice.
	* This program is intended to be used as a companion to the game Kerbal Space Program

###### Inputs
	* primary body currently being orbited
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
	* Body
		* static data structure that contains important information about each of the planets
			* planet identifer (number 0-6)
				* 0 - Moho
				* 1 - Eve
				* 2 - Kerbin
				* 3 - Duna
				* 4 - Dres
				* 5 - Jool
				* 5 - Eeloo
                        * Length of Semi-Major Axis (m)
                        * Escape Velocity (m/s)

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
		* delta v required for ejection and insertion burn
		* angular velocity of target body
		* orbital period of transfer orbit
		* phase angle

###### ![Equations](/equations.png)
