class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int count=0;
        int n=piles.size();
        int m=n-2;
        for(int i=0;i<n/3;i++){
           count+=piles[m];
           m=m-2;
        }
        return count;
    }
};