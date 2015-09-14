class Solution {
private:
    void helper(vector<vector<int>>& result, vector<int>& nums, int curIndex) {
        if(curIndex < nums.size()) {
            if(curIndex == nums.size() - 1) {
                result.push_back(nums);
            } else {
                helper(result, nums, curIndex+1);
                for (int i = curIndex+1; i < nums.size(); ++i) {
                    int temp = nums[i];
                    nums[i] = nums[curIndex];
                    nums[curIndex] = temp;

                    helper(result, nums, curIndex+1);
                    nums[curIndex] = nums[i];
                    nums[i] = temp;
                }
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(result, nums, 0);
        return result;
    }
};
