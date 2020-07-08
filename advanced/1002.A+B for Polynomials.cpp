#include <iostream>
#include <map>
using namespace std;
int main()
{
    int M, coef, coun=2;
    double expo;
    map<int, double, greater<int>> m;
    while(coun--){
        cin >> M;
        while(M--){
            cin >> coef >> expo;
            m[coef] += expo;
        }
    }
    for(auto it = m.begin(); it != m.end(); it++)
        if(it -> second == 0) m.erase(it);
    cout << m.size();
    for(auto it: m)
        printf(" %d %.1f", it.first, it.second);
    return 0;
}
