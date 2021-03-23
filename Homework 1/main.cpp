//
// main.cpp
// navid cs61 hw#1


#include <iostream>
#include <stack>
#include <string>
using namespace std;

//INFIX TO PREFIX
//infix must be input with full parentheses
//for example: ((3+2)*5)
string infixToPrefix(string infix) {
    stack<string> stack1;
    stack<string> stack2;
    int length = infix.size();
    
    for(int i=0; i<length; i++) {
        if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            stack2.push(string(1,infix[i]));
        }
        else if(infix[i] == ')') {
            string first, second, oper;
            first = stack1.top();
            stack1.pop();
            second = stack1.top();
            stack1.pop();
            oper = stack2.top();
            stack2.pop();
            string temp = oper + " " + second + " " + first;
            stack1.push(temp);
        }
        else if(infix[i] != '(') {
            string value = "";
            while(infix[i] != '+' || infix[i] != '-' || infix[i] != '*' || infix[i] != '/' || infix[i] != ')') {
                value = value + infix[i];
                i++;
                if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == ')') {
                    i--;
                    break;
                }
            }
            stack1.push(value);
        }
    }
    return stack1.top();
}


//PREFIX TO INFIX
//prefix must be input with spaces between every operator and value
//for example: * + 8 9 7
string prefixToInfix(string prefix) {
    stack<string> stack1;
    int length = prefix.size();
    
    for(int i = length-1; i>=0; i--) {
        if(prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/')
        {
            string first, second;
            while(stack1.top() == " ") {
                stack1.pop();
            }
            while(!stack1.empty()) {
                if(stack1.top() == " ") {
                    break;
                }
                first = first+stack1.top();
                stack1.pop();
            }
            while(stack1.top() == " ") {
                stack1.pop();
            }
            while(!stack1.empty()) {
                if(stack1.top() == " ") {
                    break;
                }
                second = second+stack1.top();
                stack1.pop();
            }
            string temp = "(" + first + prefix[i] + second + ")";
            stack1.push(temp);
        }
        else {
            stack1.push(string(1, prefix[i]));
        }
    }
    return stack1.top();
}

//MAIN
int main()
{
    string infix = "(((12-61)*6)/2)";
    cout <<"Infix notation: " <<infix <<endl;
    cout <<"Prefix notation: "<<infixToPrefix(infix) <<endl <<endl;
    string prefix = "+ / 225 531 + 13 51";
    cout <<"Prefix notation: " <<prefix <<endl;
    cout <<"Infix notation: " <<prefixToInfix(prefix) <<endl <<endl;

    return 0;
}
