#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if(n == 0) return result;
        vector<int> temp;
        helper(result,temp,k-1,n,1);
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int>& temp, int k, int n, int index) {
        if(k == 0) {
            if(n >= index && n <= 9) {
                temp.push_back(n);
                result.push_back(temp);
                temp.pop_back();
                return;
            }
            return;
        } 
        if(n <= index) return;
        if(k == 0) return;
        for(int i = index; i <= 9 ; ++i) {
            temp.push_back(i);
            helper(result, temp, k-1, n-i, i+1);
            temp.pop_back();
        }
    }    
};

int main() {
    int k , n;
    cin >> k >> n;
    Solution solution;

    vector<vector<int>> result;
    result = solution.combinationSum3(k, n);

    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < k-1; ++j) {
            cout << result[i][j] << " ";
        }
        cout << result[i][k-1] << endl;
    }

    return 0;
}

