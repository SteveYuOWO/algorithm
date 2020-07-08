#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct mooncake {
    double cnt, price;
};
vector<mooncake> v;
bool cmp(mooncake mc, mooncake mc2) {
    return mc.price * mc2.cnt < mc2.price * mc.cnt;
}
int main() {
    double N, target;
    scanf("%lf %lf", &N, &target);
    v.resize(N);
    for(int i = 0; i < N; i++)
        scanf("%lf", &v[i].price);
    for(int i = 0; i < N; i++)
        scanf("%lf", &v[i].cnt);
    sort(v.begin(), v.end(), cmp);
    double ans = 0;
    for(int i = 0; i < N && target != 0; i++){
        if(v[i].price <= target){
            target -= v[i].price;
            ans += v[i].cnt;
        }else {
            ans += (target * v[i].cnt / v[i].price);
            target = 0;
        }
    }
    printf("%.2f", ans);
    return 0;
}
