
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_set>
using namespace std;

void wordSearch(vector<vector<char>> mainVec, unordered_set<string> uSet, int maxWordLength);

int main() {
    int horizontal;
    int vertical;
    cout <<"Enter horizontal puzzle size: "<<endl;
    cin >>horizontal;
    cout <<"Enter vertical puzzle size: " <<endl;
    cin >>vertical;
    
    int hcount = 0;
    int vcount = 0;
    
    ifstream instream;
    instream.open("puzzle.txt");
    char tempc;
    vector<vector<char>> mainVec;
    vector<char> tempVec;
    //puts puzzle into double vector
    while (instream.get(tempc))
    {
        while (hcount!=horizontal) {
            if (tempc == ' '){
                break;
            }
            if (tempc == '\n'){
                break;
            }
            if (tempc != ' ' && tempc != '\n')
            {
                tempVec.push_back(tempc);
                hcount = hcount+1;
                break;
            }
        }
        if (hcount == horizontal) {
            while (vcount!=vertical) {
                mainVec.push_back(tempVec);
                tempVec.clear();
                vcount = vcount+1;
                hcount = 0;
                break;
            }
        }
    }
    
    instream.close();

    //outputs puzzle
    /*for (int i=0; i<mainVec.size(); i++)
    {
        for (int j=0; j<mainVec[i].size(); j++)
        {
            cout<<mainVec[i][j] <<' ';
        }
        cout <<'\n';
    }*/
    
    
    //put words into unordered set
    ifstream instream2;
    instream2.open("words.txt");
    unordered_set<string> uSet;
    string temps;
    while (getline(instream2, temps))
    {
        uSet.insert(temps);
    }
    instream2.close();
    
    //find max word length in dictionary
    int maxlength = 0;
    unordered_set<string>::iterator itr;
    for (itr=uSet.begin(); itr!=uSet.end(); itr++) {
        string s = *itr;
        if(s.size()>maxlength){
            maxlength = s.size();
        }
    }
    
    //how to iterate through unordered set
    /*unordered_set<string>::iterator itr;
    for (itr=uSet.begin(); itr!=uSet.end(); itr++) {
        cout <<*itr;
    }*/
    
    cout <<endl;
    
    //ouput words that are found
    wordSearch(mainVec, uSet, maxlength);
    
    cout <<endl;
    return 0;
}

