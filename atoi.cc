#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int atoi(string str) {
        int r = 0;
        int positive = 0, negative = 0,count = 0;
        bool flag = false;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == '-') {
                flag = true;
                negative++;
                count++;
                if(count > 1) return 0;
                continue;
            }else if(str[i] == '+'){
                flag = true;
                count++;
                positive++;
                if(count>1) return 0;
                continue;
            }
            if ('0' <= str[i] && str[i] <= '9') {
                if ((unsigned)r>(INT_MAX/10)) {
                    cout<<negative<<" "<<positive<<endl;
                    if(negative > positive) return INT_MIN;
                    else return INT_MAX;
                }
                flag = true;
                r = r * 10 + (str[i]-'0');
                cout<<r<<endl;
                if((unsigned)r > INT_MAX) {
                    if(negative > positive) return INT_MIN;
                    else return INT_MAX;
                }
            } else if (flag || str[i] != ' ') {
                break;
            }
        }
        if(negative == positive && negative != 0) return 0;
        if(negative > positive) r = -1 * r;
        return r;
    }
};

int main() {
    Solution solution;
    int r = solution.atoi("  10522545459");

    cout<<r<<endl;
    return 0;
}
