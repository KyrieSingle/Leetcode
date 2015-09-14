#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        using ll = long long;
        ll curmax = nums[0], curmin = nums[0], res = nums[0];
        for(int i=1; i<nums.size(); ++i){
            ll premax = curmax;
            curmax = max(curmax*nums[i], max(curmin*nums[i], (ll)nums[i]));
            curmin = min(premax*nums[i], min(curmin*nums[i], (ll)nums[i]));
            res = max(res, curmax);
        }
        return (int)res;
    }
};
