#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// 两数之和
// 我们使用一个哈希表进行查询另外一个数字，如果刚好存在，则立即返回
// 否则到最后返回一个空的vector，这边用了简写的{}，用来初始化vector
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(target - nums[i])) 
                return {m[target - nums[i]], i};
            m[nums[i]] = i;
        }
        return {};
    }
};