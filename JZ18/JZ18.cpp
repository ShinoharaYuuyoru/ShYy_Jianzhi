/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/


// S1: Recursion
class Solution {
public:
    void Mirror(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return;
        }

        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;

        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};


// S2: Loop (BFS)
class Solution {
public:
    void Mirror(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return;
        }

        queue<TreeNode*> Q;
        Q.push(pRoot);

        while (Q.empty() == false) {
            TreeNode* curr = Q.front();
            Q.pop();
            if (curr == nullptr) {
                continue;
            }

            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            Q.push(curr->left);
            Q.push(curr->right);
        }
    }
};