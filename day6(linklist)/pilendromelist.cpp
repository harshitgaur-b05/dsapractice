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
        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* Next = NULL;
        while (curr != NULL) {
            Next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = Next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        // if 1 half is equal to 2 half of a linked list can say pilendonme

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* nh = reverseList(slow->next);
        ListNode* a = head;
        ListNode* b = nh;
        while (b != NULL) {
            if (a->val != b->val) {
                return false;
            }
            a = a->next;
            b = b->next;
        }
        return true;
    }
};