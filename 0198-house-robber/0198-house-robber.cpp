#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();

class Solution {
public:
    Solution(){
        DPSolver; 
    }
    int rob(vector<int>& nums) {
        int sz = nums.size(); 
        if(sz < 3) {
            return *max_element(nums.begin(), nums.end());
        }
        else{
            vector<int> money (sz, 0);
            money[0] = nums[0];
            money[1] = nums[1];
            money[2] = nums[2] + nums[0];
            for(int i = 3; i < sz; i++)
                money[i] = max(nums[i] + money[i-2], nums[i] + money[i-3]);
            
            return *max_element(money.begin(), money.end());
        }
    }
};