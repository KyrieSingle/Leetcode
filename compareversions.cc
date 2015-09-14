#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> version1Vec = getNum(version1);
        vector<int> version2Vec = getNum(version2);
        int min = std::min(version1Vec.size(), version2Vec.size());
        int max = std::max(version1Vec.size(), version2Vec.size());
        if(version1Vec.size()>version2Vec.size()){
            for(int i = 0; i < (max - min); ++i){
                version2Vec.push_back(0);
            }
        } else {
            for(int i = 0; i < (max - min); ++i){
                version1Vec.push_back(0);
            }
        }
        for(int i = 0; i < max; ++i){
            if( version1Vec[i] > version2Vec[i]) return 1;
            else if(version1Vec[i] < version2Vec[i]) return -1;
        }
        return 0;
    }
private:
    vector<int> getNum(string version){
        vector<int> getNumber;
        int number = 0;
        for(int i = 0; i < version.length(); ++i){
            const char *ptr;
            char t = version.at(i);
            if(t != '.'){
                ptr = &t;
                number = number*10 + atoi(ptr);
            } else {
                getNumber.push_back(number);
                number = 0;
            }
        }
        getNumber.push_back(number);
        return getNumber;
    }
};

int main(){
    Solution solution;
    string version1, version2;
    cin>>version1>>version2;
    int result;

    result = solution.compareVersion(version1,version2);
    cout<<result<<endl;

    return EXIT_SUCCESS;
}

