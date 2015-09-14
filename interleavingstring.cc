#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_SIZE 1001

bool dp[MAX_SIZE][MAX_SIZE];

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size()+s2.size()) return false;
        if(s1.size() == 0) return s2 == s3;
        if(s2.size() == 0) return s1 == s3;
        int m = s1.size();
        int n = s2.size();
        int l = s3.size();
        for(int i = 0; i < MAX_SIZE; ++i) {
            for(int j = 0; j < MAX_SIZE; ++j) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for(int i = 1; i <= s1.size(); ++i) {
            dp[i][0] = dp[i-1][0] && (s3[i-1] == s1[i-1]);
        }
        for(int j = 1; j <= s2.size(); ++j) {
            dp[0][j] = dp[0][j-1] && (s3[j-1] == s2[j-1]);
        }
        for(int i = 1; i <= s1.size(); ++i) {
            for(int j = 1; j <= s2.size(); ++j) {
                dp[i][j] = (dp[i][j-1] && s3[i+j-1] == s2[j-1]) || (dp[i-1][j] && s3[i+j-1] == s1[i-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

int main () {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    Solution solution;
    bool result = solution.isInterleave(s1, s2, s3);

    cout << "Result is " << result << endl;
    return 0;
}
