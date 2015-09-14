class Solution {
public:
    double myPow (double x, int n) {
        if(0 == n) return 1;
        if(0 == x) return 0;

        double multiplier;
        double remainder = 1;

        long long ul_n = n;
        if(ul_n > 0) {
            multiplier = x;
        } else {
            multiplier = 1.0 / x;
            ul_n = abs(ul_n);
        }

        while(ul_n / 2 > 0) {
            double curRemainder = (ul_n % 2) * multiplier;
            remainder *= (curRemainder != 0 ? curRemainder : 1);
            ul_n /= 2;
            multiplier *= multiplier;
        }

        return multiplier * (remainder != 0 ? remainder : 1);
    }
};
