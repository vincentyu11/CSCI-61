//
//  main.cpp
//  1
//
//  Created by Vincent Yu on 5/2/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include <iostream>
#include "bintree.h"
using namespace std;

void heapify(binary_tree_node<int> *rootptr, int depth)
{
    for (int i = 0; i<depth; i++)
    {
        if (rootptr == NULL)
        {
            return;
        }
        binary_tree_node<int> *temp = new binary_tree_node<int>;
        temp = rootptr->left();
        if (rootptr->left() == NULL)
        {
            return;
        }
        else if (temp->data() > rootptr->data())
        {
            int swap = temp->data();
            temp->set_data(rootptr->data());
            rootptr->set_data(swap);
        }
        heapify(temp, depth);
        temp = rootptr->right();
        if (rootptr->right() == NULL)
        {
            return;
        }
        else if (temp->data() > rootptr->data())
        {
            int swap = temp->data();
            temp->set_data(rootptr->data());
            rootptr->set_data(swap);
        }
        heapify(temp, depth);
    }
}



int main()
{
    int depth = 3;
    cout <<"Binary tree node, unheapified: " <<endl <<endl;
    //DEPTH 1
    binary_tree_node<int> *rootptr = new binary_tree_node<int> (1);
    //DEPTH 2
    rootptr->set_left(new binary_tree_node<int> (50));
    rootptr->set_right(new binary_tree_node<int> (12));
    //DEPTH 3
    rootptr->left()->set_left(new binary_tree_node<int> (512));
    rootptr->left()->set_right(new binary_tree_node<int> (62));
    rootptr->right()->set_left(new binary_tree_node<int> (18));
    rootptr->right()->set_right(new binary_tree_node<int> (100));
    //DEPTH 4
    rootptr->left()->left()->set_left(new binary_tree_node<int> (161));
    rootptr->left()->left()->set_right(new binary_tree_node<int> (123));
    rootptr->left()->right()->set_left(new binary_tree_node<int> (2));
    rootptr->left()->right()->set_right(new binary_tree_node<int> (9));
    rootptr->right()->left()->set_left(new binary_tree_node<int> (120));
    rootptr->right()->left()->set_right(new binary_tree_node<int> (1701));
    rootptr->right()->right()->set_left(new binary_tree_node<int> (5717));
    rootptr->right()->right()->set_right(new binary_tree_node<int> (210));
    
    print(rootptr, 0);
    
    heapify(rootptr, depth);
    
    cout <<endl <<"Binary tree node, heapified: " <<endl <<endl;
    print(rootptr, 0);
    
    cout <<endl;
    return 0;
}
