//
// Created by chijinxin on 18-4-19.
//
#include <iostream>
#include <unordered_map>
using namespace std;

/*
 * 求单链表环的长度
 * 1.先判断是否有环： 快慢指针 快指针是慢指针的两倍 ，如果快指针已经到了链表尾部它们还没有相遇 则没有环
 * 否则他们相遇的点肯定位于环内
 *
 * 2.然后计算环的长度 由相遇节点 往后走肯定能在遇到该节点
 *
 * 3.利用Hash表判断环的起点
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
        list_node* n1 = new list_node(3);
        head->next = n1;
        list_node* n2 = new list_node(8);
        n1->next = n2;
        list_node* n3 = new list_node(7);
        n2->next = n3;
        list_node* n4 = new list_node(1);
        n3->next = n4;
        list_node* n5 = new list_node(2);
        n4->next = n5;
        list_node* n6 = new list_node(3);
        n5->next = n6;
        list_node* n7 = new list_node(4);
        n6->next = n7;
        list_node* n8 = new list_node(5);
        n7->next = n8;
        n8->next = n4;
    }
};


int getLength(list_node* head)
{
    list_node* current = head->next;
    int count = 1;
    while(current!=head)
    {
        count++;
        current = current->next;
    }
    return count;
}

/*
 * 计算环的长度
 */
int getCircleLength(list_node* head)
{
    if(head->next==NULL) return 0;
    list_node* low = head;
    list_node* fast = head->next->next;
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
    {
        if(low == fast)
        {
            return getLength(low);
        }
        else
        {
            low = low->next;
            fast= fast->next->next;
        }
    }
    return 0;
}

/*
 * 寻找环的起点
 */
list_node* getStartCirclePoint(list_node* head)
{
    if(head->next==NULL) return NULL;
    unordered_map<list_node*,int> hashmap;
    list_node* low = head;
    list_node* fast = head->next->next;
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
    {
        if(low == fast)
        {
            list_node* current = head->next;
            while(current!=NULL)
            {
                if(hashmap.find(current)!=hashmap.end()) return current;
                else
                {
                    hashmap.insert(make_pair(current,1));
                    current=current->next;
                }
            }
        }
        else
        {
            low = low->next;
            fast= fast->next->next;
        }
    }
    return NULL;
}


int main()
{
    myList ll;
    cout<<"Circle Length = "<<getCircleLength(ll.head)<<endl;
    cout<<"Circle Start  = "<<getStartCirclePoint(ll.head)->data<<endl;
    return 0;
}
