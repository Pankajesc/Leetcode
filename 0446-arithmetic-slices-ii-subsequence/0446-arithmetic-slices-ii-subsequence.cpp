class Solution {
public:
    // O(n^2) time and space
    // dynamic programming; hashtable; counting;
    int numberOfArithmeticSlices(vector<int>& nums) {
        /* for nums[i], table[i][d] is total sequence len of d in [0, i] */
        int n = nums.size();
        vector<unordered_map<long, int>> table(n);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long d = (long)nums[i] - nums[j];
                /*
                if (d > INT_MAX || d <= INT_MIN) {
                    continue;
                }
                */

                /* not directly accessing table[j][d], but judge first, will help save space */
                if (table[j].find(d) != table[j].end()) {
                    ans += table[j][d];
                    table[i][d] += table[j][d];
                }

                /* the starting pair (j, i) */
                table[i][d] += 1;
            }
        }
        
        return ans;
    }
};