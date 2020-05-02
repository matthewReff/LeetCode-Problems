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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
     TreeNode* root = new TreeNode(preorder[0]);

     for (int i = 1; i < preorder.size(); i++)
     {
         int current = preorder[i];
         TreeNode* currentNode = root;
         TreeNode* nodeToAdd = new TreeNode(current);
         while (true)
         {
             if (current < currentNode->val)
             {
                 if (currentNode->left == nullptr)
                 {
                     currentNode->left = nodeToAdd;
                     break;
                 }
                 else
                     currentNode = currentNode->left;
             }
             else
             {
                 if (currentNode->right == nullptr)
                 {
                     currentNode->right = nodeToAdd;
                     break;
                 }
                 else
                     currentNode = currentNode->right;
             }
         }
     }

    return root;
}  
};