class Solution 
{
    public:
        string longestCommonPrefix(vector<string>& strs) 
        {
            int minLen = INT_MAX;
            for (const string& s : strs)
            {
                minLen = min(minLen, (int)s.size());
            }
            string ans= "";
            if((int)strs.size()==1)
            {
                ans = strs[0];
                return ans;
            }
            for(int i=0;i<minLen;i++)
            {
                int count=0;
                for(int j=0;j<(int)strs.size()-1;j++)
                {
                    if(strs[j][i]==strs[j+1][i])
                    {
                        count++;
                    }
                    if(count==(int)strs.size()-1)
                    {
                        ans = ans + strs[0][i];
                    }
                    if(strs[j][i]!=strs[j+1][i])
                    {
                        return ans;
                    }
                    
                }
            }
            return ans;
            
        }
};