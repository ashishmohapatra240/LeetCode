class Solution {
private:
    unordered_set<int> to_delete_set;
    vector<TreeNode*> ans;

    TreeNode* dfs(TreeNode* root) {
        if (!root)
            return nullptr;
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        if (to_delete_set.count(root->val)) {
            if (root->left)
                ans.push_back(root->left);
            if (root->right)
                ans.push_back(root->right);
            return nullptr;
        }
        return root;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root,
                                    vector<int>& to_delete) {
        for (int val : to_delete) {
            to_delete_set.insert(val);
        }
        if (dfs(root)) {
            ans.push_back(root);
        }
        return ans;
    }
};