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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;

        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty()) {
            TreeNode* cur = s1.top();
            s1.pop();
            s2.push(cur);

            if(cur->left) {
                s1.push(cur->left);
            }
            if(cur->right) {
                s1.push(cur->right);
            }
        }

        while(!s2.empty()) {
            TreeNode* cur = s2.top();
            result.push_back(cur->val);
            s2.pop();
        }
        return result;
    }
};
