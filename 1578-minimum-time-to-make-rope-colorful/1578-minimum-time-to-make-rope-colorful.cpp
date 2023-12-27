class Solution {
public:
    int minCost(string s, vector<int>& v) {
        // Initialize mincost to 0
        int mincost = 0;
        // Get the length of the input string
        int n = s.size();

        // Iterate through the balloons
        for (int i = 1; i < n;) {
            // If current balloon color is different from the previous one, move to the next balloon
            if (s[i] != s[i - 1]) {
                i++;
            } else {
                // If current balloon color is the same as the previous one
                // Find sum and maximum removal time for consecutive same-colored balloons
                int sum = v[i - 1];
                int maxi = v[i - 1];
                
                // Continue until consecutive same-colored balloons end
                while (s[i] == s[i - 1]) {
                    // Update the sum of removal times
                    sum = sum + v[i];
                    // Track the maximum removal time
                    maxi = max(v[i], maxi);
                    i++;
                }
                
                // Add (sum - maxi) to mincost
                mincost += (sum - maxi);
            }
        }
        
        // Return the final mincost
        return mincost;
    }
};