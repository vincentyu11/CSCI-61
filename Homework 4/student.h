//
//  student.h
//  2
//

#ifndef student_h
#define student_h
#include <stdio.h>

class Student
{
public:
    Student();
    int getTimeNeeded();
    int getPriority();
    int timeNeeded;
    int priority;
};

bool operator <(const Student &lhs, const Student &rhs);

#endif /* student_h */
