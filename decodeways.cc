#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0') return 0;
        if(n == 1) return 1;
        int result = 0;
        int f1 = 1, f2 = 1;
        for(int i = 1; i < n; ++i) {
            int temp = f1;
            if(isValid(s[i])&&isValid(s[i-1],s[i]))  result+=f1+f2;
            if(!isValid(s[i])&&isValid(s[i-1],s[i])) result+=f2;
            if(isValid(s[i])&&!isValid(s[i-1],s[i])) result+=f1;
            if(!isValid(s[i])&&!isValid(s[i-1],s[i]))  return 0;
            f1 = result;
            f2 = temp;
            result = 0;
        }
        
        return f1;
    }
private:
    bool isValid(char a, char b) {
        return a == '1' || (a == '2' && b <= '6');
    }
    bool isValid(char a) {
        return a != '0';
    }
};

int main() {
    string s;
    cin >> s;
    Solution solution;

    int result = solution.numDecodings(s);

    cout << result << endl;
    return 0;
}
