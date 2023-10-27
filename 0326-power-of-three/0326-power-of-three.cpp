class Solution {
public:
    bool isPowerOfThree(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        if(n == 0) return false;

        while(n % 3 == 0)
        {
            n = n / 3;
        }

        return n == 1;
    }
};