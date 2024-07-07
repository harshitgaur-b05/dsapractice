#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;
        if (head == NULL)
            return false;
        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;
            if (s == f)
                return true;
        }
        return false;
    }
};