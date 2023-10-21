class Solution {
public:
    #define DPSolver                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
bool isValid(TreeNode *root, long leftBound, long rightBound, bool &res)
{
    if (!root)
        return true;
    if (root->val < rightBound && root->val > leftBound)
    {
        bool left = isValid(root->left, leftBound, root->val, res);
        if (res && left)
            bool right = isValid(root->right, root->val, rightBound, res);
        else
            res = false;
    }
    else
        res = false;
    return res; 
}

bool isValidBST(TreeNode *root)
{
    DPSolver;
    bool res = true ;
    isValid(root,  LLONG_MIN, LLONG_MAX,  res); 
    return res; 
}


// incorrect approach
// bool validNode(pair<int, int> left, pair<int, int> right, int rootVal)
// {
//     return (rootVal > left.first && rootVal > left.second && rootVal < right.second && rootVal < right.first);
// }

// pair<int, int> traverse(TreeNode *root, bool leftBool, bool &valid)
// {
//     if (!valid)
//         return {INT_MAX, INT_MIN};

//     if (!root->left && !root->right)
//         return {root->val, root->val};
//     pair<int, int> left;
//     pair<int, int> right;
//     if (root->left)
//         left = traverse(root->left, true, valid);
//     else
//         left = {INT_MIN, INT_MIN};
//     if (root->right)
//         right = traverse(root->right, false, valid);
//     else
//         right = {INT_MAX, INT_MAX};
//     if (valid && validNode(left, right, root->val))
//     {
//         if (leftBool)
//             return {root->val, root->right ? max(right.first, right.second) : root->val};
//         else
//             return {root->val, root->left ? min(left.first, left.second) : root->val};
//     }
//     else
//     {
//         valid = false;
//         return {INT_MAX, INT_MIN};
//     }
// }

// bool isValidBST(TreeNode *root)
// {
//     DPSolver;
//     bool valid = true;
//     traverse(root, false, valid);
//     return valid;
// }

};