/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(!root) return result;
        vector<int> path;
        helper(root, result, path, sum);
        return result;
    }
private:
    void helper(TreeNode* root, vector<vector<int>>& result, vector<int>& path, int sum) {
        if(!root) return;
        path.push_back(root->val);
        if(sum == root->val && !root->left && !root->right) {
            result.push_back(path);
            return;
        }
        int count = sum - root->val;
        if(root->left) {
            helper(root->left, result, path, count);
            path.pop_back();
        }
        if(root->right) {
            helper(root->right, result, path, count);
            path.pop_back();
        }
    }
};
