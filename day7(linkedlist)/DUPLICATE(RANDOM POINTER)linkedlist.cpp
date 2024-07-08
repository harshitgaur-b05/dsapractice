 #include <bits/stdc++.h>
using namespace std;
//   Definition for singly-linked list.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
  

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // step 1 create a simple copy of normal list in which automatically all
        // random pointer points to NULL
        Node* dummy = new Node(-1);
        Node* tmp = head;
        Node* t2 = dummy;
        while (tmp != NULL) {
            Node* a = new Node(tmp->val);
            t2->next = a;
            t2 = t2->next;
            tmp = tmp->next;
        }
        // step 2 : merge 2 list alternatively
        Node* duplicate = dummy->next;
        // for traversing
        Node* a = head;
        Node* b = duplicate;
        // Node* dummy2 = new Node(-1);
        Node* tmpD = dummy;
        while (b != NULL) {

            tmpD->next = a;
            a = a->next;
            tmpD = tmpD->next;
            tmpD->next = b;
            b = b->next;
            tmpD = tmpD->next;
        }
        // STEP 3: assign random pointers as(our dupli is next node to original and)
        dummy = dummy->next;
        Node* t1 = dummy;

        while (t1 != nullptr) {
            t2 = t1->next;
            if (t1->random != nullptr) {

                t2->random = t1->random->next;
            }
            t1 = t1->next->next;
        }
        // step 4 remove the connection seprately
        Node* d1 = new Node(-1);
        Node* d2 = new Node(-1);
        t1 = d1;
        t2 = d2;
        Node* t = dummy;
        while (t) {
            t1->next = t;
            t = t->next;
            t1 = t1->next;
            t2->next = t;
            t = t->next;
            t2 = t2->next;
        }
        t1->next = NULL;
        t2->next = NULL;
        d1 = d1->next;
        d2 = d2->next;
        return d2;

        return dummy;
    }
};