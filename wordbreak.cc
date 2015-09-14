#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
private:
    int minV, maxV, n;
    void helper(string &s, unordered_set<string>& wordDict, int begin, string& str, vector<string>& res) {
        for(int i = minV; i <= min(maxV, n - begin); ++i) {
            if(wordDict.find(s.substr(begin, i)) != wordDict.end()) {
                if(i == n - begin) {
                    res.push_back(str + s.substr(begin, i));
                } else {
                    string pre = str;
                    str += s.substr(begin, i)+" ";
                    helper(s, wordDict, begin + i, str, res);
                    str = pre;
                }
            }  
        } 
    }
public:
    vector<string> wordBreak_2(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        if(!wordBreak(s, wordDict)) return result;
        string str = "";
        helper(s, wordDict, 0, str, result);
        return result;
    }

    bool wordBreak(string s, unordered_set<string>& wordDict) {
        n = s.size();
        if(n == 0) return false;
        maxV = INT_MIN, minV = INT_MAX;
        for(auto it = wordDict.begin(); it != wordDict.end(); ++it) {
            if((int)it->size() > maxV) {
                maxV = it->size();
            }
            if((int)it->size() < minV) {
                minV = it->size();
            }
        }

        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i = n - 1; i >= 0; --i) {
            for(int j = minV; j <= min(maxV, n - i); ++j) {
                string subword = s.substr(i, j);
                if(dp[i+j] && wordDict.find(subword) != wordDict.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[0] == 1;
    }
};

int main() {
    Solution solution;
    string s;
    int n  = 0;
    cin >> s;
    cin >> n;
    unordered_set<string> dict;
    for(int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        dict.insert(word);
    }

    vector<string> result = solution.wordBreak_2(s, dict);
    for(int i = 0; i < result.size(); ++i)
        cout << result[i] << endl;

    return 0;
}
