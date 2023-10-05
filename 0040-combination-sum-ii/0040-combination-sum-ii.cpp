class Solution {
private:
    void backtrack(vector<vector<int>>& res, vector<int>& curr, int curr_sum, vector<int>& candidates, int target, int start) {
        if(curr_sum > target) return;
        if(curr_sum == target) {
            res.push_back(curr);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue; // Skip duplicates
            curr.push_back(candidates[i]);
            curr_sum += candidates[i];
            backtrack(res, curr, curr_sum, candidates, target, i+1);
            curr.pop_back();
            curr_sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(res, curr, 0, candidates, target, 0);
        return res;
    }
};