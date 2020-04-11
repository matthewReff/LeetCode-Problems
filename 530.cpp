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
    int getMinimumDifference(TreeNode* root) {
        set<int> vals;
        populate(root, vals);
        int minDiff = 999999;
        auto current = vals.begin();
        auto next = vals.begin();
        next++;
        while(next != vals.end())
        {
            int thisDiff = (*next) - (*current);
            cerr << thisDiff << "\n";
            if (thisDiff < minDiff)
            {
                minDiff = thisDiff;
            }
            current++;
            next++;
        }
        return minDiff;
    }
    
    void populate(TreeNode* root, set<int> &vals)
    {
        if(root != nullptr)
        {
            vals.insert(root->val);
            populate(root->left, vals);
            populate(root->right, vals);
        }
    }
};