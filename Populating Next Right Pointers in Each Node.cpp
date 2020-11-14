/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    queue <Node*> s1;
    queue <Node*> s2; 
    void DFS() {
        while(!s1.empty() || !s2.empty()) {
            if(!s1.empty()) {
                while(!s1.empty()) {
                    Node* current = s1.front();
                    s1.pop();
                    if(current == NULL) {
                        continue;
                    }
                    if(s1.empty()!= true) {
                        current->next = s1.front();
                    } else {
                        current->next = NULL;
                    }
                    if(current->left != NULL) {
                        s2.push(current->left);
                    }
                    if(current->right != NULL) {
                        s2.push(current->right);
                    }
                }
            }
            else if(!s2.empty()) {
                while(!s2.empty()) {
                    Node* current = s2.front();
                    s2.pop();
                    if(current == NULL) {
                        continue;
                    }
                    if(s2.empty()!= true) {
                        current->next = s2.front();
                    } else {
                        current->next = NULL;
                    }
                    if(current->left != NULL) {
                        s1.push(current->left);
                    }
                    if(current->right != NULL) {
                        s1.push(current->right);
                    }
                }
            }
        }
    }
    Node* connect(Node* root) {
        s1.push(root);
        
        DFS();
        return root;
    }
};


//Memory efficient solution 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) {
            return root;
        }
        if(root->left&&root->right) {
            root->left->next = root->right;
        }
        if(root->next && root->right && root->next->left) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};