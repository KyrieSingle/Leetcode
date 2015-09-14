class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        helper(result, nums, 0);
        return result;
    }
private:
    void helper(vector<vector<int>>& result, vector<int>& nums, int curIndex){
        if(curIndex < nums.size()) {
            if(curIndex == nums.size()-1) {
                result.push_back(nums);            
            } else {
                helper(result, nums, curIndex+1);
                unordered_set<int> set;
                set.insert(nums[curIndex]);
                for(int i = curIndex+1; i < nums.size(); ++i) {
                    if(set.find(nums[i])!= set.end()) continue;
                    set.insert(nums[i]);
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
};
