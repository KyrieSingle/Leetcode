#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.empty()) return result;
        
        unordered_map<string, int> map;
        for(int i = 0; i < strs.size(); ++i) {
            string temp = strs[i]; 
            sort(strs[i].begin(), strs[i].end());
            if(map.find(strs[i]) != map.end()) {
                int index = map.find(strs[i])->second;
                result[index-1].push_back(temp);
                sort(result[index-1].begin(), result[index-1].end());
            } else {
                vector<string> newStr;
                newStr.push_back(temp);
                result.push_back(newStr);
                map.insert(pair<string, int>(strs[i], result.size()));
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<string> strs(2, "");
    vector<vector<string>> result = solution.groupAnagrams(strs);

    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << endl;
        }
    }

    return EXIT_SUCCESS;
}
