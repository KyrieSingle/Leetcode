#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long newNumrator = (long long)numerator;
        long long newDenominator = (long long)denominator;
        string resultString;
        if(newNumrator<0 && newDenominator>0){
            resultString+="-";
        } else if(newNumrator>0 && newDenominator<0){
            resultString+="-";
        }
        newNumrator = abs(newNumrator);
        newDenominator = abs(newDenominator);

        unordered_map<long long,int> fractionMap;
        vector<int> resultVec;
        if(newDenominator == 0) return "";
        resultString += to_string(newNumrator/newDenominator);
        long long f = newNumrator % newDenominator;
        if(f == 0){
            return resultString;
        } else {
            int firstLoop = 0;
            bool flag = false;
            resultString+=".";
            fractionMap.clear();
            resultVec.clear();
            int count = 0;
            fractionMap[f] = count;
            f = f * 10;
            resultVec.push_back(f/newDenominator);
            while(f){
                long long t = f % newDenominator;
                count++;
                if(fractionMap.find(t)!=fractionMap.end())
                {
                    flag = true;
                    firstLoop = t;
                    break;
                }
                fractionMap[t] = count;
                f = t*10;
                if(f)
                    resultVec.push_back(f/newDenominator);
            }
            if(flag){
                unordered_map<long long,int>::iterator it = fractionMap.find(firstLoop);
                int index = it->second;
                for(int i = 0; i < index; ++i){
                    resultString += '0'+resultVec[i];
                }
                resultString+="(";
                for(int i = index; i < resultVec.size(); ++i){
                    resultString += '0' + resultVec[i];
                }
                resultString+=")";
                return resultString;
            } else {
                for(int i = 0; i < resultVec.size(); ++i){
                    resultString+='0'+resultVec[i];
                }
                return resultString;
            }
        }
    }
};

int main(){
    Solution solution;
    int i , k;
    cin>>i>>k;
    string result = solution.fractionToDecimal(i,k);

    cout<<result<<endl;

    return EXIT_SUCCESS;
}
