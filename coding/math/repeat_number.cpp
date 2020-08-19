
//原地置换
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i=0;
        while(i < nums.size()){
            while(nums[i] != i){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                swap(nums[i],nums[nums[i]]);
            }
            ++i;
        }
        return 0;
    }
};
//暴力法
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 首先进行排序
        sort(nums.begin(),nums.end());
        // 获取长度
        int result;
        for(int i = 0 ; i < nums.size()-1; ++i){
            if(nums[i] == nums[i+1]){
                result = nums[i];
            }
        }
        return result;
    }
};
//哈希表