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
    Data->accx = this.getNewestDataPoint("SensorOutputs/accX.txt");
    Data->accY = this.getNewestDataPoint("SensorOutputs/accY.txt");
    Data->accZ = this.getNewestDataPoint("SensorOutputs/accZ.txt");

    Data->gyrx = this.getNewestDataPoint("SensorOutputs/gyrX.txt");
    Data->gyrY = this.getNewestDataPoint("SensorOutputs/gyrY.txt");
    Data->gyrZ = this.getNewestDataPoint("SensorOutputs/gyrZ.txt");

    Data->magx = this.getNewestDataPoint("SensorOutputs/magX.txt");
    Data->magY = this.getNewestDataPoint("SensorOutputs/magY.txt");
    Data->magZ = this.getNewestDataPoint("SensorOutputs/magZ.txt");

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
