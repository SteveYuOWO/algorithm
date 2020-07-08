#include <iostream>
#include <vector>
using namespace std;
struct frac{
    long long up, down, sign = 1;
};
long long gcd(long long a, long long b) {
    return b == 0 ? a: gcd(b, a%b);
}
int main() {
    long long N, multi = 1, sum = 0;
    scanf("%lld", &N);
    vector<frac> v;
    for(int i = 0; i < N; i++) {
        frac tmp;
        scanf("%lld/%lld", &tmp.up, &tmp.down);
        if(tmp.up < 0) {
            tmp.sign = -1;
            tmp.up = -tmp.up;
        }
        v.push_back(tmp);
        multi = multi * tmp.down;
    }
    for(int i = 0; i < N; i++)
        sum += (multi / v[i].down * v[i].up * v[i].sign);
    if(sum < 0) printf("-");
    if(sum == 0) {
        printf("0");
        return 0;
    }
    sum = abs(sum);
    int integer = sum / multi, blank = 0;
    sum %= multi;
    if(integer > 0) {
        printf("%d", integer);
        blank = true;
    }
    long long m = gcd(multi, sum);
    if(sum != 0) {
        if(blank) printf(" ");
        printf("%lld", sum/m);
        if(multi/m != 1L) printf("/%lld", multi/m);
    }
    return 0;
}
