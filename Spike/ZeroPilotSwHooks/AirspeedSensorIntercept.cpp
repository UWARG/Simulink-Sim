#include "airspeed.hpp"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

/***********************************************************************************************************************
 * Code
 **********************************************************************************************************************/

void SimulatedAirspeed :: Init()
{
    return;
}

void SimulatedAirspeed :: Begin_Measuring()
{
    return;
}

void SimulatedAirspeed :: GetResult(airspeedData_t *Data)
{
    std::ifstream airspeedFile;

    std::string line, previousLine;
    std::string returnChar ("\n");

    airspeedFile.open("SimulationResults/SensorOutputs/airspeed.txt");

    int i = 0;

    do
    {
        previousLine = line;

        getline(airspeedFile, line);
    }
    while (line.length() == 8);

    airspeedFile.close();

    Data->airspeed = std::stof(previousLine);
    Data->isDataNew = true;
    Data->sensorStatus = 0;
}
