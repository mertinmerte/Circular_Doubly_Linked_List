#include "Obeb.hpp"
#include <iostream>
using namespace std;

int Obeb::GetObeb(int number, int otherNumber) 
{
	int maxValue;
	int obeb;

	if (number > otherNumber) 
	{
		maxValue = number;
	}
	else 
	{
		maxValue = otherNumber;
	}

	for (maxValue; maxValue > 0; maxValue--) 
	{
		if ((number % maxValue == 0) && (otherNumber % maxValue == 0)) 
		{
			obeb = maxValue;
			break;
		}
	}
	return obeb;
}
