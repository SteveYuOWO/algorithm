#include <iostream>
#include <vector>
using namespace std;
int process(string s, int score, int l, int r) {
    if(l > r) return score;
    // 选左边
    int left = process(s, score + (s[l] - '0'), l + 1, r - 1);
    // 选右边
    int right = process(s, score + (s[r] - '0'), l + 1, r - 1);
    return max(left, right);
}
int main() {
    string s = "8219";
    cout << process(s, 0, 0, s.size() - 1);
    return 0;
}