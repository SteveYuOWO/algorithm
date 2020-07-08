#include <iostream>
#include <deque>
using namespace std;
int main() {
    int a, b, first = 0, index = 0;
    deque<char> deq;
    scanf("%d%d", &a, &b);
    string ans = to_string(a + b);
    for(int i = 0; i < ans.size(); i++) deq.push_back(ans[i]);
    if(deq[0] == '-') {
        putchar('-');
        deq.pop_front();
    }
    while(deq.size()) {
        putchar(deq[0]);
        deq.pop_front();
        if(deq.size() % 3 == 0 && deq.size()) putchar(',');
    }
    return 0;
}
