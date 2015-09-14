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
    bool isBalanced(TreeNode* root) {
        if (NULL==root) return true;

        if(abs(getHeight(root->left)-getHeight(root->right)) > 1)
            return false;
        else 
            return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int getHeight(TreeNode* root) {
        if (NULL==root) return 0;
        int height = 0;
        
        height = max(getHeight(root->left), getHeight(root->right))+1;

        return height;
    } 
};
