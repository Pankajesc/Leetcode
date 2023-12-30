const int N = 2005;
class Solution {
public:
    long long int answers[N];
    int isPalin[N][N];

    bool isPalindrome(string &s, int i, int j) {
        if (isPalin[i][j] > -1) return isPalin[i][j];
        int ci = i, cj = j;
        while (i < j  &&  i < s.size()  &&  i >= 0  &&  j < s.size()  &&  j >= 0) {
            if (isPalin[i][j] > -1) return isPalin[ci][cj] = isPalin[i][j];
            if (s[i] != s[j]) return isPalin[ci][cj] = false;
            i++;
            j--;
        }
        return isPalin[ci][cj] = true;
    }

    long long int helper(int i, string &s) {
        if (i >= s.size()  ||  isPalindrome(s, i, s.size() - 1)) return 0;
        if (answers[i] > -1) return answers[i];
        long long int ans = INT_MAX;
        for (int k = 0; k + i < s.size(); k++) {
            if (isPalindrome(s, i, k + i)) {
                ans = min(ans, helper(i + k + 1, s));
            }
        }

        return answers[i] = 1LL + ans;
    }

    int minCut(string s) {
        memset(answers, -1, sizeof(answers));
        memset(isPalin, -1, sizeof(isPalin));
        int a = helper(0, s);
        return a;
    }
};