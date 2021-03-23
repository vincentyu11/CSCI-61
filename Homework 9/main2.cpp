#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "graph.h"
using namespace std;

void linkNodes(const string s, graph &g, vector<string> vec, vector<string> &used);
bool inVector(vector<string> vec, string s);

int main()
{
    vector<string> vec;
    graph g;
    string inputString;
    ifstream instream;
    instream.open("knuth.txt");
    while (instream >> inputString)
    {
        vec.push_back(inputString);
        g.add_vertex();
    }
    
    vector<int>::iterator itr;
    vector<string>::iterator itr1;
    
    vector<string> vec1 = {"black","tears","small","stone","angel","amino","amigo"};
    vector<string> vec2 = {"white","smile","giant","money","devil","right","signs"};
    vector<string> used;
    
    //SET WHICH WORD YOU WANT TO SEARCH
    const int vecnumber = 0;
    const string s = vec1[vecnumber];
    const string s1 = vec2[vecnumber];
    
    //SEARCH
    linkNodes(s, g, vec, used);
    
    //PRINT USED VECTOR
    for (itr1 = used.begin(); itr1 != used.end(); itr1++)
    {
        //cout << *itr1 <<endl;
    }
    cout <<endl <<endl;
    
    //PRINT OUT PATH
    size_t pos = find(vec.begin(),vec.end(), s) - vec.begin();
    size_t pos1 = find(vec.begin(),vec.end(), s1) - vec.begin();
    vector<int> vecPos = g.shortest_path(pos, pos1);
    cout <<"Path from " <<s <<" to " <<s1 <<":" <<endl;
    for (itr = vecPos.begin(); itr != vecPos.end(); itr++)
    {
        cout <<vec[*itr] <<endl;
    }
    
    return 0;
}


void linkNodes(const string s, graph &g, vector<string> vec, vector<string> &used)
{
    if (inVector(vec, s))
    {
        const string alphabet = "abcdefghijklmnopqrstuvwxyz";
        
        size_t pos = find(vec.begin(),vec.end(), s) - vec.begin();
        
        //REPLACE 1ST LETTER
        for (int y=0; y<26; y++)
        {
            string temp = string(1,alphabet[y]) + string(1,s[1]) + string(1,s[2]) + string(1,s[3]) + string(1,s[4]);
            size_t pos1 = find(vec.begin(),vec.end(),temp) - vec.begin();
            if (inVector(vec, temp) == true) {
                g.add_edge(pos, pos1);
            }
            if ((inVector(vec, temp) == true) && (inVector(used, temp) == false))
            {
                //cout <<temp<<endl;
                
                    used.push_back(temp);
                    linkNodes(temp, g, vec, used);
                
            }
        }
        
        //REPLACE 2ND LETTER
        for (int y=0; y<26; y++)
        {
            string temp = string(1,s[0]) + string(1,alphabet[y]) + string(1,s[2]) + string(1,s[3]) + string(1,s[4]);
            size_t pos1 = find(vec.begin(),vec.end(),temp) - vec.begin();
            if (inVector(vec, temp)) {
                g.add_edge(pos, pos1);
            }
            if (inVector(vec, temp) && !inVector(used, temp))
            {
                //cout <<temp<<endl;
             
                    used.push_back(temp);
                    linkNodes(temp, g, vec, used);
                
            }
        }
        
        //REPLACE 3RD LETTER
        for (int y=0; y<26; y++)
        {
            string temp = string(1,s[0]) + string(1,s[1]) + string(1,alphabet[y]) + string(1,s[3]) + string(1,s[4]);
            size_t pos1 = find(vec.begin(),vec.end(),temp) - vec.begin();
            if (inVector(vec, temp)) {
                g.add_edge(pos, pos1);
            }
            if (inVector(vec, temp) && !inVector(used, temp))
            {
                //cout <<temp<<endl;
                
                    used.push_back(temp);
                    linkNodes(temp, g, vec, used);
                
            }
        }
        
        //REPLACE 4TH LETTER
        for (int y=0; y<26; y++)
        {
            string temp = string(1,s[0]) + string(1,s[1]) + string(1,s[2]) + string(1,alphabet[y]) + string(1,s[4]);
            size_t pos1 = find(vec.begin(),vec.end(),temp) - vec.begin();
            if (inVector(vec, temp)) {
                g.add_edge(pos, pos1);
            }
            if (inVector(vec, temp) && !inVector(used, temp))
            {
                //cout <<temp<<endl;
                
                    used.push_back(temp);
                    linkNodes(temp, g, vec, used);
                
            }
        }
        
        //REPLACE 5TH LETTER
        for (int y=0; y<26; y++)
        {
            string temp = string(1,s[0]) + string(1,s[1]) + string(1,s[2]) + string(1,s[3]) + string(1,alphabet[y]);
            size_t pos1 = find(vec.begin(),vec.end(),temp) - vec.begin();
            if (inVector(vec, temp)) {
                g.add_edge(pos, pos1);
            }
            if (inVector(vec, temp) && !inVector(used, temp))
            {
                //cout <<temp<<endl;
                    used.push_back(temp);
                    linkNodes(temp, g, vec, used);
            
            }
        }
    }
    
    else
    {
        return;
    }
}


bool inVector(vector<string> vec, string s)
{
    bool use = false;
    if (find(vec.begin(),vec.end(),s) != vec.end())
    {
        use = true;
    }
    return use;
}

