class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> v(2001,0);
        
        for(int i=0;i<arr.size();i++){
            v[arr[i]+1000]++;
        }
        vector<int> temp(2001);
        for(int i=0;i<v.size();i++){
            temp[v[i]]++;
        }
        for(int i=1;i<temp.size()-1;i++){
            if(temp[i]>1){return false;}
        }
        return true;
    }
};