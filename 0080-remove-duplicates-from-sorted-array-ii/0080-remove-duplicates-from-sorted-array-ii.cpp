class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c=0,n=nums.size();
        for(int i=0;i<n;i++) {
            if(i<n-2 and nums[i]==nums[i+2]) continue;
            else {
                nums[c++]=nums[i];
            }
        }
        return c;
    }
};