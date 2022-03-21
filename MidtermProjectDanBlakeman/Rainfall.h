#pragma once
//Daniel Blakeman
//CIS 2207-502
//Midterm Project - Rainfall Statistics
#include<string>
using namespace std;

class Rainfall
{
	//Variables
private:
	string month;
	float rainAmount;

public:
	string getMonth();
	void setMonth(string month);
	float getRainAmount();
	void setRainAmount(float rainAmount);
};
