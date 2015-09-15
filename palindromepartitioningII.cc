class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n<=1) return 0;

        bool isPalin[n][n];
        fill_n(&isPalin[0][0], n*n, false);
        int minCuts[n+1];
        for(int i = 0; i <= n; ++i) 
            minCuts[i] = i-1;

        for(int j = 1; j < n; ++j)
        {
            for(int i = j; i >= 0; --i)
            {
                if( (s[i] == s[j]) && ( ( j-i < 2 ) || isPalin[i+1][j-1] ) )
                {
                    isPalin[i][j] = true;
                    minCuts[j+1] = min(minCuts[j+1], 1 + minCuts[i]);    
                }
            }
        }
        return minCuts[n];
    }
};