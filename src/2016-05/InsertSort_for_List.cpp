#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* init(int a[],int num){
    ListNode* head = new ListNode(a[0]);
    ListNode* end = head;
    for (int i=1;i<num;i++){
        ListNode* temp = new ListNode(a[i]);
        end->next = temp;
        end = temp;
    }
    return head;
}

void bianli(ListNode* head){
    ListNode* current = head;
    while(current!=NULL){
        cout<<current->val<<endl;
        current=current->next;
    }
}

typedef bool (*func)(int,int);
ListNode *insertionSortList(ListNode *head,func compare) {
    ListNode* unfirst1 = NULL;   //定义一个无序节点指针
    ListNode* first = NULL;   //用来表示有序链表的节点指针
    ListNode* inNode = NULL;    //找到可以插入的节点
    ListNode* front = NULL;     //用来保存指向可以插入节点位置的指针
    if(head==NULL) return NULL;
    if(head->next==NULL) return head;
    first = head;   //有序链表头指针
    unfirst1 = head->next; //无序链表头指针
    first->next = NULL;  //断开有序链表和无序链表之间的连接
    while(unfirst1){
        inNode = first;
        ListNode* next = unfirst1->next;
        unfirst1->next = NULL;

        //if(unfirst1->val<=inNode->val){
        if(compare(unfirst1->val,inNode->val)){
            ListNode* temp = first;
            first = unfirst1;
            first->next = temp;
        }
        else {
            while (inNode) {
                //if (unfirst1->val > inNode->val && inNode != NULL) {
                if (!compare(unfirst1->val,inNode->val)&& inNode != NULL) {
                    front = inNode;
                    inNode = inNode->next;
                } else break;
            }
            front->next = unfirst1;
            unfirst1->next = inNode;
        }
        unfirst1 = next;
    }
    return first;
}

bool compare(int a,int b){
    if (a<=b)
        return true;
    else return false;
}

int main(){
    int a[6]={5,4,6,7,1,2};
    ListNode* head = init(a,6);
    ListNode* que = insertionSortList(head,compare);
    // bianli(head);
    bianli(que);
}