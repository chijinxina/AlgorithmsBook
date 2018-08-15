//
// Created by chijinxin on 18-8-15.
//
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class myList
{
public:
    ListNode* pHead;
    myList()
    {
        pHead = new ListNode(0);
        ListNode* cur = pHead;
        for(int i=1;i<10;i++)
        {
            ListNode* newNode = new ListNode(i);
            cur->next = newNode;
            cur = cur->next;
        }
    }
};

/*
 * 从尾到头打印链表
 */
void printListFromTailToHead(ListNode* head, vector<int> &result)
{
    if(head == NULL) return;
    printListFromTailToHead(head->next, result);
    result.push_back(head->val);
}

int main()
{
    myList ll;
    vector<int> result;
    printListFromTailToHead(ll.pHead, result);
    cout<<result[0]<<endl;
    return 0;
}

