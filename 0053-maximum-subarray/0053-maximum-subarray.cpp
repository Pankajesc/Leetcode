class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        //base case
        if(start == end){
            return nums[start];
        }

        int mid = start + (end-start)/2;
        int leftSum = solve(nums, start, mid);
        int rightSum = solve(nums, mid+1, end);

        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
        int leftBorderSum = 0, rightBorderSum = 0;
        for(int i=mid; i >= start; i--){
            leftBorderSum += nums[i];
            if(leftBorderSum > maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
            }
        }
        for(int i=mid+1; i <= end; i++){
            rightBorderSum += nums[i];
            if(rightBorderSum > maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
            }
        }

        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(crossBorderSum, max(leftSum, rightSum));
    }


    int maxSubArray(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        return solve(nums, start, end);
    }
};