//
//  main.cpp
//  2
//

#include "student.h"
#include <iostream>
#include <ctime>
#include <queue>
using namespace std;

int studentProbability();

int main()
{
    int totalWaitTime = 0;
    int totalOfficeTime = 0;
    int studentsInLine = 0;
    int timeAfterOneHour = 0;
    
    int setProb = 10;  //*****The probablility that a student will show up each minute. SET BETWEEN 10 and 100*****
    
    for (int i=1; i<=100; i++) //100 day simulation of office hours
    {
        cout <<"Office hour day " <<i <<endl;
        int count = 0;
        priority_queue <Student> q1;
        priority_queue <int> q2;
        srand(i);
        
        for (int i=0; i<60; i++) //Simulation of 60 minutes of office hours
        {
            int time = 0;
            int prob = studentProbability();
            cout << "Minute: " << i <<"\t\t";
            
            if (prob <= (100-setProb))
            {
                cout << "No student" <<"\t\t";
            }
            else if (prob > (100-setProb))
            {
                cout << "A student shows up" <<"\t\t";
            }
            
            if (prob > (100-setProb))
            {
                Student a;
                q1.push(a);
                q2.push(i);
                
                cout <<"Time needed: " << a.getTimeNeeded() <<"\t\t" <<"Priority: " <<a.getPriority();
                time = time + a.getTimeNeeded();
                studentsInLine = studentsInLine + 1; //calculate total number of students
                totalOfficeTime = totalOfficeTime + a.getTimeNeeded(); //calculate total office time
                count = count+1;
                
                if ((i + a.getTimeNeeded()) > 59) //calculate overtime
                {
                    timeAfterOneHour = timeAfterOneHour + (((i + a.getTimeNeeded())-1) - 59);
                }
            }
            cout <<endl;
        }
        cout <<"Number of students today: " <<count <<endl <<endl;
        int tempTime = q2.top();
        while (!q1.empty()) //calculating wait time
        {
            if (q1.size()>=1)
            {
                if (q1.size() == 1)
                {
                    break;
                }
                Student temp = q1.top();
                int studentTime = temp.getTimeNeeded();
                tempTime = tempTime + studentTime;
                q1.pop();
                q2.pop();
                if ((tempTime-1) < q2.top())
                {
                    tempTime = q2.top();
                }
                else if ((tempTime-1) >= q2.top())
                {
                    totalWaitTime = totalWaitTime + (tempTime - q2.top());
                }
            }
        }
    }
    
    //reporting results section
    cout << endl;
    cout << "--------" << endl << "Results" <<endl <<"--------" <<endl;
    cout << "Simulation using priority queue" <<endl;
    cout << setProb <<"% chance that a student will show up each minute" <<endl <<endl;
    cout << "Total students: " <<studentsInLine <<" students"<<endl;
    cout << "Total office time: " <<totalOfficeTime <<" minutes" <<endl;
    cout << "Total wait time: " <<totalWaitTime <<" minutes" <<endl;
    cout << "Time professor spent past an hour: " <<timeAfterOneHour <<" minutes" <<endl;
    cout << "Average office time per student: " <<double(totalOfficeTime)/double(studentsInLine) <<" minutes"<<endl;
    cout << "Average wait time per student: " <<double(totalWaitTime)/double(studentsInLine) <<" minutes"<<endl;
    cout << "Average time professor spent past an hour: " <<double(timeAfterOneHour)/100.0 <<" minutes" <<endl;
    cout << endl;
    
    return 0;
}


//randomly generated number (1-100).
//if number meets probability requirement, a student will show up
int studentProbability()
{
    return rand() % 100 + 1;
}
