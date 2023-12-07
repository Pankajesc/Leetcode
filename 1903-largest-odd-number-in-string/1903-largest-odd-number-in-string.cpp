class Solution {
public:
    // time/space: O(n)/O(1)
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; i--) {
            if (isOdd(num[i])) return num.substr(0, i + 1);
        }
        return "";
    }
private:
    bool isOdd(const char& digit) {
        return (((digit - '0') & 1) == 1);
    }
};