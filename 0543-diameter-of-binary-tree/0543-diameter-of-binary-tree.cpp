class Solution {
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = diameterOfBinaryTree(root->left); // Recursive diameter on left subtree
        int right = diameterOfBinaryTree(root->right); // Recursive diameter on right subtree

        int opt1 = height(root->left) + height(root->right); // Diameter through the root
        int opt2 = max(left, right); // Maximum diameter from left and right subtrees

        return max(opt1, opt2);
    }
};
