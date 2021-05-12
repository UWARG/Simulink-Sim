#include "SensorFusion.hpp"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cmath>

/***********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************/

constexpr float m_pi = 3.14159;

/***********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************/

static float getNewestDataPoint(const char * fileName);
static bool resultsDirIsEmpty();

/***********************************************************************************************************************
 * Code
 **********************************************************************************************************************/

void SF_Init(void)
{
}

SFError_t SF_GetResult(SFOutput_t *SFoutput)
{

    SFError_t errorStruct;
    errorStruct.errorCode = 0;


    if (resultsDirIsEmpty())  // Data is not ready until we do a step of the model.But we cannot do a step of the model until the state machine gives it instructions.But the state machine cannot give it instructions until it knows where the aircraft is, so this is the starting point.
    {

        SFoutput->roll = 0;
        SFoutput->pitch = 0;
        SFoutput->yaw = 0;

        SFoutput->rollRate = 0;
        SFoutput->pitchRate = 0;
        SFoutput->yawRate = 0;

        SFoutput->airspeed = 15;

        SFoutput->rateOfClimb = 0;
        SFoutput->latitudeSpeed = 0;
        SFoutput->longitudeSpeed = 15;

        SFoutput->latitude = 21.322;
        SFoutput->longitude = -157.924;
        SFoutput->altitude = 1000;

        SFoutput->track = 0 * (180.0 / m_pi);

        return errorStruct;
    }


    SFoutput->roll = getNewestDataPoint("SensorOutputs/roll.txt");
    SFoutput->pitch = getNewestDataPoint("SensorOutputs/pitch.txt");
    SFoutput->yaw = getNewestDataPoint("SensorOutputs/yaw.txt");

    SFoutput->rollRate = getNewestDataPoint("SensorOutputs/rollRate.txt");
    SFoutput->pitchRate = getNewestDataPoint("SensorOutputs/pitchRate.txt");
    SFoutput->yawRate = getNewestDataPoint("SensorOutputs/yawRate.txt");

    SFoutput->airspeed = getNewestDataPoint("SensorOutputs/airspeed.txt");

    SFoutput->rateOfClimb = getNewestDataPoint("SensorOutputs/rateOfClimb.txt");
    SFoutput->latitudeSpeed = getNewestDataPoint("SensorOutputs/latitudeSpeed.txt");
    SFoutput->longitudeSpeed = getNewestDataPoint("SensorOutputs/longitudeSpeed.txt");

    SFoutput->latitude = getNewestDataPoint("SensorOutputs/latitude.txt");
    SFoutput->longitude = getNewestDataPoint("SensorOutputs/longitude.txt");
    SFoutput->altitude = getNewestDataPoint("SensorOutputs/altitude.txt");

    SFoutput->track = getNewestDataPoint("SensorOutputs/track.txt") * (180.0 / m_pi);

    return errorStruct;

}

IMU_Data_t SF_GetRawIMU()
{

    IMU_Data_t imuStruct;

    if (resultsDirIsEmpty())  // Data is not ready until we do a step of the model.But we cannot do a step of the model until the state machine gives it instructions.But the state machine cannot give it instructions until it knows where the aircraft is, so this is the starting point.
    {

        imuStruct.accx = 0;
        imuStruct.accy = 0;
        imuStruct.accz = -9.8;

        imuStruct.gyrx = 0;
        imuStruct.gyry = 0;
        imuStruct.gyrz = 0;

        imuStruct.magx = 0;
        imuStruct.magy = 1;
        imuStruct.magz = 0;

        imuStruct.sensorStatus = 0;

        return imuStruct;

    }

        imuStruct.accx = getNewestDataPoint("SensorOutputs/accX.txt");
        imuStruct.accy = getNewestDataPoint("SensorOutputs/accY.txt");
        imuStruct.accz = getNewestDataPoint("SensorOutputs/accZ.txt");

        imuStruct.gyrx = getNewestDataPoint("SensorOutputs/gyrX.txt");
        imuStruct.gyry = getNewestDataPoint("SensorOutputs/gyrY.txt");
        //imuStruct.gyrz = getNewestDataPoint("SensorOutputs/gyrZ.txt");
        imuStruct.gyrz = std::nan("1");

#ifdef SOMEONE_EVENTUALLY_BUYS_AN_IMU_WITH_A_MAGNETOMETER
        imuStruct.magx = getNewestDataPoint("SensorOutputs/roll.txt");
        imuStruct.magy = getNewestDataPoint("SensorOutputs/roll.txt");
        imuStruct.magz = getNewestDataPoint("SensorOutputs/roll.txt");
#endif

        imuStruct.sensorStatus = 0;

        return imuStruct;
}


static float getNewestDataPoint(const char * fileName)
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

static bool resultsDirIsEmpty()
{
    static bool provenToExist = false;

    if (! provenToExist)
    {
        if (FILE *file = fopen("SensorOutputs/accX.txt", "r"))
        {
            fclose(file);
            provenToExist = true;
        }

        else
        {
            return true;
        }
    }

    return false;
}
