/*
This question is asked by Microsoft. Given a linked list, containing unique numbers, return whether or not it has a cycle.
Note: a cycle is a circular arrangement (i.e. one node points back to a previous node)

Ex: Given the following linked lists...

1->2->3->1 -> true (3 points back to 1)
1->2->3 -> false
1->1 true (1 points to itself)
*/

#include <iostream> 

using namespace std; 

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL){}
};

bool hasCycle(ListNode* head) {
  ListNode* fast = head;
  ListNode* slow = head;

  while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;

    if (slow == fast) {
      return true;
    }
  }
  return false;
}

int main() {
  return 0; 
}