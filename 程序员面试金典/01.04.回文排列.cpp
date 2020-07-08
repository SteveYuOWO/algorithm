#include <iostream>
using namespace std;
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int arr[200] = {0}, odd = 0;
        for(int i = 0; i < s.length(); i++) 
            arr[s[i]]++;
        for(int i = 0; i < 200; i++)
            if(arr[i] % 2 != 0) odd++;
        return odd < 2;
    }
};