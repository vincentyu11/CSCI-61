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
    topicGenerator = rand() % 4;
    topic = static_cast<char>(('A' + topicGenerator)); //randomly generated topic, 4 in total
    nameGenrator = rand() % 10 + 1;
    name =  "Student " + std::to_string(nameGenrator); //randomly generated student name, 10 students in total
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
