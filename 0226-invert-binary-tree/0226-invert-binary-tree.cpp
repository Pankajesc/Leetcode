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
    TreeNode* helper(TreeNode* root) {
        if(root == NULL)
            return NULL;

        if(root->left == NULL && root->right == NULL)
            return NULL;

        if(root->right == NULL) {
            root->right = root->left;
            root->left = NULL;
        }
        else if(root->left == NULL) {
            root->left = root->right;
            root->right = NULL;
        }


        else {
            TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        }

        helper(root->left);
        helper(root->right);

        return root;
        
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return root;

        
        TreeNode* temp = helper(root);

        return temp;
    }
};