#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> r(n, -1);
        dfs(result, r, 0);
        return result;
    }
private:
    void dfs(vector<vector<string>>& result, vector<int>& r, int curRow) {
        for(int x = 0; x < r.size(); ++x) {
            r[curRow] = x;
            bool valid = true;
            for(int i = 0; i < curRow; ++i) {
                if(r[i] == x || abs(curRow - i) == abs(x - r[i])) {
                    valid = false;
                    break;
                }
            }

            if(valid && curRow == r.size() - 1) {
                vector<string> v(r.size(), string(r.size(), '.'));
                for(int i = 0; i < r.size(); ++i) {
                    v[i][r[i]] = 'Q';
                }
                result.push_back(v);
            } else if (valid) {
                dfs(result, r, curRow + 1);
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<string>> result;
    result = solution.solveNQueens(4);

    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << endl;
        }
    }

    return EXIT_SUCCESS;
}
