#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        int result = 0;
        for(long long i = 1; i <= n; i *= 10) {
            long long a = n / i;
            long long b = n % i;
            result += (a+8)/10 * i;
            if(a % 10 == 1) {
                result += b + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    int number = 0;
    cin >> number;
    int result = solution.countDigitOne(number);

    cout << number << " result is: " << result << endl;

    return 0;
}