void wordSearch(vector<vector<char>> mainVec, unordered_set<string> uSet, int maxWordLength)
{
    vector<string> foundWords;
    string temp = "";
    unordered_set<string>::iterator itr;
    int startLeftCoord;
    int startRightCoord;
    int endLeftCoord;
    int endRightCoord;
    vector<int> vecSLC;
    vector<int> vecSRC;
    vector<int> vecELC;
    vector<int> vecERC;
    
    
    //left direction
    for (int i=0; i<mainVec.size(); i++)
    {
        for (int j=0; j<mainVec[i].size(); j++)
        {
            if (j-5>=0)
            {
                for (int x=5; x<maxWordLength; x++)
                {
                    if (j-x>=0)
                    {
                        for (int y=0; y<x+1; y++)
                        {
                            //cout <<mainVec[i][j-y];
                            temp = temp + string(1,mainVec[i][j-y]);
                            
                            startLeftCoord = i;
                            startRightCoord = j;
                            endLeftCoord = i;
                            endRightCoord = j-y;
                        }
                        //cout <<endl;
                        //cout << temp;
                        for (itr=uSet.begin(); itr!=uSet.end(); itr++) {
                            if (*itr == temp) {
                                foundWords.push_back(temp);
                                vecSLC.push_back(startLeftCoord);
                                vecSRC.push_back(startRightCoord);
                                vecELC.push_back(endLeftCoord);
                                vecERC.push_back(endRightCoord);
                            }
                        }
                        temp = "";
                        //cout <<endl;
                    }
                }
            }
        }
    }
    //right direction
    for (int i=0; i<mainVec.size(); i++)
    {
        for (int j=0; j<mainVec[i].size(); j++)
        {
            if (j+5<mainVec.size())
            {
                for (int x=5; x<maxWordLength; x++)
                {
                    if (j+x<mainVec.size())
                    {
                        for (int y=0; y<x+1; y++)
                        {
                            //cout <<mainVec[i][j+y];
                            temp = temp + string(1,mainVec[i][j+y]);
                            
                            startLeftCoord = i;
                            startRightCoord = j;
                            endLeftCoord = i;
                            endRightCoord = j+y;
                        }
                        //cout <<endl;
                        //cout << temp;
                        for (itr=uSet.begin(); itr!=uSet.end(); itr++) {
                            if (*itr == temp) {
                                foundWords.push_back(temp);
                                vecSLC.push_back(startLeftCoord);
                                vecSRC.push_back(startRightCoord);
                                vecELC.push_back(endLeftCoord);
                                vecERC.push_back(endRightCoord);
                            }
                        }
                        temp = "";
                        //cout <<endl;
                    }
                }
            }
        }
    }
    //down direction
    for (int i=0; i<mainVec.size(); i++)
    {
        for (int j=0; j<mainVec[i].size(); j++)
        {
            if (i+5<mainVec.size())
            {
                for (int x=5; x<maxWordLength; x++)
                {
                    if (i+x<mainVec.size())
                    {
                        for (int y=0; y<x+1; y++)
                        {
                            //cout <<mainVec[i+y][j];
                            temp = temp + string(1,mainVec[i+y][j]);
                            
                            startLeftCoord = i;
                            startRightCoord = j;
                            endLeftCoord = i+y;
                            endRightCoord = j;
                        }
                        //cout <<endl;
                        //cout << temp;
                        for (itr=uSet.begin(); itr!=uSet.end(); itr++) {
                            if (*itr == temp) {
                                foundWords.push_back(temp);
                                vecSLC.push_back(startLeftCoord);
                                vecSRC.push_back(startRightCoord);
                                vecELC.push_back(endLeftCoord);
                                vecERC.push_back(endRightCoord);
                            }
                        }
                        temp = "";
                        //cout <<endl;
                    }
                }
            }
        }
    }
    //up direction
    for (int i=0; i<mainVec.size(); i++)
    {
        for (int j=0; j<mainVec[i].size(); j++)
        {
            if (i-5>=0)
            {
                for (int x=5; x<maxWordLength; x++)
                {
                    if (i-x>=0)
                    {
                        for (int y=0; y<x+1; y++)
                        {
                            //cout <<mainVec[i-y][j];
                            temp = temp + string(1,mainVec[i-y][j]);
                            
                            startLeftCoord = i;
                            startRightCoord = j;
                            endLeftCoord = i-y;
                            endRightCoord = j;
                        }
                        //cout <<endl;
                        //cout << temp;
                        for (itr=uSet.begin(); itr!=uSet.end(); itr++) {
                            if (*itr == temp) {
                                foundWords.push_back(temp);
                                vecSLC.push_back(startLeftCoord);
                                vecSRC.push_back(startRightCoord);
                                vecELC.push_back(endLeftCoord);
                                vecERC.push_back(endRightCoord);
                            }
                        }
                        temp = "";
                        //cout <<endl;
                    }
                }
            }
        }
    }
    //up right diagonal direction
    for (int i=0; i<mainVec.size(); i++)
    {
        for (int j=0; j<mainVec[i].size(); j++)
        {
            if ((i-5>=0) && (j+5 < mainVec.size()))
            {
                for (int x=5; x<maxWordLength; x++)
                {
                    if ((i-x>=0) && (j+x<mainVec.size()))
                    {
                        for (int y=0; y<x+1; y++)
                        {
                            //cout <<mainVec[i-y][j+y];
                            temp = temp + string(1,mainVec[i-y][j+y]);
                            
                            startLeftCoord = i;
                            startRightCoord = j;
                            endLeftCoord = i-y;
                            endRightCoord = j+y;
                        }
                        //cout <<endl;
                        //cout << temp;
                        for (itr=uSet.begin(); itr!=uSet.end(); itr++) {
                            if (*itr == temp) {
                                foundWords.push_back(temp);
                                vecSLC.push_back(startLeftCoord);
                                vecSRC.push_back(startRightCoord);
                                vecELC.push_back(endLeftCoord);
                                vecERC.push_back(endRightCoord);
                            }
                        }
                        temp = "";
                        //cout <<endl;
                    }
                }
            }
        }
    }
    //down right diagonal direction
    for (int i=0; i<mainVec.size(); i++)
    {
        for (int j=0; j<mainVec[i].size(); j++)
        {
            if ((i+5<mainVec.size()) && (j+5 < mainVec.size()))
            {
                for (int x=5; x<maxWordLength; x++)
                {
                    if ((i+x<mainVec.size()) && (j+x<mainVec.size()))
                    {
                        for (int y=0; y<x+1; y++)
                        {
                            //cout <<mainVec[i+y][j+y];
                            temp = temp + string(1,mainVec[i+y][j+y]);
                            
                            startLeftCoord = i;
                            startRightCoord = j;
                            endLeftCoord = i+y;
                            endRightCoord = j+y;
                        }
                        //cout <<endl;
                        //cout << temp;
                        for (itr=uSet.begin(); itr!=uSet.end(); itr++) {
                            if (*itr == temp) {
                                foundWords.push_back(temp);
                                vecSLC.push_back(startLeftCoord);
                                vecSRC.push_back(startRightCoord);
                                vecELC.push_back(endLeftCoord);
                                vecERC.push_back(endRightCoord);
                            }
                        }
                        temp = "";
                        //cout <<endl;
                    }
                }
            }
        }
    }
    //up left diagonal direction
    for (int i=0; i<mainVec.size(); i++)
    {
        for (int j=0; j<mainVec[i].size(); j++)
        {
            if ((i-5>=0) && (j-5>=0))
            {
                for (int x=5; x<maxWordLength; x++)
                {
                    if ((i-x>=0) && (j-x>=0))
                    {
                        for (int y=0; y<x+1; y++)
                        {
                            //cout <<mainVec[i-y][j-y];
                            temp = temp + string(1,mainVec[i-y][j-y]);
                            
                            startLeftCoord = i;
                            startRightCoord = j;
                            endLeftCoord = i-y;
                            endRightCoord = j-y;
                        }
                        //cout <<endl;
                        //cout << temp;
                        for (itr=uSet.begin(); itr!=uSet.end(); itr++) {
                            if (*itr == temp) {
                                foundWords.push_back(temp);
                                vecSLC.push_back(startLeftCoord);
                                vecSRC.push_back(startRightCoord);
                                vecELC.push_back(endLeftCoord);
                                vecERC.push_back(endRightCoord);
                            }
                        }
                        temp = "";
                        //cout <<endl;
                    }
                }
            }
        }
    }
    //down left diagonal direction
    for (int i=0; i<mainVec.size(); i++)
    {
        for (int j=0; j<mainVec[i].size(); j++)
        {
            if ((i+5<mainVec.size()) && (j-5>=0))
            {
                for (int x=5; x<maxWordLength; x++)
                {
                    if ((i+x<mainVec.size()) && (j-x>=0))
                    {
                        for (int y=0; y<x+1; y++)
                        {
                            //cout <<mainVec[i+y][j-y];
                            temp = temp + string(1,mainVec[i+y][j-y]);
                            
                            startLeftCoord = i;
                            startRightCoord = j;
                            endLeftCoord = i+y;
                            endRightCoord = j-y;
                        }
                        //cout <<endl;
                        //cout << temp;
                        for (itr=uSet.begin(); itr!=uSet.end(); itr++) {
                            if (*itr == temp) {
                                foundWords.push_back(temp);
                                vecSLC.push_back(startLeftCoord);
                                vecSRC.push_back(startRightCoord);
                                vecELC.push_back(endLeftCoord);
                                vecERC.push_back(endRightCoord);
                            }
                        }
                        temp = "";
                        //cout <<endl;
                    }
                }
            }
        }
    }
    cout <<endl;
    cout <<"Found words: " <<endl;
    for (int i=0; i<foundWords.size(); i++)
    {
        cout<<foundWords[i] <<" from " <<"("<<vecSLC[i]<<","<<vecSRC[i]<<")"<<" to "<<"("<<vecELC[i]<<","<<vecERC[i]<<")";
        cout<<endl;
    }
}

