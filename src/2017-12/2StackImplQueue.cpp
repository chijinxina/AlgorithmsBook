//
// Created by chijinxin on 17-12-3.
//
#include <iostream>
#include <stack>

using namespace std;

/*
 * 用两个栈实现队列
 */
template <class T>     //实现模板类的功能
class MyQueue{
public:
    MyQueue(){}     //构造函数
    ~MyQueue(){}    //析构函数
    T& top();       //返回队列顶部元素
    void pop();     //队列的pop()操作
    void push(T ele);   //队列的push()操作
    bool empty();
protected:
    stack<T> s1;    //  两个栈的声明
    stack<T> s2;
};

template <class T>
bool MyQueue<T>::empty() {
    if(s1.empty()&&s2.empty())
        return true;
    else
        return false;
}

template <class T>
T& MyQueue<T>::top() {
    if(this->empty()){
        std::cerr<<"MyQueue is empty!"<<std::endl;
    }
        //return result;
    if(!s2.empty()){
        return s2.top();
    }
    else{
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
}
template <class T>
void MyQueue<T>::pop() {
    if (this->empty()){
        std::cerr<<"MyQueue is empty!"<<std::endl;
        return;
    }
    if(!s2.empty()){
        //result=s2.top();
        s2.pop();
    }
    else{
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        //result = s2.top();
        s2.pop();
    }
}

template <class T>
void MyQueue<T>::push(T ele) {
    s1.push(ele);
}

/*
 * 自定义类 实现MyQueue模板类的测试
 */
class demo{
public:
    int a;
    int b;
    demo(){
        a=0;
        b=0;
    }
    ~demo(){}

    friend ostream& operator<<(ostream& out, demo& dm){ //重载输出流
        out<<"["<<dm.a<<","<<dm.b<<"]";
        return out;
    }
    friend istream& operator>>(istream& in, demo& dm){ //重载输入流
        in>>dm.a>>dm.b;
        return in;
    }
};

/*
 * 主函数两个栈实现队列的demo操作
 */
int main(){
    MyQueue<int> queue;
    cout<<queue.empty()<<endl;
    queue.push(1);
    queue.push(2);


    MyQueue<demo> qu1;
    demo dm;
    cin>>dm;
    cout<<dm<<endl;
    qu1.push(dm);
    cin>>dm;
    cout<<dm<<endl;
    qu1.push(dm);

    cout<<"结果："<<endl;
    cout<<qu1.top()<<endl;
    qu1.pop();
    cout<<qu1.top()<<endl;
    qu1.pop();
    return 0;
}
