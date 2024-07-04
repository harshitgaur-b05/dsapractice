#include <bits/stdc++.h>
using namespace std;
//take constant space
class Solution {
public:
    // slow fast linked list approach
    // 1 we move slow by 1 and fast by 2 untill they meet first(collision)
    // 2 now after collision we (st fast to st) and  move both pointer one by
    // one their collision will be or duplicate
    int findDuplicate(vector<int>& a) {
        int s = a[0];
        int f = a[0];

        do {
            s = a[s];    // move slow by 1
            f = a[a[f]]; // move fast by 2
        } while (s != f);
        
        f = a[0]; // move to st (f_fast pointer)
        while (s != f) {
            s = a[s]; // move both by 1 in next aur second collision
            f = a[f];
        }
        return s;
    }
};
//other is by making an unordered map 
// that is easy 