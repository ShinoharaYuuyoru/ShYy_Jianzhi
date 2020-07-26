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
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int> > paths;
        if (root == nullptr) {
            return paths;
        }

        vector<int> path;
        path.push_back(root->val);
        TreeTraverse(root, expectNumber, path, paths);

        return paths;
    }

private:
    void TreeTraverse(TreeNode* node, int& expectNumber, vector<int> path, vector<vector<int> >& paths) {
        if (node->left == nullptr && node->right == nullptr) {
            int sum = 0;
            for (int i = 0; i < path.size(); i++) {
                sum += path[i];
            }
            if (sum == expectNumber) {
                paths.push_back(path);
            }
        }

        if (node->left != nullptr) {
            path.push_back(node->left->val);
            TreeTraverse(node->left, expectNumber, path, paths);

            if (node->right != nullptr) {
                path.pop_back();

                path.push_back(node->right->val);
                TreeTraverse(node->right, expectNumber, path, paths);
            }
        }
        else if (node->right != nullptr) {
            path.push_back(node->right->val);
            TreeTraverse(node->right, expectNumber, path, paths);
        }
    }
};


// S2: Loop
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int> > paths;
        if (root == nullptr) {
            return paths;
        }

        stack<TreeNode*> S;
        stack<vector<int> > pathStack;
        S.push(root);
        vector<int> nowPath{ root->val };
        pathStack.push(nowPath);

        while (S.empty() == false) {
            TreeNode* curr = S.top();
            nowPath = pathStack.top();
            S.pop();
            pathStack.pop();

            if (curr->left == nullptr && curr->right == nullptr) {
                int sum = 0;
                for (int i = 0; i < nowPath.size(); i++) {
                    sum += nowPath[i];
                }
                if (sum == expectNumber) {
                    paths.push_back(nowPath);
                }
            }

            if (curr->right != nullptr) {
                S.push(curr->right);
                vector<int> nextPath = nowPath;
                nextPath.push_back(curr->right->val);
                pathStack.push(nextPath);
            }
            if (curr->left != nullptr) {
                S.push(curr->left);
                vector<int> nextPath = nowPath;
                nextPath.push_back(curr->left->val);
                pathStack.push(nextPath);
            }
        }

        return paths;
    }
};