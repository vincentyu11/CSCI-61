//
//  main.cpp
//  2
//


#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

//Node of Tree
class TreeNode
{
public:
    TreeNode(char data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    
    char data;
    TreeNode *right;
    TreeNode *left;
};


class StackNode
{
public:
    StackNode(TreeNode *treeNode)
    {
        this->treeNode = treeNode;
        next = NULL;
    }
    
    StackNode *next;
    TreeNode *treeNode;
};

//Tree for input expression
class ExpressionTree
{
public:
    ExpressionTree()
    {
        top = NULL;
    }
    
    void push(TreeNode *ptr)
    {
        if (top == NULL)
        {
            top = new StackNode(ptr);
        }
        else
        {
            StackNode *nextptr = new StackNode(ptr);
            nextptr->next = top;
            top = nextptr;
        }
    }
    
    TreeNode *get()
    {
        return top->treeNode;
    }
    
    TreeNode *pop()
    {
        if (top == NULL)
        {
            cout <<"Underflow" <<endl;
            return 0;
        }
        else
        {
            TreeNode *ptr = top->treeNode;
            top = top->next;
            return ptr;
        }
    }
    
    void insert(char c)
    {
        if (isOperator(c))
        {
            TreeNode *nextptr = new TreeNode(c);
            nextptr->left = pop();
            nextptr->right = pop();
            push(nextptr);
        }
        else if (isdigit(c))
        {
            TreeNode *nextptr = new TreeNode(c);
            push(nextptr);
        }
        else
        {
            cout <<"Incid expression." <<endl;
        }
    }
    
    bool isOperator(char a)
    {
        return a == '+' || a == '-' || a == '*' || a == '/';
    }
    
    int convertToDigit(char a)
    {
        return a - '0';
    }
    
    void createTree(string equation)
    {
        for (int i=equation.length()-1; i>=0; i--) {
            insert(equation[i]);
        }
    }
    
    void postfix()
    {
        postfixArrange(get());
    }
    
    void postfixArrange(TreeNode *ptr)
    {
        if (ptr != NULL)
        {
            postfixArrange(ptr->left);
            postfixArrange(ptr->right);
            cout <<ptr->data;
        }
    }
    
    void infix()
    {
        infixArrange(get());
    }
    
    void infixArrange(TreeNode *ptr)
    {
        if (ptr != NULL)
        {
            infixArrange(ptr->left);
            cout <<ptr->data;
            infixArrange(ptr->right);
        }
    }
    
    void prefix()
    {
        prefixArrange(get());
    }
    
    void prefixArrange(TreeNode *ptr)
    {
        if (ptr != NULL)
        {
            cout <<ptr->data;
            prefixArrange(ptr->left);
            prefixArrange(ptr->right);
        }
    }
private:
    StackNode *top;
};


//MAIN FUNCTION
int main()
{
    string s;
    ExpressionTree tree1;
    cout <<"Enter expression in prefix form: " <<endl;
    cin >> s;
    tree1.createTree(s);
    cout <<"Prefix: " <<endl;
    tree1.prefix();
    cout <<endl;
    cout <<"Infix: " <<endl;
    tree1.infix();
    cout <<endl;
    cout <<"Postfix: " <<endl;
    tree1.postfix();
    cout <<endl <<endl;
    
    return 0;
}
