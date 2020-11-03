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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *current = head; 
        
        while(current != nullptr) {
            int swappingVal = current->val;
            int temp ;
            ListNode *start = head;
            while(start != current->next) {
                //cout << "start->val " << start->val << " swap " << swappingVal <<endl;
                if(start->val > swappingVal) {
                    temp = start->val;
                    start->val = swappingVal ;
                    swappingVal = temp;
                }
                start = start->next;
                if(start == current) {
                    current->val = swappingVal;
                }
            }
            current = current->next;
        }
        return head;
    }
};