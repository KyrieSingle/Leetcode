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
    int minDepth(TreeNode* root) {
        if(NULL == root) return 0;
        int left = minDepth(root->left) + 1;
        int right = minDepth(root->right) + 1;
        if(root->left == NULL)
            return right;
        else if(root->right == NULL)
            return left;
        else
            return left > right ? right : left;
    }
};
