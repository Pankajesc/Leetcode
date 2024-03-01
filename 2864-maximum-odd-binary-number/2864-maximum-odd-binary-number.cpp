class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int oneCount = count(s.begin(), s.end(), '1'), size = s.size(), zeroCount = size - oneCount;
        string res = "";
        oneCount--;// decrementing oneCount as we will append one more '1' at the end
        while(oneCount-->0){
            res += "1";
        }
        while(zeroCount-->0){
            res += "0";
        }
        res += "1";
        return res;
    }
};