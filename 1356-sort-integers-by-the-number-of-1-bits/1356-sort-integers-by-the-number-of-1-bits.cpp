class Solution {
public:
	vector<int> sortByBits(vector<int>& arr) {
		sort(arr.begin(), arr.end(), compareFunc);			
		return arr;
	}
private:
	static int countOnes(int n) {
		int count = 0;
		while (n) {
			n = n & (n - 1);
			count++;
		}
		return count;
	}
	static bool compareFunc(int a, int b) {
		int c = countOnes(a), d = countOnes(b);
		if (c == d)
			return (a <= b);
		else
			return(c < d);
	}
};