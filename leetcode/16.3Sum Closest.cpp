#include <iostream>
#include <vector>
using namespace std;
// 使用双指针法
// 依旧是从左往右，和从右往左，找一个最优的点
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int close = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                int threeSum = nums[l] + nums[r] + nums[i];
                if(abs(threeSum - target) < abs(close - target)) 
                    close = threeSum;
                if(threeSum > target) r--;
                else if(threeSum < target) l++;
                else return target;
            }
        }
        return close;
    }
};
