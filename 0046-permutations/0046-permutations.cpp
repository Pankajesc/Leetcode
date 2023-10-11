class Solution {
public:
    #define DPSolver ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void permutations(const vector<int> &nums, vector<vector<int>> &res, vector<bool> &taken, vector<int> per, const int sz, int lvl)
{
    if (lvl == sz)
    {
        res.push_back(per);
        return;
    }
    for (int i = 0; i < sz; i++)
    {
        if (!taken[i])
        {
            taken[i] = true;
            per.push_back(nums[i]);
            permutations(nums, res, taken, per, sz, lvl + 1);
            per.pop_back();
            taken[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    DPSolver;
    vector<vector<int>> res;
    vector<bool> taken(nums.size());
    vector<int> per;
    permutations(nums, res, taken, per, nums.size(), 0);
    return res;
}

    vector<vector<int>> permuteUsingBuiltInFunction(vector<int>& nums) {
        // to get all the possible permutations.
        sort(nums.begin(), nums.end());
        
        // creating a place in the memory to store the results in. 
        vector<vector<int>> permus; 

        // generating all possible combinations. 
        do {
            permus.push_back(nums); 
        } while (next_permutation(nums.begin(), nums.end()));

        // returning the result. 
        return permus; 
    }

};