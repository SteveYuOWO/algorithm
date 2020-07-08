#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int M, N;
    scanf("%d", &M);
    vector<pair<int, double>> poly1(M);
    for(int i = 0; i < M; i++)
        scanf("%d%lf", &poly1[i].first, &poly1[i].second);
    scanf("%d", &N);
    vector<pair<int, double>> poly2(N);
    for(int i = 0; i < N; i++)
        scanf("%d%lf", &poly2[i].first, &poly2[i].second);
    map<int, double, greater<int>> m;
    for(int i = 0; i < poly1.size(); i++)
        for(int j = 0; j < poly2.size(); j++)
            m[poly1[i].first + poly2[j].first] += poly1[i].second * poly2[j].second;
    for(auto it = m.begin(); it != m.end(); it++)
        if(it->second == 0) m.erase(it);
    printf("%d", m.size());
    for(auto it=m.begin();it!=m.end();it++)
        printf(" %d %.1f",it->first,it->second);
    system("pause");
    return 0;
}
