#define SIMULATION

#include "SendInstructionsToSafety.hpp"

#include <iostream>
#include <cstdio>

int main(void)
{

	SendToSafety_Init();

	float testData[4] = {0,0,0,50};

	for (int i = 0; i < 100; i++)
	{
		SendToSafety_Execute(testData);
	}

	return 0;
}
