/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0 ;
    int findSum(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        } else {
            int leftSum = findSum(node->left);
            int rightSum = findSum(node->right);
            
            sum += abs(rightSum-leftSum);
            
            return node->val + leftSum + rightSum ; 
        }
    }
    int findTilt(TreeNode* root) {
        sum = 0 ;
        findSum(root);
        return sum;
    }
};