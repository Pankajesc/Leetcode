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
    bool traversal(TreeNode* root, int curSum, int targetSum) {
        if (!root->left && !root->right) {
            if (targetSum == (curSum + root->val))
                return true;
            return false;    
        }
        if (root->left) {
            if (traversal(root->left, curSum + root->val, targetSum))
                return true;
        }
        if (root->right) {
            if (traversal(root->right, curSum + root->val, targetSum))
                return true;
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int curSum = 0;
        if (!root)
            return false;
        return traversal(root, curSum, targetSum);
    }
};