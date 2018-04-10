//
// Created by chijinxin on 18-4-10.
//
#include <iostream>
#include <stack>
using namespace std;

class myStack{
public:
    myStack(){}
    void push(int e);
    int pop();
    int top();
    int min();
private:
    stack<int> ele_;
    stack<int> min_;
};

void myStack::push(int e)
{
    ele_.push(e);
    if(min_.empty() || e <= min_.top())
    {
        min_.push(e);
    }
}

int myStack::pop()
{
    int top = ele_.top();
    ele_.pop();
    if(top == min_.top())
    {
        min_.pop();
    }
    return top;
}

int myStack::top()
{
    return ele_.top();
}

int myStack::min()
{
    return min_.top();
}

int main()
{
    myStack ss;
    ss.push(11);
    ss.push(12);
    ss.push(1);
    ss.push(10);
    cout<<ss.min()<<endl;
    ss.pop();
    cout<<ss.min()<<endl;
    ss.pop();
    cout<<ss.min()<<endl;
    return 0;
}
