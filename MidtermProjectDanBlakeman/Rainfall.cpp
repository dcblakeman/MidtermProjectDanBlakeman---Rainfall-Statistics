#pragma once
//Daniel Blakeman
//CIS 2207-502
//Midterm Project - Rainfall Statistics
#include "Rainfall.h"
#include<string>

string Rainfall::getMonth()
{
	return month;
}

void Rainfall::setMonth(string setMonth)
{
	month = setMonth;
}

float Rainfall::getRainAmount()
{
	return rainAmount;
}

void Rainfall::setRainAmount(float setRainAmount)
{
	rainAmount = setRainAmount;
}
