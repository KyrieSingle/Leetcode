#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        if(row == 0) return -1;
        int col = dungeon[0].size();
        vector<vector<int> > dp(row+1, vector<int> (col+1,0));
        for(int i = 0; i < row+1; i++) dp[i][col] = INT_MAX;
        for(int i = 0; i < col+1; i++) dp[row][i] = INT_MAX;
        dp[row][col-1] = 1;
        dp[row-1][col] = 1;
        int val = 0;
        for(int i = row-1; i >= 0; --i) {
            for(int j = col-1; j >= 0; --j) {
                val = min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                dp[i][j] = val <= 0 ? 1 : val; 
            }
        }

        return dp[0][0];
    }
};

int main() {
    int m = 0, n = 0;
    cin >> m >> n;
    vector<vector<int>> dungeon;
    for(int i = 0; i < m; ++i) {
        vector<int> line(n, 0);
        for(int j = 0; j < n; ++j) {
            cin >> line[j];
        }
        dungeon.push_back(line);
    }

    Solution solution;
    int result = solution.calculateMinimumHP(dungeon);

    cout << result << endl;
    return 0;
}

