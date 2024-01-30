class Solution {
public:

    double find(int i,vector<vector<int>>&points,double &slope){
        return points[i][0]-(1.0*points[i][1]/slope);
    }

    int maxPoints(vector<vector<int>>& points) {
        int ans=1;
        int n=points.size();
        for(int i=0;i<n;i++){
            map<pair<double,double>,int>mp;
            int cnt=0;
            for(int j=i+1;j<n;j++){
                double slope=points[j][0]==points[i][0]?90:1.0*(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                if(slope==90) mp[{points[i][0],90}]++,ans=max(ans,1+mp[{points[i][0],90}]);
                else if(slope==0) cnt++,ans=max(ans,cnt+1);
                else{
                    double x=find(i,points,slope);
                    mp[{x,slope}]++;
                    ans=max(ans,mp[{x,slope}]+1);
                }
            }
        }
        return ans;
    }
};