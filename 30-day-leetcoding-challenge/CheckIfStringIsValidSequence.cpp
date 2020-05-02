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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return navigation(root, arr, 0);
    }
    
    bool navigation(TreeNode* current, vector<int>& arr, int index)
    {
        if(current == nullptr || current->val != arr[index])
            return false;
        
        if(index == arr.size() - 1)
            return current->left == nullptr && current->right == nullptr;
        
        return navigation(current->left, arr, index+1) || navigation(current->right, arr, index+1);
    }
};