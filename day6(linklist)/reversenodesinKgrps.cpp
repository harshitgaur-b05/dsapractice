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
 

ListNode* reverse(ListNode* head) {
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

ListNode* rettkthnode(ListNode* temp, int k) {
    k -= 1;
    while (temp != NULL && k > 0) {
        k--;
        temp = temp->next;
    }
    return temp;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    ListNode* pre = NULL;
    ListNode* nex = NULL;
    int count = 0;
    
    // Check if there are at least k nodes left to reverse
    ListNode* checkLength = head;
    int length = 0;
    while (checkLength != NULL) {
        length++;
        checkLength = checkLength->next;
    }
    if (length < k) return head; // If remaining nodes are less than k, no need to reverse

    while (temp != NULL) {
        ListNode* kthnode = rettkthnode(temp, k);
        if (kthnode == NULL) {
            if (pre) pre->next = temp;
            break;
        }
        nex = kthnode->next;
        kthnode->next = NULL;
        ListNode* reversed = reverse(temp);
        if (temp == head) {
            head = reversed;
        } else {
            pre->next = reversed;
        }
        pre = temp;
        temp = nex;
        count++;
    }
    return head;

}
};