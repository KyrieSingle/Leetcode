class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int current = 0;
        int flag = 1;
        for(int i = 1; i < n; ++i) {
            if(nums[i] != nums[current]) {
                nums[++current] = nums[i];
                flag = 1;
            } else if(nums[i] == nums[current] && flag != 2) {
                nums[++current] = nums[i];
                flag++;
            }
        }
        return ++current;
    }
};
