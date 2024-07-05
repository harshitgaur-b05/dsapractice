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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode * pre, *nxt, *curr;
        pre = NULL;
        nxt = NULL;
        curr = head;
        while (curr != NULL) {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        return pre;
    }
};