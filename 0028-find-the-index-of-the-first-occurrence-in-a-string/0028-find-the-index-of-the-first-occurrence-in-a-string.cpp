class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();
        int len = 0, i = 1;
        vector<int > lps(m, 0);

        while(i < m) {
            if(needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if(len == 0) {
                    lps[i] = 0;
                    i++;
                }
                else {
                    len = lps[len - 1];
                }
            }
        }

        int n = haystack.size();
        int j = 0;
        i = 0;

        while(j < n) {
            if(haystack[j] == needle[i]) {
                i++, j++;
                if(i == m)
                    return (j - m);
            }
            else if(haystack[j] != needle[i]) {
                if(i == 0) {
                    j++;
                }
                else
                    i = lps[i - 1];
            }
        }

        return -1;

    }
};