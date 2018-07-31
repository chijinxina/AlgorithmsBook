//
// Created by chijinxin on 18-7-31.
//
#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(NULL){}
};

class MyList{
public:
    ListNode* head;
    MyList(int n)
    {
        head = new ListNode(0);
        ListNode* current = head;
        for(int i=1;i<n;i++)
        {
            ListNode* temp = new ListNode(i);
            current->next = temp;
            current = current->next;
        }
    }
};

void PrintList(ListNode* head)
{
    ListNode* current = head;
    while(current!=NULL)
    {
        cout<<current->val<<" ";
        current = current->next;
    }
}

ListNode* ReverseList(ListNode* head)
{
    if(head==NULL || head->next==NULL) return head;
    ListNode* Curr = head;
    ListNode* Prev = NULL;
    ListNode* temp = NULL;
    while(Curr!=NULL)
    {
        temp = Curr;
        Curr = Curr->next;
        temp->next = Prev;
        Prev = temp;
    }
    return Prev;
}

int main()
{
    MyList l(10);
    cout<<"翻转前："<<endl;
    PrintList(l.head);
    cout<<endl<<"翻转后："<<endl;
    ListNode* head = ReverseList(l.head);
    PrintList(head);
    return 0;
}
