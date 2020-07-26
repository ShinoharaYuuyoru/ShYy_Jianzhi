/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> print;
        if (root == nullptr) {
            return print;
        }

        queue<TreeNode*> Q;
        Q.push(root);

        while (Q.empty() == false) {
            TreeNode* curr = Q.front();
            Q.pop();
            if (curr == nullptr) {
                continue;
            }

            print.push_back(curr->val);

            Q.push(curr->left);
            Q.push(curr->right);
        }

        return print;
    }
};