#include "SendInstructionsToSafety.hpp"
#include "AttitudeDatatypes.hpp"

#include "Infinion.h"

#include <fstream>
#include <stdio.h>

/***********************************************************************************************************************
 * Variables
 **********************************************************************************************************************/

static std::fstream throttleFile;
static std::fstream aileronFile;
static std::fstream elevatorFile;
static std::fstream rudderFile;

static InfinionModelClass Infinion;

/***********************************************************************************************************************
 * Code
 **********************************************************************************************************************/

void SendToSafety_Init(void)
{

    throttleFile.open("ActuatorCommands/throttle.txt", std::fstream::out);
    aileronFile.open("ActuatorCommands/aileron.txt", std::fstream::out);
    elevatorFile.open("ActuatorCommands/elevator.txt", std::fstream::out);
    rudderFile.open("ActuatorCommands/rudder.txt", std::fstream::out);

    throttleFile << "";
    aileronFile << "";
    elevatorFile << "";
    rudderFile << "";

    throttleFile.close();
    aileronFile.close();
    elevatorFile.close();
    rudderFile.close();

    Infinion.initialize();

    return;
}

SendToSafety_error_t SendToSafety_Execute(int channel, int percent)
{
    SendToSafety_error_t errorStruct;
    errorStruct.errorCode = 0;

    static int channelOut[4];
    static int i;

    channelOut[channel] = percent;

    i++;

    if ( i == 4)
    {
        i = 0;

        throttleFile.open("ActuatorCommands/throttle.txt", std::fstream::app);
        aileronFile.open("ActuatorCommands/aileron.txt", std::fstream::app);
        elevatorFile.open("ActuatorCommands/elevator.txt", std::fstream::app);
        rudderFile.open("ActuatorCommands/rudder.txt", std::fstream::app);

        throttleFile << channelOut[THROTTLE_OUT_CHANNEL] << " ";
        aileronFile << channelOut[AILERON_OUT_CHANNEL] << " ";
        elevatorFile << channelOut[ELEVATOR_OUT_CHANNEL] << " ";
        rudderFile << channelOut[RUDDER_OUT_CHANNEL] << " ";

        throttleFile.close();
        aileronFile.close();
        elevatorFile.close();
        rudderFile.close();

        Infinion.step();
    }

    return errorStruct;
}
