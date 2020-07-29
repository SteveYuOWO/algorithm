#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // findMedianSortedArrays
    // 我们首先total存储nums1, nums2的数组之和
    // 然后如果total为奇数，则找第total/2大的数（减少规模)
    // 如果total为偶数，则找total/2 + 1大的数
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if(total % 2 == 0) {
            int left = findKthNumber(nums1, 0, nums2, 0, total / 2);
            int right = findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
            return (left + right) / 2.0;
        } else {
            return findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
        }
    }
    // findKthNumber
    // 如果nums1比nums2数组大小要打，则进行交换递归（这步是进行把小的数组放在前面
    // 如果nums1找到出口，则返回nums2中第k大数
    // 如果k为1了，则是i，j中最小的数
    // 如果nums1[si - 1] > nums2[sj - 1], 则把nums2中指针往前移动k/2
    int findKthNumber(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if(nums1.size() - i > nums2.size() - j) 
            return findKthNumber(nums2, j, nums1, i, k);
        if(nums1.size() == i) return nums2[j + k - 1];
        if(k == 1) return min(nums1[i], nums2[j]);
        int si = min((int)nums1.size(), i + k / 2), sj = j + k / 2;
        if(nums1[si - 1] > nums2[sj - 1]) 
            return findKthNumber(nums1, i, nums2, sj, k / 2);
        else 
            return findKthNumber(nums1, si, nums2, j, k / 2);
    }
};