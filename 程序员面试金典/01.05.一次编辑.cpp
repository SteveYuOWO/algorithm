#include <iostream>
using namespace std;
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int s1 = first.size(), s2 = second.size();
        if (abs(s1 - s2) > 1) return false;
        if (s1 < s2) return oneEditAway(second, first);
        for (int i = 0, edit = 0; i < s1; i++) {
            if (first[i] != second[i - (s1 - s2) * edit] && ++edit > 1) {
                return false;
            }
        }
        return true;
    }
};