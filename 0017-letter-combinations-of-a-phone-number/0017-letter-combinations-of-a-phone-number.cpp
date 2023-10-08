class Solution {
public:
    vector<string> letterCombinations(string digits) {
       vector<string> res;
       vector<char> curChrSeq;
       findCombs(digits, 0, res, curChrSeq);
       return res;     
    }
 private:
    vector<string> dToLMap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void findCombs(string digits, int startIndx, vector<string> & res, vector<char> & curChrSeq){
        int sz = digits.size();
        if(startIndx == sz){
            string comb = "";
            for(auto chr : curChrSeq){
                comb += chr;
            }
            if(comb.size() > 0)
             res.push_back(comb);
            return;
        }
        string optns = dToLMap[digits[startIndx] - '2'];
        sz = optns.size();
        for(int indx = 0; indx<sz; indx++){
            curChrSeq.push_back(optns[indx]);
            findCombs(digits, startIndx+1, res, curChrSeq);
            curChrSeq.pop_back();
        }
    }
};