#include "iostream"
#include "vector"
#include "map"
using namespace std;
int N, M, tmp1, tmp2;
map<int, int, greater<int>> poly, poly2, mul, sum;
vector<pair<int, int>> mul_v, sum_v;
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &tmp1, &tmp2);
        poly[tmp2] += tmp1;
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &tmp1, &tmp2);
        poly2[tmp2] += tmp1;
    }
    for(auto x: poly) 
        for(auto y: poly2) 
            mul[x.first + y.first] += (x.second * y.second);
    for(auto it = mul.begin(); it != mul.end(); it++)
        if(it->second != 0) mul_v.push_back({it->first, it->second});
    for(auto x: poly) 
        sum[x.first] += x.second;
    for(auto x: poly2)
        sum[x.first] += x.second;
    for(auto it = sum.begin(); it != sum.end(); it++)
        if(it->second != 0) sum_v.push_back({it->first, it->second});
    if(mul_v.size() == 0) printf("0 0");
    else {
        for(int i = 0; i < mul_v.size(); i++)
        if(i == 0) printf("%d %d", mul_v[i].second, mul_v[i].first);
        else  printf(" %d %d", mul_v[i].second, mul_v[i].first);
    }
    if(sum_v.size() == 0) printf("\n0 0");
    else {
        for(int i = 0; i < sum_v.size(); i++)
        if(i == 0) printf("\n%d %d", sum_v[i].second, sum_v[i].first);
        else  printf(" %d %d", sum_v[i].second, sum_v[i].first);
    }
    
    return 0;
}