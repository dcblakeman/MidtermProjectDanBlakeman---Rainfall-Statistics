#pragma once
//Daniel Blakeman
//CIS 2207-502
//Midterm Project - Rainfall Statistics

#include <stdexcept>
#include <string>

class PrecondViolatedExcept : public std::logic_error 
{
public:
	PrecondViolatedExcept(const std::string& message = "");
}; // end PrecondViolatedExcept

