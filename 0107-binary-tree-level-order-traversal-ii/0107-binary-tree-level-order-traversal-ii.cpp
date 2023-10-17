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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)
        {
            return v;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            vector<int> level;
            for(int i=0;i<s;i++)
            {
                TreeNode* current=q.front();
                q.pop();
                level.push_back(current->val);
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
            v.push_back(level);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};