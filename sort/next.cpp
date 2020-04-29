#include <map>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<map<int, bool>> v;
    int dp_v[9999][9999] = {0};
    int splitArray(vector<int>& nums) {
        v.resize(nums.size());
        for(int i = 0; i < nums.size(); i++) 
            for(int j = 2; j <= nums[i]; j++) 
                if(nums[i] % j == 0) v[i][j] = true;
        
        return dp(nums, 0, nums.size() - 1);
    }
    int dp(vector<int>& nums, int start, int end) {
        if(start >= end) return 1;
        for(auto it = v[start].begin(); it != v[start].end(); it++) 
            if(v[end][it->first]) return 1;
        int min = 99999;
        for(int i = start; i < end; i++) {
            if(dp_v[start][i] == 0) dp_v[start][i] = dp(nums, start, i);
            if(dp_v[i + 1][end] == 0) dp_v[i+1][end] = dp(nums, i + 1, end);
            int tmp = dp_v[start][i] + dp_v[i + 1][end];
            if(tmp < min) min = tmp;
        }
        return min;
    }
};
int main() {
    
    return 0;
}