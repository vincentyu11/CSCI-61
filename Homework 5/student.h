//
//  student.h
//  2
//

#ifndef student_h
#define student_h
#include <stdio.h>
#include <string>

class Student
{
public:
    Student();
    int getTimeNeeded();
    int getPriority();
    int timeNeeded;
    int priority;
    char topic;
    int topicGenerator;
    std::string name;
    int nameGenrator;
};

bool operator <(const Student &lhs, const Student &rhs);

#endif /* student_h */
