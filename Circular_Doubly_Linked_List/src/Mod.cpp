#include "Mod.hpp"
#include <iostream>
using namespace std;

int Mod::GetMod(int number, int otherNumber) 
{
	int maxValue;
	int minValue;
	int mod;

	if (number > otherNumber) 
	{
		maxValue = number;
		minValue = otherNumber;
	}
	else 
	{
		maxValue = otherNumber;
		minValue = number;
	}

	mod = maxValue % minValue;

	return mod;
}
