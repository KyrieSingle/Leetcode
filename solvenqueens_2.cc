#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if(1 == n) return 1;
        vector<int> r(n, -1);
        return dfs(r, 0);
    }
private:
    int dfs(vector<int>& r, int curRow) {
        int total = 0;
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
                return 1;
            } else if (valid) {
                total += dfs(r, curRow + 1);
            }
        }
        return total;
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    int result = solution.totalNQueens(n);

    cout << result << endl;

    return EXIT_SUCCESS;
}
