/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

// 1. In-order traversal
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr) {
            return nullptr;
        }

        vector<TreeNode*> sorted;

        // Loop in-order traversal
        stack<TreeNode*> s;
        TreeNode* curr = pRootOfTree;
        while (curr != nullptr || s.empty() == false) {
            if (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                curr = s.top();
                cout << curr->val << " ";
                sorted.push_back(curr);
                s.pop();
                curr = curr->right;
            }
        }

        for (int i = 0; i < sorted.size(); i++) {
            TreeNode* curr = sorted[i];
            if (i == 0) {
                curr->left = nullptr;
                if (i + 1 < sorted.size()) {
                    curr->right = sorted[i + 1];
                }
                else {
                    curr->right = nullptr;
                }
            }
            else if (i == sorted.size() - 1) {
                curr->right = nullptr;
                if (i - 1 < 0) {
                    curr->left = nullptr;
                }
                else {
                    curr->left = sorted[i - 1];
                }
            }
            else {
                curr->left = sorted[i - 1];
                curr->right = sorted[i + 1];
            }
        }

        return sorted[0];
    }
};


// 2. Optimization
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr) {
            return nullptr;
        }

        Convert(pRootOfTree->right);
        if (pre != nullptr) {
            pRootOfTree->right = pre;
            pre->left = pRootOfTree;
        }
        pre = pRootOfTree;
        Convert(pRootOfTree->left);

        return pre;
    }

private:
    TreeNode* pre = nullptr;
};