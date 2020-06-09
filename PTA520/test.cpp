#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
long long a, b;
stack<int> s;
long long factorial(int a) {
    if(a == 1) return 1;
    long long tmp = a * factorial(a - 1);
    for(int i = 0; i < b * 10 && tmp != 0; i++) {
        s.push(tmp % 10);
        tmp /= 10;
    }
    long long ans = 0;
    while(!s.empty()) {
        ans = ans * 10 + s.top();
        s.pop();
    }
    return ans;
}
int main() {
    cin >> a >> b;
    long long ans = factorial(a), zero = 0;
    string pri;
    while(ans % 10 == 0) {
        zero++;
        ans /= 10;
    }
    while(b--) {
        pri = to_string(ans % 10) + pri;
        ans /= 10;
    }
    printf("%s %lld", pri.c_str(), zero);
    return 0;
}