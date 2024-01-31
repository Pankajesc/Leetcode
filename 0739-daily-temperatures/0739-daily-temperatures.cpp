class Solution {
public:
    // time/space: O(n)/O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && (temperatures[stk.back()] < temperatures[i])) {
                answer[stk.back()] = (i - stk.back());
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return answer;
    }
};