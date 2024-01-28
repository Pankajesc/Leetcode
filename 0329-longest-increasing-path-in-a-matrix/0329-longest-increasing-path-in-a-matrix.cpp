class Solution {
public:
    int dp[200][200]={};
    int m,n,ans=1;

    int solve(vector<vector<int>>& matrix,int i,int j, int prev){
        if(i<0 || i>=m || j<0 || j>=n || matrix[i][j]<=prev)return 0;
        if(dp[i][j])return dp[i][j];
        return dp[i][j]=1+max({
            solve(matrix,i+1,j,matrix[i][j]),
            solve(matrix,i,j+1,matrix[i][j]),
            solve(matrix,i-1,j,matrix[i][j]),
            solve(matrix,i,j-1,matrix[i][j])
        });
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,solve(matrix,i,j,-1));
            }
        }
        return ans;
    }
};