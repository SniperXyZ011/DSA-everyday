// Implement stack using array
// Write a program to implement a Stack using Array. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. The push() method takes one argument, an integer 'x' to be pushed into the stack and pop() which returns an integer present at the top and popped out from the stack. If the stack is empty then return -1 from the pop() method.

// Note: The input is given in form of queries. Since there are two operations push() and pop(), there is two types of queries as described below:
// (i) 1 x   (a query of this type means  pushing 'x' into the stack)
// (ii) 2     (a query of this type means to pop an element from the stack and print the popped element)
// Input contains separated by space and as described above. 

#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};

void MyStack ::push(int x) {
    top++;
    arr[top%1000] = x;
    // Your Code
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    if(top != -1){
        return arr[top--];
    }
    return -1;
    // Your Code
}