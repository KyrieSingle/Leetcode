#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(0 == nums.size()) return 0;
        if(1 == nums.size()) return nums[0];
        return recursive(nums, 0, nums.size()-1);
    }
private:
    int recursive(vector<int>& nums, int start, int end) {
        if(start == end) return nums[start];
        if(start == end - 1) {
            if(nums[start] <= nums[end]) return nums[start];
            else return nums[end];
        } else {
            if(nums[start] < nums[end]) {
                return nums[start];
            } else if (nums[start] == nums[end]){
                return recursive(nums, start+1, end);
            } else {
                int middle = (start + end) / 2;
                if(nums[middle] >= nums[start]) {
                    return recursive(nums, middle, end);
                } else {
                    return recursive(nums, start, middle);
                }
            }
        }
    }
};

int main() {   
    Solution solution;
    int array[] = {4, 5, 6, 7, 0, 0, 1, 2};
    size_t count = sizeof(array) / sizeof(int);
    vector<int> vec(array, array+count);
    int result = solution.findMin(vec);

    cout << result << endl;

    return EXIT_SUCCESS;
}
