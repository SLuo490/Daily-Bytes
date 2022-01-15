/*
This question is asked by Facebook. Given a linked list and a value n, remove the nth to last node and return the resulting list.

Ex: Given the following linked lists...

1->2->3->null, n = 1, return 1->2->null
1->2->3->null, n = 2, return 1->3->null
1->2->3->null, n = 3, return 2->3->null
*/

#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* slow = head;
  ListNode* fast = head;

  // move fast to the n-1 node
  for (int i = 0; i < n; i++) {
    fast = fast->next;
  }

  // if fast is null then there is only one element
  if (!fast) return head->next;

  // move fast and slow 
  while (fast->next) {
    fast = fast->next;
    slow = slow->next;
  }

  // remove the nth node
  slow->next = slow->next->next;

  return head;
}

int main() {

  return 0; 
}