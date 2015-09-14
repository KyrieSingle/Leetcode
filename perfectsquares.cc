#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        int result = 0;
        vector<int> dp(n+1, INT_MAX);
        for(int i = 1; i <= sqrt(n); ++i) {
            dp[i*i] = 1;
        }
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3 ; i <= n; ++i){
            if(dp[i] == 1) continue;
            for(int j = 1; j <= sqrt(i); ++j) {
                dp[i] = min(dp[i], dp[j*j]+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    int number = 0;
    cin >> number;
    int result = solution.numSquares(number);
    
    cout << result << endl;

        int temp = 1;
    return 0;
}
