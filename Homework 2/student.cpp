//
//  student.cpp
//  2
//


#include "student.h"
#include <cstdlib>
#include <ctime>

Student::Student()
{
    timeNeeded = rand() % 10 + 1; //randomly generated time needed with professor
}

int Student::getTimeNeeded()
{
    return timeNeeded;
}
