
#include "airspeed.hpp"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

/***********************************************************************************************************************
 * Code
 **********************************************************************************************************************/

void SimulatedAirspeed :: Begin_Measuring()
{
    return;
}

void SimulatedAirspeed :: GetResult(airspeedData_t &Data)
{
    static bool firstCall = true;

    if (firstCall)  // TODO this is a shit solution, but the issue is that this data is not ready until we do a step of the model.
                    // But we cannot do a step of the model until the state machine gives it instructions.
                    // But the state machine cannot give it instructions until it knows where the aircraft is.
    {
        Data.airspeed = 10;
        Data.isDataNew = true;
        Data.sensorStatus = 0;

        firstCall = false;
        return;
    }

    std::ifstream airspeedFile;

    std::string line, previousLine;
    std::string returnChar ("\n");

    airspeedFile.open("SensorOutputs/airspeed.txt");

    do
    {
        previousLine = line;

        getline(airspeedFile, line);
    }
    while (!line.empty());

    airspeedFile.close();

    Data.airspeed = std::stof(previousLine);
    Data.isDataNew = true;
    Data.sensorStatus = 0;
}
