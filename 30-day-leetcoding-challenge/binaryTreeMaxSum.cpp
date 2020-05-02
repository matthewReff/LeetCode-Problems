/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, bool> used;
    int maxVal = INT_MIN;
    
    int maxPathSum(TreeNode* root)
    {
        getValue(root);
        return maxVal;
    }
    
    int getValue(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        else if(used[root])
            return root->val;
        else
        {
            int leftVal = getValue(root->left);
            int rightVal = getValue(root->right);
            leftVal = max(leftVal, 0);
            rightVal = max(rightVal, 0);
            int pathVal = max(leftVal, rightVal);
            int myVal = root->val + pathVal;
            maxVal = max(maxVal, root->val + leftVal + rightVal);
            root->val = myVal;
            used[root] = true;
            maxVal = max(maxVal, myVal);
            return myVal;
        }
    }
};