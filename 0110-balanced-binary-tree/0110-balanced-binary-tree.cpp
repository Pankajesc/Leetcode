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
    pair<int, bool> temp(TreeNode* &root) {
        if (!root)
            return make_pair(-1, true);//returning pair to the return call

        pair<int, bool> l = temp(root->left);
        pair<int, bool> r = temp(root->right);
        //if both left subtree and right tree is true its valid so we return the height of given tree and true
        if (abs(l.first - r.first)  < 2  and l.second and r.second) {
            return make_pair(1 + max(l.first, r.first), true);
        } else {
            return make_pair(1 + max(l.first, r.first), false);
        }
    }
    
    bool isBalanced(TreeNode* root) {
        return temp(root).second;
    }
};
