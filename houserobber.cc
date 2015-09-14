#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob_1(vector<int>& nums) {
        if(0 == nums.size()) return 0;
        if(1 == nums.size()) return nums[0];
        if(2 == nums.size()) return max(nums[0], nums[1]);
        vector<int> result(nums.size(), 0);
        result[0] = nums[0];
        result[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i) {
            result[i] = max(result[i-1], result[i-2]+nums[i]);
        }
        
        return result[nums.size()-1];
    }

    int rob_2(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> a(nums.begin(), nums.end()-1);
        vector<int> b(nums.begin()+1, nums.end());

        return max(rob_1(a), rob_1(b));
    }

};
