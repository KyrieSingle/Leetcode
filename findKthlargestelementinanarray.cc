#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int cur=nums[k-1];
        vector<int> bigger;
        vector<int> smaller;
        for(size_t i=0; i<nums.size(); ++i){
            if(i==k-1) continue;
            if(nums[i]>=cur) bigger.push_back(nums[i]);
            else smaller.push_back(nums[i]);
        }
        if(bigger.size()==k-1) return cur;
        if(bigger.size()>k-1) return findKthLargest(bigger,k);
        if(bigger.size()<k-1) return findKthLargest(smaller,k-bigger.size()-1);
    }
};
