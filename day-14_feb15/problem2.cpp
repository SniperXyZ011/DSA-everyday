// Queue Using Array
// Implement a Queue using an Array. Queries in the Queue are of the following type:
// (i) 1 x   (a query of this type means  pushing 'x' into the queue)
// (ii) 2     (a query of this type means to pop an element from the queue and print the popped element. If the queue is empty then return -1)

// We just have to implement the functions push and pop and the driver code will handle the output.

#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int);
    int pop();
};

void MyQueue ::push(int x)
{
    if (rear < 100005)
    { // Ensure it doesn't exceed array bounds
        arr[rear++] = x;
    }
}
// Function to pop an element from queue and return that element.
int MyQueue ::pop()
{
    if (front == rear)
        return -1; // Queue is empty
    return arr[front++];
    // Your Code
}