class Solution {
public:
    queue <Node*> s1;
    queue <Node*> s2; 
    void BFS() {
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
        
        BFS();
        return root;
    }
};