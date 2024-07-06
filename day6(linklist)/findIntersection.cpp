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
    int length(ListNode* head) {
        if (head == NULL)
            return 0;
        int cnt = 0;
        while (head != NULL) {
            cnt += 1;
            head = head->next;
        }
        return cnt;
    }
    ListNode* getIntersectionNode(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        int len1 = length(l1);
        int len2 = length(l2);
        if (len1 > len2) {
            int diff = len1 - len2;

            for (int i = 0; i < diff; i++) {
                a = a->next;
            }
            while (a != b) {
                a = a->next;
                b = b->next;
            }
            return a;

        } else {
            int diff = len2 - len1;

            for (int i = 0; i < diff; i++) {
                b = b->next;
            }
            while (a != b) {
                a = a->next;
                b = b->next;
            }
            return a;
        }
        return NULL;
    }
};