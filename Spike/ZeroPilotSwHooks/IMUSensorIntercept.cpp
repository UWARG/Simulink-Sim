#include "IMU.hpp"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

/***********************************************************************************************************************
 * Code
 **********************************************************************************************************************/

void SimulatedIMU :: Init()
{
    return;
}

void SimulatedIMU :: Begin_Measuring()
{
    return;
}

void SimulatedIMU :: GetResult(airspeedData_t *Data)
{
    Data->accx = this.getNewestDataPoint("SimulationResults/SensorOutputs/accX.txt");
    Data->accY = this.getNewestDataPoint("SimulationResults/SensorOutputs/accY.txt");
    Data->accZ = this.getNewestDataPoint("SimulationResults/SensorOutputs/accZ.txt");

    Data->gyrx = this.getNewestDataPoint("SimulationResults/SensorOutputs/gyrX.txt");
    Data->gyrY = this.getNewestDataPoint("SimulationResults/SensorOutputs/gyrY.txt");
    Data->gyrZ = this.getNewestDataPoint("SimulationResults/SensorOutputs/gyrZ.txt");

    Data->magx = this.getNewestDataPoint("SimulationResults/SensorOutputs/magX.txt");
    Data->magY = this.getNewestDataPoint("SimulationResults/SensorOutputs/magY.txt");
    Data->magZ = this.getNewestDataPoint("SimulationResults/SensorOutputs/magZ.txt");

    Data->isDataNew = true;
    Data->status = 0;
}

float SimulatedIMU :: getNewestDataPoint(const char * fileName)
{
    std::ifstream dataFile;
    std::string line, previousLine;
    std::string returnChar ("\n");

    dataFile.open(fileName);

    do
    {
        previousLine = line;

        getline(dataFile, line);
    }
    while (line.length() == 8);

    dataFile.close();

    return std::stof(previousLine);
}
