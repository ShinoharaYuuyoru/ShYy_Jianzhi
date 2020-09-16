class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = treeDepth(pRoot);

        return isBalanced;
    }

    int treeDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftTreeDepth = treeDepth(node->left);
        int rightTreeDepth = treeDepth(node->right);

        int depthDiff = abs(leftTreeDepth - rightTreeDepth);
        if (depthDiff <= 1) {
            isBalanced = true;
        }
        else {
            isBalanced = false;
        }

        return max(leftTreeDepth, rightTreeDepth) + 1;
    }

private:
    bool isBalanced = true;
};