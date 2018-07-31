//
// Created by chijinxin on 18-7-31.
//
#include <iostream>
#include <stack>
using namespace std;
/*
 * 找到两个链表的第一个公共节点
 *
 * 1 -> 2 -> 3 ->
 *                 -> 6 -> 7
 *      4 -> 5 ->
 */

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(NULL){}
};

class MyList{
public:
    ListNode* head1;
    ListNode* head2;
    MyList()
    {
        head1 = new ListNode(1);
        ListNode* n2 = new ListNode(2);
        head1->next = n2;
        ListNode* n3 = new ListNode(3);
        n2->next = n3;
        ListNode* n6 = new ListNode(6);
        n3->next = n6;
        ListNode* n7 = new ListNode(7);
        n6->next = n7;
        n7->next = NULL;
        head2 = new ListNode(4);
        ListNode* n5 = new ListNode(5);
        head2->next = n5;
        n5->next = n6;
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

ListNode* FindFirstCommonNode(ListNode* l1, ListNode* l2)
{
    stack<ListNode*> st1;
    stack<ListNode*> st2;
    while(l1!=NULL)
    {
        st1.push(l1);
        l1 = l1->next;
    }
    while(l2!=NULL)
    {
        st2.push(l2);
        l2 = l2->next;
    }
    ListNode* temp;
    while(st1.top()==st2.top())
    {
        temp = st1.top();
        st1.pop();
        st2.pop();
    }
    return temp;
}

int main()
{
    MyList l;
    cout<<"List1:"<<endl;
   // PrintList(l.head1);
    cout<<endl<<"List2:"<<endl;
   // PrintList(l.head2);

    ListNode* res = FindFirstCommonNode(l.head1,l.head2);

    cout<<endl<<"Common Node = "<<res->val<<endl;

    return 0;
}
