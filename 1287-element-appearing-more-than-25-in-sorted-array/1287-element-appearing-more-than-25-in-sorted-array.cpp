class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int val=0.25*arr.size();
        map<int,int>mp;
        for(auto &it:arr){
            mp[it]++;
        }
        for(auto &it:mp){
            if(it.second>val){
                return it.first;
            }
        }return -1;
    }
};