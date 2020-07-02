/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        TreeNode* root = nullptr;

        root = this->BNTreeBuilder(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);

        return root;
    }

private:
    TreeNode* BNTreeBuilder(vector<int>& pre, int preStart, int preEnd, vector<int>& vin, int inStart, int inEnd) {
        /*
            preorder[preStart] is the root of the (sub)tree.
            Find the root value in inorder[inStart, inEnd] to divide left and right tree.
        */
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        int rootVal = pre[preStart];

        auto divideItr = find(vin.begin() + inStart, vin.begin() + inEnd + 1, rootVal);
        int leftTreeNodeLength = divideItr - vin.begin() - inStart;

        TreeNode* root = new TreeNode(rootVal);
        root->left = BNTreeBuilder(pre, preStart + 1, preStart + leftTreeNodeLength, vin, inStart, inStart + leftTreeNodeLength - 1);
        root->right = BNTreeBuilder(pre, preStart + leftTreeNodeLength + 1, preEnd, vin, inStart + leftTreeNodeLength + 1, inEnd);

        return root;
    }
};