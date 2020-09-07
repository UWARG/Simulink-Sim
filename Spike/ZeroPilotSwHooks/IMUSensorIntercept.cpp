#include "IMU.hpp"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

/***********************************************************************************************************************
 * Code
 **********************************************************************************************************************/

void SimulatedIMU :: GetResult(IMUData_t &Data)
{
    Data.accx = this->getNewestDataPoint("SensorOutputs/accX.txt");
    Data.accy = this->getNewestDataPoint("SensorOutputs/accY.txt");
    Data.accz = this->getNewestDataPoint("SensorOutputs/accZ.txt");

    Data.gyrx = this->getNewestDataPoint("SensorOutputs/gyrX.txt");
    Data.gyry = this->getNewestDataPoint("SensorOutputs/gyrY.txt");
    Data.gyrz = this->getNewestDataPoint("SensorOutputs/gyrZ.txt");

    Data.magx = this->getNewestDataPoint("SensorOutputs/magX.txt");
    Data.magy = this->getNewestDataPoint("SensorOutputs/magY.txt");
    Data.magz = this->getNewestDataPoint("SensorOutputs/magZ.txt");

    Data.isDataNew = true;
    Data.sensorStatus = 0;
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
