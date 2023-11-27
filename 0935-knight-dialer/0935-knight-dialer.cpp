class Solution {
public:
    const int mod=1e9+7;
    vector<vector<int>> adj={
        {4, 6},{6, 8},{7, 9},{4, 8}, {3, 9, 0},
        {}, {1, 7, 0},{2, 6}, {3, 1},{2,4}
    };
   
    vector<vector<int>> dp;
    int f(int i, int n){
        if (n==1) return 1;
        if (i==5) return 0;
        if (dp[i][n]!=-1) return dp[i][n];
        int ans=0;
        #pragma unroll
        for(int j: adj[i]){
            ans=(ans+f(j, n-1))%mod;
        }
        return dp[i][n]=ans;
    }
    int knightDialer(int n) {
        int ans=0;
        dp.assign(10, vector<int>(n+1, -1));
        #pragma unroll
        for(int i=0; i<=9; i++)
            ans=(ans+f(i, n))%mod;
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();