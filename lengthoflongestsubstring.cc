#include <stdio.h>
#include <set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if(s.length() == 0) return 0;
        set<string> cset;
        cset.clear();
        int start = 0, end = 0;
        int res = 0;
        int count = 0;
        int i = 0;
        while(count < s.size()) {
            i = start;
            while(i < s.size() && cset.find(string(1,s[i])) == cset.end()) {
                cset.insert(string(1,s[i]));
                end = i;
                ++i;
            }
            cset.clear();
            ++count;
            res = (res > (end - start + 1)) ? res : end-start+1;
            start = count;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int res = solution.lengthOfLongestSubstring("aaddddb agaee");
    cout<<res<<endl;
    
    return 0;
}
