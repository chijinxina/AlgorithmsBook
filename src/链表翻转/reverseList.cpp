//
// Created by chijinxin on 18-4-9.
//
#include <iostream>
#include <memory>

using namespace std;

class list_node{
public:
    list_node():data(0),next(NULL){};
    list_node(int d, list_node* n):data(d),next(n){};
    int data;
    list_node* next;
};

class myList{
public:
    myList(int a[],int n)
    {
        head = new list_node(0,NULL);
        list_node* current = head;
        for(int i=0;i<n;i++)
        {
            list_node* newNode = new list_node(a[i],NULL);
            current->next = newNode;
            current = current->next;
        }
    }

    list_node* head;
};

void reverseList(myList &c)
{
    list_node* Current = c.head->next;
    list_node* Next = Current->next;
    c.head->next = NULL;
    Current->next = NULL;
    while(Next!=NULL)
    {
        list_node* temp = Current;
        Current = Next;
        Next = Next->next;
        Current->next = temp;
    }
    c.head->next = Current;
}

list_node* ReverseList(list_node* pHead) {
    list_node* temp = pHead;
    list_node* pre = NULL;
    while(temp != NULL){
        temp = pHead->next;
        pHead->next = pre;
        pre = pHead;
        pHead = temp;
    }
    return pre;
}

int main()
{
    int a[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    myList c(a,12);
    cout<<"翻转之前："<<endl;
    list_node* current = c.head;
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current = current->next;
    }

    //reverseList(c);
    list_node* phead = ReverseList(c.head);
//
    cout<<endl<<"翻转之后："<<endl;
    current = phead;
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
}
