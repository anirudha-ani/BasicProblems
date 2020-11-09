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
    int ans = 0 ;
    pair<int,int> findMinMax(TreeNode* root) {
        if(root == nullptr) {
            return make_pair(1000000,-1);
        } 
        pair<int,int> leftMinMax = findMinMax(root->left);
        pair<int,int> rightMinMax = findMinMax(root->right);
        int currentMin = min(leftMinMax.first, rightMinMax.first);
        int currentMax = max(leftMinMax.second, rightMinMax.second);
        pair <int, int> returnVal = make_pair(1000000,-1);
        if(currentMin != 1000000) {
            ans = max(ans, abs(root->val - currentMin));
        }
        if(currentMax != -1) {
            ans = max(ans,abs(root->val - currentMax));
        }
        return make_pair(min(currentMin,root->val), max(currentMax, root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        findMinMax(root);
        return ans;
    }
};