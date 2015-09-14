#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res = generateChildVec(digits, letters, 0);
        return res;
    }
private:
    vector<string> generateChildVec(string& digits, string letters[], int level) {
        vector<string> res;
        if(digits.size() <= level) return res;
        int curDig = digits[level] - 48;
        vector<string> childRes = generateChildVec(digits, letters, level+1);
        for(int i = 0; i < letters[curDig].size(); ++i){
            string tString = string(1, letters[curDig][i]);
            if(childRes.size() != 0){
                for(int j = 0; j < childRes.size(); ++j) {
                    res.push_back(tString+childRes[j]);
                }
            } else {
                res.push_back(tString);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<string> res;
    res = solution.letterCombinations("24");

    for(int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<endl;
    }
}
