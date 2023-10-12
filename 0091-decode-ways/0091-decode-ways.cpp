class Solution {
public:
int count(string s,int idx,unordered_map<string,int>umap,vector<int>&dp){
    if(idx==s.size()) return 1;
    if(dp[idx]!=-1) return dp[idx];

    int one=0;
    int two=0;

    string takeone=s.substr(idx,1);
    if(umap.find(takeone)!=umap.end()) one=count(s,idx+1,umap,dp);

    if(idx<s.size()-1){
        string taketwo=s.substr(idx,2);
        if(umap.find(taketwo)!=umap.end()) two=count(s,idx+2,umap,dp);
    }
    return dp[idx]=one+two;

}
    int numDecodings(string s) {
        int n=s.size();
        unordered_map<string,int>umap;
        for(int i=1;i<=26;i++){
            string x=to_string(i);
            umap[x]=1;
        }
        vector<int>dp(n+1,-1);
        return count(s,0,umap,dp);
    }
};