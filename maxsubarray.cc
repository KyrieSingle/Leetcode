#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > max) max = sum;
            if (sum < 0 ) sum = 0;
        }

        return max;
    }
};

int main() {
    int array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int count = sizeof(array) / sizeof(int);

    vector<int> vec(array, array+count);
    Solution solution;

    int result = solution.maxSubArray(vec);
    cout << result << endl;
    
    return EXIT_SUCCESS;
}
