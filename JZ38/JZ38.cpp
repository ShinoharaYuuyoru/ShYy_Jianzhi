/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/


// S1: Level traversal
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == nullptr) {
            return 0;
        }

        queue<TreeNode*> Q;
        int depth = 0;
        Q.push(pRoot);
        int count = 0;
        int nextLevelNodeNum = 1;
        while (Q.empty() == false) {
            TreeNode* cur = Q.front();
            Q.pop();
            count++;
            if (cur->left != nullptr) {
                Q.push(cur->left);
            }
            if (cur->right != nullptr) {
                Q.push(cur->right);
            }
            if (count == nextLevelNodeNum) {
                depth++;
                count = 0;
                nextLevelNodeNum = Q.size();
            }
        }

        return depth;
    }
};


// S2: Divide and Conquer
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == nullptr) {
            return 0;
        }

        int leftVal = TreeDepth(pRoot->left);
        int rightVal = TreeDepth(pRoot->right);
        return max(leftVal, rightVal) + 1;
    }
};


