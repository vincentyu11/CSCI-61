//
//  main.cpp
//  2
//

#include "student.h"
#include <iostream>
#include <ctime>
#include <queue>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <string>
using namespace std;

int studentProbability();


int main()
{
    int totalWaitTime = 0;
    int totalOfficeTime = 0;
    int studentsInLine = 0;
    int timeAfterOneHour = 0;
    multimap<string,char> info;
    
    int setProb = 10;  //*****The probablility that a student will show up each minute. SET BETWEEN 10 and 100*****
    
    for (int i=1; i<=100; i++) //100 day simulation of office hours
    {
        //cout <<"Office hour day " <<i <<endl; //uncomment to show simulation
        int count = 0;
        priority_queue <Student> q1;
        priority_queue <int> q2;
        srand(i);
        
        for (int i=0; i<60; i++) //Simulation of 60 minutes of office hours
        {
            int time = 0;
            int prob = studentProbability();
            //cout << "Minute: " << i <<"\t\t"; //uncomment to show simulation
            
            if (prob <= (100-setProb))
            {
                //cout << "No student" <<"\t\t"; //uncomment to show simulation
            }
            else if (prob > (100-setProb))
            {
                //cout << "One student" <<"\t\t"; //uncomment to show simulation
            }
            
            if (prob > (100-setProb))
            {
                Student a;
                q1.push(a);
                q2.push(i);
                
                info.insert(pair <string, char> (a.name,a.topic)); //inserting info into map
                
                //cout <<"Time needed: " << a.getTimeNeeded() <<"\t\t" <<"Priority: " <<a.getPriority();//uncomment to show simulation
                time = time + a.getTimeNeeded();
                studentsInLine = studentsInLine + 1; //calculate total number of students
                totalOfficeTime = totalOfficeTime + a.getTimeNeeded(); //calculate total office time
                count = count+1;
                
                if ((i + a.getTimeNeeded()) > 59) //calculate overtime
                {
                    timeAfterOneHour = timeAfterOneHour + (((i + a.getTimeNeeded())-1) - 59);
                }
            }
            //cout <<endl; //uncomment to show simulation
        }
        //cout <<"Number of students today: " <<count <<endl <<endl; //uncomment to show simulation
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
    
    
    //MULTIMAP
    //cout<< "Multimap: " <<endl<<endl; //uncomment to show simulation
    multimap <string, char>::iterator itr;
    //cout << "\tStudent\t\tTopic\n"; //uncomment to show simulation
    //cout << "-------------------------" <<endl; //uncomment to show simulation
    for (itr = info.begin(); itr != info.end(); ++itr)
    {
        //cout  <<  "\t" << itr->first <<  "\t" << itr->second << "\n"; //uncomment to show simulation
    }
    //cout << endl; //uncomment to show simulation
    
    //Sort by name
    ofstream namestream;
    namestream.open("mapoutputName.txt");
    
    for (int i = 1; i<=10; i++) {
        int scount = 0;
        int tcount[4] = {0,0,0,0};
        for (itr = info.begin(); itr != info.end(); ++itr)
        {
            if (itr->first == "Student " + to_string(i))
            {
                scount += 1;
            }
            if (itr->first == "Student " + to_string(i) && itr->second == 'A') {
                tcount[0] += 1;
            }
            if (itr->first == "Student " + to_string(i) && itr->second == 'B') {
                tcount[1] += 1;
            }
            if (itr->first == "Student " + to_string(i) && itr->second == 'C') {
                tcount[2] += 1;
            }
            if (itr->first == "Student " + to_string(i) && itr->second == 'D') {
                tcount[3] += 1;
            }
        }
        namestream <<"Student Name: " <<"Student " + to_string(i) <<endl;
        namestream <<"Number of Visits: " <<scount <<endl;
        namestream <<"Topic A: " <<tcount[0] <<" times" <<endl;
        namestream <<"Topic B: " <<tcount[1] <<" times" <<endl;
        namestream <<"Topic C: " <<tcount[2] <<" times" <<endl;
        namestream <<"Topic D: " <<tcount[3] <<" times" <<endl <<endl <<endl;
    }
    namestream.close();
    
    //Sort by topic
    ofstream topicstream;
    topicstream.open("mapoutputTopic.txt");
    
    for (char i = 'A'; i<='D'; i++) {
        int tcount = 0;
        int scount[10] = {0,0,0,0,0,0,0,0,0,0};
        for (itr = info.begin(); itr != info.end(); ++itr)
        {
            if (itr->second == i)
            {
                tcount += 1;
                if (itr->first == "Student 1") {
                    scount[0] += 1;
                }
                if (itr->first == "Student 2") {
                    scount[1] += 1;
                }
                if (itr->first == "Student 3") {
                    scount[2] += 1;
                }
                if (itr->first == "Student 4") {
                    scount[3] += 1;
                }
                if (itr->first == "Student 5") {
                    scount[4] += 1;
                }
                if (itr->first == "Student 6") {
                    scount[5] += 1;
                }
                if (itr->first == "Student 7") {
                    scount[6] += 1;
                }
                if (itr->first == "Student 8") {
                    scount[7] += 1;
                }
                if (itr->first == "Student 9") {
                    scount[8] += 1;
                }
                if (itr->first == "Student 10") {
                    scount[9] += 1;
                }
            }
            
        }
        topicstream <<"Topic: " <<i <<endl;
        topicstream <<"Number of Visits: " <<scount[0]+scount[1]+scount[2]+scount[3]+scount[4]+scount[5]+scount[6]+scount[7]+scount[8]+scount[9] <<endl;
        topicstream <<"Student 1: " <<scount[0] <<" times" <<endl;
        topicstream <<"Student 2: " <<scount[1] <<" times" <<endl;
        topicstream <<"Student 3: " <<scount[2] <<" times" <<endl;
        topicstream <<"Student 4: " <<scount[3] <<" times" <<endl;
        topicstream <<"Student 5: " <<scount[4] <<" times" <<endl;
        topicstream <<"Student 6: " <<scount[5] <<" times" <<endl;
        topicstream <<"Student 7: " <<scount[6] <<" times" <<endl;
        topicstream <<"Student 8: " <<scount[7] <<" times" <<endl;
        topicstream <<"Student 9: " <<scount[8] <<" times" <<endl;
        topicstream <<"Stduent 10: " <<scount[9] <<" times" <<endl <<endl <<endl;
    }
    topicstream.close();
    
    
    return 0;
}


//randomly generated number (1-100).
//if number meets probability requirement, a student will show up
int studentProbability()
{
    return rand() % 100 + 1;
}


