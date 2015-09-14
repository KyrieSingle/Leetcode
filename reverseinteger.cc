#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = abs(x);
        int r = 0;
        while(res > 0){
            if(r > (INT_MAX / 10)) return 0;
            r = r * 10 + (res%10);
            res = res / 10;
        }
        if(r < 0 ) return 0;
        return (x < 0) ? -1 * r : r;
    }
};

int main() {
    Solution solution;
    int r = solution.reverse(1534236469);

    cout<<r<<endl;
    cout<<INT_MAX<<endl;
}
