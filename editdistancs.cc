class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int dp[n+1] = {0};
        for(int j = 1; j <= n; ++j) {
            dp[j] = j;
        }
        int start, cur;
        for(int i = 1; i <= m; ++i) {
            start = dp[0];
            dp[0] = i;
            for(int j = 1; j <= n; ++j) {
                cur = dp[j];
                dp[j] = min(min(dp[j]+1, dp[j-1]+1), start+(int)(word1[i-1] != word2[j-1]));
                start = cur;
            }
        }
        return dp[n];
    }
};
