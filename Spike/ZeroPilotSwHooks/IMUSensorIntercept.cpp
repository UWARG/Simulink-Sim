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

    static bool firstCall = true;

    if (firstCall)  // TODO this is a shit solution, but the issue is that this data is not ready until we do a step of the model.
                    // But we cannot do a step of the model until the state machine gives it instructions.
                    // But the state machine cannot give it instructions until it knows where the aircraft is.
    {
        Data.accx = 0;
        Data.accy = 0;
        Data.accz = 1;

        Data.gyrx = 0;
        Data.gyry = 0;
        Data.gyrz = 0;

        Data.magx = 1;
        Data.magy = 0;
        Data.magz = 0;

        Data.isDataNew = true;
        Data.sensorStatus = 0;

        firstCall = false;
        return;
    }
    Data.accx = this->getNewestDataPoint("SensorOutputs/accX.txt");
    Data.accy = this->getNewestDataPoint("SensorOutputs/accY.txt");
    Data.accz = this->getNewestDataPoint("SensorOutputs/accZ.txt");

    Data.gyrx = this->getNewestDataPoint("SensorOutputs/gyrX.txt");
    Data.gyry = this->getNewestDataPoint("SensorOutputs/gyrY.txt");
    Data.gyrz = this->getNewestDataPoint("SensorOutputs/gyrZ.txt");

    //Data.magx = this->getNewestDataPoint("SensorOutputs/magX.txt");
    //Data.magy = this->getNewestDataPoint("SensorOutputs/magY.txt");   TODO simulation needs to turn headings into mag data
    //Data.magz = this->getNewestDataPoint("SensorOutputs/magZ.txt");

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
    while (!line.empty());

    dataFile.close();

    return std::stof(previousLine);
}
