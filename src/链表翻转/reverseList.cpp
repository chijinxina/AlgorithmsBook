//
// Created by chijinxin on 18-4-9.
//
#include <iostream>
#include <memory>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class myList{
public:
    ListNode* pHead;
    myList(int a[],int n)
    {
        pHead = new ListNode(a[0]);
        ListNode* current = pHead;
        for(int i=1;i<n;i++)
        {
            ListNode* newNode = new ListNode(a[i]);
            current->next = newNode;
            current = current->next;
        }
    }

};


//ListNode* ReverseList(ListNode* pHead) {
//    ListNode* Current = pHead;
//    ListNode* Next = Current->next;
//    pHead->next = NULL;
//    while(Next!=NULL)
//    {
//        ListNode* temp = Current;
//        Current = Next;
//        Next = Next->next;
//        Current->next = temp;
//    }
//    return Current;
//}

ListNode* ReverseList(ListNode* pHead)
{
    if(pHead==NULL || pHead->next==NULL)
        return pHead;

    ListNode* temp = pHead;
    ListNode* pre = NULL;

    while(temp != NULL)
    {
        temp = pHead->next;
        pHead->next = pre;
        pre = pHead;
        pHead = temp;
    }
    return pre;
}

//递归法翻转链表
ListNode* ReverseList_digui(ListNode* pHead, ListNode* newHead)
{
    if(pHead==NULL || pHead->next==NULL)
    {
        newHead = pHead;
        return pHead;
    }
    //递归调用
    ListNode* pre = ReverseList_digui(pHead->next, newHead);
    pre->next = pHead;  //翻转指针指向
    pHead->next = NULL;
    return pHead;       //返回新的链表头
}

int main()
{
    int a[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    myList c(a,12);
    cout<<"翻转之前："<<endl;
    ListNode* current = c.pHead;
    while(current!=NULL)
    {
        cout<<current->val<<" ";
        current = current->next;
    }

    //reverseList(c);
    ListNode* newHead = NULL;
    ListNode* phead = ReverseList_digui(c.pHead,newHead);
 //   ListNode* phead = ReverseList(c.pHead);
//
    cout<<endl<<"翻转之后："<<endl;
    current = phead;
    while(current!=NULL)
    {
        cout<<current->val<<" ";
        current = current->next;
    }
}
