class Solution {
public:
    vector<double> convertTemperature(double Celsius) {
       double Kelvin = Celsius + 273.15;
       double Fahrenheit = Celsius * 1.80 + 32.00;
       vector<double> v;
       v.push_back(Kelvin);
       v.push_back(Fahrenheit);
       return v;
    }
};
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long maximumSum(vector<long>& a, long m) {
    long n = a.size();
    long maxSum = 0;
    long prefixSum = 0;

    // Use prefix sum to calculate subarray sum modulo m
    vector<long> prefixSums(n);
    for (int i = 0; i < n; ++i) {
        prefixSum = (prefixSum + a[i]) % m;
        prefixSums[i] = prefixSum;
    }

    // Sort the prefix sums and find the maximum difference between adjacent elements
    sort(prefixSums.begin(), prefixSums.end());
    for (int i = 0; i < n - 1; ++i) {
        long diff = (prefixSums[i + 1] - prefixSums[i] + m) % m;
        maxSum = max(maxSum, diff);
    }

    // Compare the maximum difference with the maximum prefix sum
    maxSum = max(maxSum, prefixSums[n - 1]);

    return maxSum;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        long n, m;
        cin >> n >> m;

        vector<long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long result = maximumSum(a, m);
        cout << result << endl;
    }

    return 0;
}
*/