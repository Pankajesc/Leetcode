class Solution {
public:
    // time/space: O(log(min(m, n)))/O(1)
    int rangeBitwiseAnd(int left, int right) {
        int m = left, n = right;
        int shift = 0;
        while (m != n) {
            m >>= 1, n >>= 1;
            shift++;
        }
        return (m << shift);
    }
};