
#include <iostream>
#include "graph.h"
#include <vector>
#include <list>
using namespace std;

int main() {

    graph a;
    a.add_vertex();
    a.add_vertex();
    a.add_vertex();
    a.add_vertex();
    a.add_vertex();
    a.add_vertex();
    a.add_vertex();
    a.add_edge(0, 1);
    a.add_edge(0, 2);
    a.add_edge(1, 3);
    a.add_edge(2, 6);
    a.add_edge(3, 4);
    a.add_edge(4, 5);
    a.add_edge(2, 4);
    cout << a <<endl;
    
    int x = 0;
    int y = 4;
    
    vector<int> vecS = a.shortest_path(x, y);
    //vector<int> vecL = a.longest_path(x, y);
    vector<int>::iterator itr;

    cout<< "Shortest path from " <<x <<" to "<<y <<":" <<endl;
    for (itr = vecS.begin(); itr!=vecS.end(); itr++) {
        cout << *itr <<" ";
    }
    cout <<endl <<endl;
    
    cout<< "Longest path from " <<x <<" to "<<y <<":" <<endl;
    a.longest_path(x, y);
    /*for (itr = vecL.begin(); itr!=vecL.end(); itr++) {
        cout << *itr <<" ";
    }*/
    cout <<endl <<endl;

    /*
    list<size_t> l = a.neighbors(3);
    for (auto v: l){
        cout <<v<<" ";
    }*/
    

    cout <<endl;
    
    return 0;
}
