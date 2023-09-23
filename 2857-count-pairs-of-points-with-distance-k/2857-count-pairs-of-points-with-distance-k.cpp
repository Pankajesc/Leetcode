class Solution {
public:
    int countPairs(vector<vector<int>>& c, int k) {
        //map to keep track of used pairs
        map<pair<int,int>,int> mp;
        int n=c.size();
        int ans=0;
        for(int i=0 ; i<n ; i++){
            
            // finding all possible (x,y) which gives : 
            //c[i][0]^x+c[i][1]^y=k                   (0)
            //Consider above is true , then
            //if , c[i][0]^x=val                      (1)
            //then c[i][1]^y=k-val                    (2)
            
            //
            //using a^b=c , then a^c=b
            //from  (1) , we have c[i][0]^val=x;
            //from  (2) , we have c[i][1]^(k-val)=y;
            //so we just need to traverse  dfsd through all possible values of val to get pairs(x,y) satisfying  eq.(0) 
            
            for(int val=0 ; val<=k ; val++){
                //using a^b=c , then a^c=b
                
                int x=val^c[i][0];    
                int y=(k-val)^c[i][1];
                ans+=mp[make_pair(x,y)];
            }
            
            mp[make_pair(c[i][0],c[i][1])]++;
        }
        return ans;
    }
};
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long maximumSum(vector<long>& a, long m) {
    long n = a.size();
    long maxSum = 0;
    long prefixSum = 0;

    // Use prefix sum to calculate subarray sum modulo m
    vector<long> prefixSums(n);
    for (int i = 0; i < n; ++i) {
        prefixSum = (prefixSum + a[i]) % m;
        prefixSums[i] = prefixSum;
    }

    // Sort the prefix sums and find the maximum difference between adjacent elements
    sort(prefixSums.begin(), prefixSums.end());
    for (int i = 0; i < n - 1; ++i) {
        long diff = (prefixSums[i + 1] - prefixSums[i] + m) % m;
        maxSum = max(maxSum, diff);
    }

    // Compare the maximum difference with the maximum prefix sum
    maxSum = max(maxSum, prefixSums[n - 1]);

    return maxSum;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        long n, m;
        cin >> n >> m;

        vector<long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long result = maximumSum(a, m);
        cout << result << endl;
    }

    return 0;
}
*/