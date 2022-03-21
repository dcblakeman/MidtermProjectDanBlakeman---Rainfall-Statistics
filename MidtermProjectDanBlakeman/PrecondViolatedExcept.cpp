//Daniel Blakeman
//CIS 2207-502
//Midterm Project - Rainfall Statistics
#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message) : std::logic_error("Precondition Violated Exception: " + message)
{
}