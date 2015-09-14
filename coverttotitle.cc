#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        std::string result;
        if (n < 27 && n >1) {
            result = 'A' + (n - 1);
            return result;
        } else {
            int i = 0;
            int mod;
            std::string r;
            while(n){
                mod = n % 26;
                if(mod){
                    r += 'A' + (mod - 1);
                    n = n / 26;
                } else {
                    r += 'Z';
                    n = n/26;
                    --n;
                }
            }
            for (int i = r.size()-1; i>=0; --i) {
                result+=r[i];
            }
            return result;
        }
    }
};

int main(){
    int number;
    cin>>number;

    Solution solution;
    string result = solution.convertToTitle(number);
    cout<<result<<endl;

    return EXIT_SUCCESS;
}



