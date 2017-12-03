//
// Created by chijinxin on 17-12-3.
//
#include <iostream>
#include <stack>
using namespace std;

/*
 * 带最小值的栈
 */
template <class T>
class MinValStack{
public:
    MinValStack(){};    //构造函数
    ~MinValStack(){};   //析构函数
    bool empty();  //判断栈是否为空
    T& top();
    void pop();
    void push(T ele);
    T& min();
protected:
    stack<T> S; //栈元素
    stack<T> Min;   //储存栈最小值
};

template <class T>
bool MinValStack<T>::empty() {
    return S.empty();
}

template <class T>
T& MinValStack<T>::top() {
    return S.top();
}

template <class T>
void MinValStack<T>::pop() {
    if(S.top() == Min.top()){
        Min.pop();
    }
    S.pop();
}

template <class T>
void MinValStack<T>::push(T ele) {
    S.push(ele);
    if(Min.empty() || ele<=Min.top()) Min.push(ele);
}

template <class T>
T& MinValStack<T>::min() {
    return Min.top();
}

int main(){
    MinValStack<int> s;
    s.push(1);
    s.push(2);
    s.push(0);
    s.pop();
    s.pop();
    cout<<s.min()<<endl;
    return 0;
}