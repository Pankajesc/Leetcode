#include<iostream>
 #include<bits/stdc++.h>
    using namespace std;

            void Bubblesort(int arr[], int n){
                  for(int i=1; i<n; i++){
                        
                        for(int j=0; j<n-i; j++){
                            if(arr[j]>arr[j+1])
                                swap(arr[j], arr[j+1]);
                            
                        }
                  }
                  cout<<"After Sorting by BubbleSort Array is: ";
                  for(int i=1; i<n; i++){
                    cout<<arr[i]<<" ";
                  }
            }
    int main(){
        int arr[8]={1,5,87,55,95,8,85};
        Bubblesort(arr, 8);
        return 0;
    }
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