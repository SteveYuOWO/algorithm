#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> s;
    int N, tmp;
    scanf("%d", &N);
    while(N--) {
        int sum = 0;
        scanf("%d", &tmp);
        while(tmp != 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        s.insert(sum);
    }
    auto it = s.begin();
    printf("%lu\n%d", s.size(), *it++);
    while(it != s.end()) printf(" %d", *it++);
    return 0;
}