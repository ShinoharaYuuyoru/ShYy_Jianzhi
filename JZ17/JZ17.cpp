/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/


// Traverse two tree to compare
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        vector<int> tree1;
        treeTraversal(pRoot1, tree1);

        vector<int> tree2;
        treeTraversal(pRoot2, tree2);
        if ((tree1.empty() | tree2.empty()) == true) {
            return false;
        }

        auto result = search(tree1.begin(), tree1.end(), tree2.begin(), tree2.end());
        if (result == tree1.end()) {
            return false;
        }
        else {
            return true;
        }
    }

private:
    void treeTraversal(TreeNode* node, vector<int>& tree) {
        if (node == nullptr) {
            return;
        }

        tree.push_back(node->val);        // Pre-order
        treeTraversal(node->left, tree);
        //tree.push_back(node->val);        // In-order
        treeTraversal(node->right, tree);
        //tree.push_back(node->val);        // Post-order
    }
};


// Recursive
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }

        return this->dfs(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }

private:
    bool dfs(TreeNode* r1, TreeNode* r2) {
        if (r2 == nullptr) {
            return true;
        }
        if (r1 == nullptr) {
            return false;
        }

        return r1->val == r2->val && dfs(r1->left, r2->left) && dfs(r1->right, r2->right);
    }
};