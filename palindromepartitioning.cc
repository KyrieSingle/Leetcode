#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if(s.size() == 0) return result;
        vector<string> cache;
        helper(result, cache, s, 0);
        return result;
    }
private:
    void helper(vector<vector<string>>&result, vector<string>& cache, string s, int index) {
        if(index == s.size()) {
        	result.push_back(cache);
        	return;
        }
        int n = s.size();
        for(int i = index; i < n; ++i) {
        	int left = index, right = i;
        	while(left < right && s[left] == s[right]) {
        		left++;
        		right--;
        	}
        	if(left >= right) {
        		cache.push_back(s.substr(index, i - index + 1));
        		helper(result, cache, s, i+1);
        		cache.pop_back();
        	}
        }
    }
};

int main() {
	Solution solution;

	string s;
	cin >> s;

	vector<vector<string>> result = solution.partition(s);

	for(int i = 0; i < result.size(); ++i) {
		int n = result[i].size();
		for(int j = 0; j < n - 1; ++j) {
			cout << result[i][j] << " ";
		}
		cout << result[i][n-1] << endl;
	}

	return 0;
}