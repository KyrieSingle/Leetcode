#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1.size() == 0) return true;
        int length = s1.size();
        bool*** dp = new bool**[length];
        for(int i = 0; i <length; ++i) {
            dp[i] = new bool*[length];
            for(int j = 0; j < length; ++j) {
                dp[i][j] = new bool[length];
            }
        }
        for(int i = 0; i < length; ++i) {
            for(int j = 0; j < length; ++j) {
                dp[0][i][j] = (s1[i] == s2[j]);
            }
        }
        for(int l=2;l<=length;l++) {  
            for(int i=0;i+l<=length;i++) {  
                for(int j=0;j+l<=length;j++) {  
                    dp[l-1][i][j] = false;  
                    for(int k=1;k<=l-1;k++) {  
                        if(dp[k-1][i][j]&&dp[l-k-1][i+k][j+k]) {  
                             dp[l-1][i][j]=true;  
                        } else if(dp[k-1][i][j+l-k]&&dp[l-k-1][i+k][j]) {  
                            dp[l-1][i][j]=true;  
                        }  
                    }  
                }  
            }  
        }
        return dp[length-1][0][0];
    }
};

int main() {
    Solution solution;
    string s1 = "great";
    string s2 = "rgeat";

    bool result = solution.isScramble(s1, s2);
    cout << result << " " << INT_MAX << endl;

    return EXIT_SUCCESS;
}
