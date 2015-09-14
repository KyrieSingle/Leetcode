class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        if(n == 1) return triangle[0][0];
        vector<int> dp(triangle[n-1]);
        for(int i = n - 2; i >= 0; --i) {
            for(int j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};