#include "SendInstructionsToSafety.hpp"
#include "AttitudeDatatypes.hpp"

#include "Spike.h"

#include <fstream>
#include <stdio.h>

/***********************************************************************************************************************
 * Variables
 **********************************************************************************************************************/

static std::fstream throttleFile;
static std::fstream aileronFile;
static std::fstream tailLeftFile;
static std::fstream tailRightFile;

static SpikeModelClass Spike;

/***********************************************************************************************************************
 * Code
 **********************************************************************************************************************/

void SendToSafety_Init(void)
{

    throttleFile.open("throttle.txt", std::fstream::out);
    aileronFile.open("aileron.txt", std::fstream::out);
    tailLeftFile.open("tailLeft.txt", std::fstream::out);
    tailRightFile.open("tailRight.txt", std::fstream::out);

    throttleFile << "";
    aileronFile << "";
    tailLeftFile << "";
    tailRightFile << "";

    throttleFile.close();
    aileronFile.close();
    tailLeftFile.close();
    tailRightFile.close();

    Spike.initialize();

    return;
}

void SendToSafety_Execute(float *channelOut)
{

    throttleFile.open("SimulationResults/ActuatorCommands/throttle.txt", std::fstream::app);
    aileronFile.open("SimulationResults/ActuatorCommands/aileron.txt", std::fstream::app);
    tailLeftFile.open("SimulationResults/ActuatorCommands/tailLeft.txt", std::fstream::app);
    tailRightFile.open("SimulationResults/ActuatorCommands/tailRight.txt", std::fstream::app);

    throttleFile << channelOut[THROTTLE_OUT_CHANNEL] << " ";
    aileronFile << channelOut[AILERON_OUT_CHANNEL] << " ";
    tailLeftFile << channelOut[L_TAIL_OUT_CHANNEL] << " ";
    tailRightFile << channelOut[R_TAIL_OUT_CHANNEL] << " ";

    throttleFile.close();
    aileronFile.close();
    tailLeftFile.close();
    tailRightFile.close();

    Spike.step();
}
