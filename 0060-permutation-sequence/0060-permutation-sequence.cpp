class Solution {
public:
    vector<int> factorial;
    string Permutation(set<int>& nums, int n, int k) {
        if (n == 1) 
            return to_string(*nums.begin());

        int index =k/ factorial[n-1];
        k %= factorial[n-1];

        auto it = nums.begin();
        advance(it, index); // Move iterator to the index
        int num = *it;
        nums.erase(it);

        return to_string(num) + Permutation(nums, n-1, k);
    }

    string getPermutation(int n, int k) {
        factorial.assign(n, 1);
        for (int i = 1; i < n; i++) {
            factorial[i]= i*factorial[i-1];
        }

        set<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.insert(i);
        }
        --k; // Adjust k to 0-based index
        return Permutation(nums, n, k);
    }
};