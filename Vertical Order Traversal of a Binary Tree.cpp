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
using namespace std;
struct node
{
    int value;
    int xaxis;
    int yaxis;

    node(int gvalue, int gxaxis, int gyaxis)
    {
        value = gvalue;
        xaxis = gxaxis;
        yaxis = gyaxis;
    }
};
class Solution
{
public:
    vector<node *> treedata;
    static bool sortFunc(node *a, node *b)
    {
        if (a->xaxis == b->xaxis)
        {
            if (a->yaxis == b->yaxis)
            {
                return a->value < b->value;
            }
            return a->yaxis > b->yaxis;
        }
        return a->xaxis < b->xaxis;
    }
    void dfs(TreeNode *root, int x, int y)
    {
        node *d = new node(root->val, x, y);
        treedata.push_back(d);
        if (root->left != nullptr)
        {
            dfs(root->left, x - 1, y - 1);
        }
        if (root->right != nullptr)
        {
            dfs(root->right, x + 1, y - 1);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> result;
        dfs(root, 0, 0);
        sort(treedata.begin(), treedata.end(), sortFunc);
        vector<int> data;
        data.push_back(treedata[0]->value);

        for (int i = 1; i < treedata.size(); i++)
        {
            if (treedata[i]->xaxis != treedata[i - 1]->xaxis)
            {
                result.push_back(data);
                data.clear();
                data.push_back(treedata[i]->value);
            }
            else
            {
                data.push_back(treedata[i]->value);
            }
        }
        result.push_back(data);
        return result;
    }
};