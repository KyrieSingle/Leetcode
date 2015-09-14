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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root == p || root == q) return root;
        TreeNode* small = NULL, *big = NULL;
        if(p->val > q->val) {
            small = q;
            big = p;
        } else {
            small = p;
            big = q;
        }
        if(root->val > big->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if(root->val < small->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};
