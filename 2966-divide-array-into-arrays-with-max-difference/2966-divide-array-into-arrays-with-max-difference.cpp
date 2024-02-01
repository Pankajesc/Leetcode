class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& arr, int k) {
        ios::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0);
        vector<vector<int>>ans,tp;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            temp.emplace_back(arr[i]);
            if(temp.size()==3)
            {
                int mini=*min_element(temp.begin(),temp.end());
                int maxi=*max_element(temp.begin(),temp.end());
                if(maxi-mini>k)return tp;
                else ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};