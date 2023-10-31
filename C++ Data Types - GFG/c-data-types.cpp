//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int cppIntType() {
        // code here
        int a;
        cin>>a;
        return a;
    }
    
    char cppCharType() {
        // code here
        char c;
        cin>>c;
        return c;
    }
    
    float cppFloatType() {
        // code here
        float f;
        cin>>f;
        return f;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        Solution ob;
        cout << ob.cppIntType() << endl;
        cout << ob.cppCharType() << endl;
        cout << ob.cppFloatType() << endl;
    }
    return 0;
}
// } Driver Code Ends