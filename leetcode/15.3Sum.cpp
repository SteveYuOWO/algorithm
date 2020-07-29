#include <iostream>
#include <vector>
#include <algorithm>
// 1.进行排序
// O(nlogn)
// 2. i, j, k 三个指针
// 固定 i, j 从左往右, k 从右往左, 我们即可进行
// 因为 j 变大，k 不可能还出现在再右边位置（反证法），即可证明，j 越大， k越小
// 优化为了 O(n * n)  i 也要一个循环
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i && nums[i] == nums[i - 1]) continue; // 去除重复元素
            for(int j = i + 1, k = nums.size() - 1; j < k; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue; // 去除重复元素
                while(j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0) k--;
                if(nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return res;
    }
};