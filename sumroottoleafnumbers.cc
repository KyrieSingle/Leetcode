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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int result = 0;
        int path = 0;
        helper(result, path, root);
        return result;
    }
private:
    void helper(int& result, int path, TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) {
            result += path*10 + root->val;
            return;
        }
        helper(result, path*10+root->val, root->left);
        helper(result, path*10+root->val, root->right);
    }
};