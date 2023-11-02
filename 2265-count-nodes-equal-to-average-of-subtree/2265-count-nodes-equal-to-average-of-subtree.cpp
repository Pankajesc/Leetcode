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
    signed count=0;
    signed long long inOrder(TreeNode* node){
        if (node==NULL) return 0;
        signed long long sum_n_L=inOrder(node->left);
        signed long long sum_n=node->val+(1L<<32);
        signed long long sum_n_R=inOrder(node->right);
        sum_n+=sum_n_L+sum_n_R;
        if ((sum_n&0xffffffff)/(sum_n>>32 )==node->val) count++;
    //    cout<<node->val<<" n="<<i<<" sum="<<sum<<endl;
        return sum_n;
    }

    int averageOfSubtree(TreeNode* root) {
        inOrder(root);
        return count;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();