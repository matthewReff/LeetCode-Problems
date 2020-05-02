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
    int diameterOfBinaryTree(TreeNode* root) {
        int height;
        if(root == nullptr)
            return 0;
        else
            return helper(root, &height) - 1;
    }
    
    int helper(TreeNode* root, int* height)
    {
        int left = 0;
        int right = 0;
        
        int leftVal = 0;
        int rightVal = 0;
        
        if(root == nullptr)
        {
            *height = 0;
            return 0;
        }
        
        leftVal = helper(root->left, &left);
        rightVal = helper(root->right, &right);
        
        *height = max(left, right) + 1;
        
        return max(left + right + 1, max(leftVal, rightVal)); 
    }
};