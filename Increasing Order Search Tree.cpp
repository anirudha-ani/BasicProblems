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
    TreeNode *ans = nullptr;
    TreeNode *temp = ans;
    TreeNode* increasingBST(TreeNode* root) {
        
        if(root->left != nullptr) {
            increasingBST(root->left);
        }
        if(temp == nullptr) {
            temp = new TreeNode;
            ans = temp;
            temp->val = root->val;
        } else {
            temp->right = new TreeNode;
            temp->right->val = root->val;
            temp = temp->right;
        }
        
        if(root->right != nullptr) {
            increasingBST(root->right);
        }
        return ans;
    }
};