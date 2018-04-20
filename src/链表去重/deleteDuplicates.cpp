//
// Created by chijinxin on 18-4-19.
//
#include <iostream>
using namespace std;

/*
 * 有序链表去重
 * 使用两个指针：第一个指针从头扫描原始链表，而第二个指针用于产生新的链表
 * 第二个指针随着第一个指针移动而移动。当第二个指针遇到相同的节点时不移动，其next指向第一个指针的next
 * 若遇到不同值的节点时，随着第一个指针而移动
 */
class list_node
{
public:
    int data;
    list_node* next;
    list_node(int d):data(d),next(NULL){}
};

class myList
{
public:
    list_node* head;
    myList()
    {
        head = new list_node(0);
        list_node* n1 = new list_node(1);
        head->next = n1;
        list_node* n2 = new list_node(1);
        n1->next = n2;
        list_node* n3 = new list_node(1);
        n2->next = n3;
        list_node* n4 = new list_node(1);
        n3->next = n4;
        list_node* n5 = new list_node(2);
        n4->next = n5;
        list_node* n6 = new list_node(4);
        n5->next = n6;
        list_node* n7 = new list_node(5);
        n6->next = n7;
        list_node* n8 = new list_node(5);
        n7->next = n8;
        n8->next = NULL;
    }
};

list_node* deleteDuplicateList(list_node* head)
{
    if(head==NULL || head->next==NULL) return head;
    list_node* low = head->next;
    list_node* fast= head->next;
    while(fast!=NULL)
    {
        if(fast->data == low->data)
        {
            fast = fast->next;
        }
        else
        {
            low->next = fast;
            low = low->next;
            fast= fast->next;
        }
    }
    low->next = NULL;
    return head;
}


int main()
{
    myList ll;

    list_node* current = deleteDuplicateList(ll.head)->next;//ll.head->next;
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
    return 0;
}
