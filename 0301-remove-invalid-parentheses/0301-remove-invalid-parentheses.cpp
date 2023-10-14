class Space{
  public:
    bool isValid;
    int removals;
    string str;
    Space(bool isValid , int removals , string str){
        this->isValid = isValid;
        this->removals = removals;
        this->str = str;
    }
};

class Compare{
    public:
    bool operator()(Space &a , Space &b){
        if(a.isValid == b.isValid){
            return a.removals > b.removals;
        }
        else{
            return a.isValid < b.isValid;
        }
    }
    
};

class Solution {
public:
    bool checkValidity(string str){
        stack<char> s;
        int n = str.size();
        for(int i=0 ; i<n ; i++){
            if((str[i] == '(')){
                s.push(str[i]);
            }
            else if(str[i] == ')'){
                if(s.empty()) return false;
                else if(s.top()=='('){
                    s.pop();
                }
            }
        }
        
        return s.empty();
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        priority_queue<Space , vector<Space> , Compare> pq;
        vector<string> ans;
        
        pq.push(Space(checkValidity(s) , 0 , s));
        set<string> vis;
        vis.insert(s);
        int minRemovals = 1e6;
        while(pq.size() > 0){
            auto [valid , rems , currStr] = pq.top() ; pq.pop();
            // cout<<valid<<" "<<rems<<" "<<currStr<<endl;
            if(rems > minRemovals) break;
            if(valid){
                minRemovals = rems;
            }
            if(valid && (minRemovals == rems)){
                ans.push_back(currStr);
            }
            
            for(int i=0 ; i<currStr.size() ; i++){
                if(currStr[i]>='a' && currStr[i]<='z') continue;
                string left = currStr.substr(0 , i);
                // cout<<left<<" is left"<<endl;
                string right = currStr.substr(i+1);
                // cout<<right<<" is rihgt"<<endl;
                string newStr = left+right;
                if(vis.count(newStr) == 0 ){
                    vis.insert(newStr);
                    pq.push(Space(checkValidity(newStr) , rems+1 , newStr));
                }                
            }
            
        }
        
        return ans;
    }
};