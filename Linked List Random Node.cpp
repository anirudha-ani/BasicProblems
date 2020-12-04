/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* a;
    Solution(ListNode* head) {
        srand(time(NULL));
        a = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int size = 1 ; 
        int ans ;
        ListNode* x = a; 
        while(x!= nullptr) {
            if(rand()%size == 0) {
                ans = x->val;
            }
            size++;
            x = x->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */