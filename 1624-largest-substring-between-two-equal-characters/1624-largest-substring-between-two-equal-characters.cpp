class Solution {
public:
    int maxLengthBetweenEqualCharacters(string st) {
        vector<int> s(26, -1), e(26, -1);
        int ans = -1;
        for(int i = 0;i < st.length();i++){
            if(s[st[i]-'a'] == -1) s[st[i]-'a'] = i, e[st[i]-'a'] = i;
            else e[st[i]-'a'] = i, ans = max(ans, e[st[i]-'a']-s[st[i]-'a']-1);  
        }
        return ans;
    }
};