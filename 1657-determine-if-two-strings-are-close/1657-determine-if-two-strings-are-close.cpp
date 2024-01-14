class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char>s1,s2;
        vector<int>v_word1(26,0);
        vector<int>v_word2(26,0);
        
        for(char c:word1){
            v_word1[c-'a']++;
            s1.insert(c);
        }
        for(char c:word2){
            v_word2[c-'a']++;
            s2.insert(c);
        }
        sort(v_word1.begin(),v_word1.end());
        sort(v_word2.begin(),v_word2.end());
        return v_word1==v_word2&&s1==s2;
    }
};