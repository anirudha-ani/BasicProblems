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
class BSTIterator {
public:
    vector <int> linkedList; 
    int index = 0;
    void DFS (TreeNode* root) {
         if(root->left != nullptr) {
            DFS(root->left);
        }
        //cout << "Pushing = " << root->val << endl;
        linkedList.push_back(root->val);
        // for(int i = 0 ; i < linkedList.size() ; i++) {
        //      cout << ":: " << linkedList[i] << endl;
        //  }
        if(root->right != nullptr) {
            DFS(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
      DFS(root);
    }
    
    int next() {
         // for(int i = 0 ; i < linkedList.size() ; i++) {
         //     cout << ":: " << linkedList[i] << endl;
         // }
        int ans = linkedList[index];
        //cout << "Returning = " << ans << endl;
        index++;
        return ans;
        
    }
    
    bool hasNext() {
        bool ans = index < linkedList.size();
        //cout << "Returning = " << ans << endl;
        return ans;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */