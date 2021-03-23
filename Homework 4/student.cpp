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
    priority = rand() % 10 + 1; //randomly generated priority level
}

int Student::getTimeNeeded()
{
    return timeNeeded;
}

int Student::getPriority()
{
    return priority;
}

bool operator <(const Student &lhs, const Student &rhs)
{
    return lhs.priority<rhs.priority;
}
