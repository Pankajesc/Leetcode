#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    array<vector<int>, 1024> bucket;
    void bucket_sort(vector<int>& nums) {
        // 1st round
        for (int x : nums)
            bucket[x&1023].push_back(x);
        int i = 0;
        for (auto &B : bucket) {
            for (auto v : B)
                nums[i++] = v;
            B.clear();
        }
        // 2nd round
        for (int x : nums)
            bucket[x>>10].push_back(x);
        i=0;
        for (auto &B : bucket) {
            for (auto v : B)
                nums[i++] = v;
        //    B.clear();
        }
    }

    void print(auto& c){
        for(int x: c)
            cout<<x<<", ";
        cout<<endl;
    }
    
    int minOperations(vector<int>& nums) {
        fill(bucket.begin(), bucket.end(), vector<int>());
        bucket_sort(nums);
    //    print(nums);
        int ans=0, f=0, prev=-1;
        for(int x:nums){
            if (x==prev) f++;
            else{
                if (f==1) return -1;
                ans+=(f+2)/3;// ceil(f/3)
                f=1;
                prev=x;
            }
        }
        if (f==1) return -1;
        ans+=(f+2)/3;// ceil(f/3)
        return ans;
    }
};