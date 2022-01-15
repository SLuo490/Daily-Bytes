/*
This question is asked by Apple. Given two sorted linked lists, merge them together in ascending order and return a reference to the merged list

Ex: Given the following lists...

list1 = 1->2->3, list2 = 4->5->6->null, return 1->2->3->4->5->6->null
list1 = 1->3->5, list2 = 2->4->6->null, return 1->2->3->4->5->6->null
list1 = 4->4->7, list2 = 1->5->6->null, return 1->4->4->5->6->7->null
*/

#include <iostream> 
#include <algorithm>

using namespace std; 

struct ListNode {
  int val; 
  ListNode *next; 
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  // edge case:
  if (!list1) return list2;
  if (!list2) return list1;

  if (!list1 && !list2) return nullptr;

  // create a new list
  ListNode* res = new ListNode(-1);
  ListNode* ptr = res;

  while (list1 != nullptr && list2 != nullptr) {
    if (list1->val <= list2->val) {
      ptr->next = list1;
      list1 = list1->next;
    } else {
      ptr->next = list2;
      list2 = list2->next;
    }
    ptr = ptr->next;
  }

  // add the rest of list1 or list2
  if (list1 == nullptr) {
    ptr->next = list2;
  } else {
    ptr->next = list1;
  }

  return res->next;
}

int main() {

  return 0; 
}