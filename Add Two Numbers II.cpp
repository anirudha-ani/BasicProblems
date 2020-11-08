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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack <int> l1s , l2s , result ; 
        ListNode *answer = new ListNode ;
        int ans;
        while(1) {
            //cout << l1-> val << endl;
            l1s.push(l1->val);
            if(l1->next == nullptr) {
                break;
            }
            l1 = l1->next;
        }
        while (1) {
           // cout << l2-> val << endl;
            
            l2s.push(l2->val);
            if(l2->next == nullptr) {
                break;
            }
            l2 = l2->next;
        }
        int carry = 0 ; 
        while(!l1s.empty() || !l2s.empty()) {
            if(l1s.empty()) {
                ans = l2s.top() + carry;
                result.push(ans%10);
                carry = ans / 10;
                l2s.pop();
            } else if (l2s.empty()) {
                ans = l1s.top() + carry;
                result.push(ans%10);
                carry = ans / 10;
                l1s.pop();
            } else {
                ans = l1s.top() + l2s.top() + carry;
                result.push(ans%10);
                carry = ans / 10;
                l1s.pop();
                l2s.pop();
            }
        }
        if(carry!= 0) {
            result.push(carry);
        }
        ListNode *temp = answer;
        while(!result.empty()) {
            cout << result.top() << endl;
            
            temp->val = result.top();
            
            result.pop();
            if(!result.empty()) {
                temp->next = new ListNode;
                temp = temp->next;
            }
        }
        return answer;
    }
};