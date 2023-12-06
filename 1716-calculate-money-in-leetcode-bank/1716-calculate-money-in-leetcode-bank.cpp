class Solution {
public:
    int totalMoney(int n) {
        int remainingDays = n % 7, fullWeeks = n / 7;



	int res = (fullWeeks * 28 + (fullWeeks - 1) * fullWeeks / 2 * 7) + ((remainingDays + 1 + 2 * fullWeeks) * remainingDays / 2);



	return res ;
    }
};