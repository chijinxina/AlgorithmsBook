//
// Created by chijx on 2020/5/19.
//

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class List {
public:
  List(){
    head = NULL;
    tail = head;
  }
  void push_front(int i) {
    ListNode* newNode = new ListNode(i);
    if(head == NULL) {
      head = newNode;
      tail = newNode;
    }
    newNode->next = head;
    head = newNode;
  }

  void push_back(int i) {
    ListNode* newNode = new ListNode(i);
    if(head == NULL) {
      head = newNode;
      tail = head;
    } else {
      tail->next = newNode;
      tail = tail->next;
    }
  }
  friend ostream& operator << (ostream& out, List& list);
private:
  ListNode* head;
  ListNode* tail;
};

ostream& operator << (ostream& out, List& list) {
  ListNode* cur = list.head;
  for(; cur!=NULL; cur=cur->next){
    out << cur->val << " ";
  }
  return out;
}

int main(){
}