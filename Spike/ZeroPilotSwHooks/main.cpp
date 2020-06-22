#define SIMULATION

#include "airspeed.hpp"

#include <iostream>
#include <cstdio>

int main(void)
{

	airspeedData_t data;

	Simulated airspeedSim;

	airspeedSim.GetResult(&data);

	std::cout << data.airspeed << std::endl;

	return 0;
}

/**
 * Functions for communicating actuator commands to the safety chip,
 * which in turn, sends the data out to the actuators.
 * Author: Anthony Berbari
 */
