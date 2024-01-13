class Solution {
public:
    string minWindow(string s, string t) {
        if(t == ""){
            return "";
        }

        unordered_map<char , int> t_counter , window ;

        for(auto x : t){
            t_counter[x] = 1 + t_counter[x];
        }

        int have = 0 , need = t_counter.size() , ans_size = INT_MAX;
        vector<int> ans;
        int left = 0 ;

        for(int right = 0 ; right < s.size() ; right++){
            window[s[right]] = 1 + window[s[right]] ;

            if(t_counter.find(s[right]) != t_counter.end() && window[s[right]] == t_counter[s[right]]){
                have++;
            }

            while(have == need){
                if((right - left + 1) < ans_size){
                    ans = {left , right} ;
                    ans_size = right - left + 1 ;
                }
                
                window[s[left]] -= 1 ;
                if(t_counter.find(s[left]) != t_counter.end() && window[s[left]] < t_counter[s[left]]){
                    have--;
                }
                left++ ;
            }  
        }

        return ans_size != INT_MAX ? s.substr(ans[0] , ans[1]-ans[0]+1) : "" ;
        
        
    }
};