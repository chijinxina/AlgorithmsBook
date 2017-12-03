//
// Created by chijinxin on 17-12-3.
//
#include <iostream>
#include <queue>

/*
 * 用两个队列实现栈
 */
template <class T>
class MyStack{
public:
    MyStack(){  //构造函数
        pushtmp = &q1;
        tmp = &q2;
        t = &q1;
    };
    ~MyStack(){ //析构函数
        pushtmp = NULL;
        tmp = NULL;
        t = NULL;
    };
    bool empty();   //  判断为空
    void push(T ele);   //压栈操作
    T& top();   //取栈顶元素
    void pop(); //出栈操作
protected:
    std::queue<T>* pushtmp; //压栈操作队列指针
    std::queue<T>* tmp; //中转队列指针
    std::queue<T>* t;   //临时指针 用于交换pushtmp指针和tmp指针的临时指针
    std::queue<T> q1;   //队列1
    std::queue<T> q2;   //队列2
};

template <class T>
bool MyStack<T>::empty() {
    if(q1.empty()&&q2.empty())
        return true;
    else
        return false;
}

template <class T>
void MyStack<T>::push(T ele) {
    pushtmp->push(ele);
}

template <class T>
T& MyStack<T>::top() {
    int num = pushtmp->size();
    //std::queue<T>* result = pushtmp;
    for(int i=1;i<num;i++){
        tmp->push(pushtmp->front());
        pushtmp->pop();
    }
//    t = pushtmp;
//    pushtmp = tmp;
//    tmp = t;
    return pushtmp->front();
}

template <class T>
void MyStack<T>::pop() {
    int num = pushtmp->size();
    if(num==0){
        std::cerr<<"栈空！"<<std::endl;
        return;
    }

    for(int i=1;i<num;i++){
        tmp->push(pushtmp->front());
        pushtmp->pop();
    }
    pushtmp->pop();
    t = pushtmp;
    pushtmp = tmp;
    tmp = t;
}

int main(){
    MyStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout<<s.top()<<std::endl;
    s.pop();
    std::cout<<s.top()<<std::endl;
    s.push(20);
    s.push(4);
    std::cout<<s.top()<<std::endl;
    s.pop();
    std::cout<<s.top()<<std::endl;
    s.pop();
    std::cout<<s.top()<<std::endl;
    s.pop();
    s.push(10);
    s.pop();
    std::cout<<s.top()<<std::endl;
    return 0;
}