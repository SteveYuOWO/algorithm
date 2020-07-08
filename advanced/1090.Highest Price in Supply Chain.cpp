#include "iostream"
#include "vector"
using namespace std;
int N, root, tmp, cnt = 0;
double P, R, max_price = -1;
struct node{
    double price =  -1;
    vector<int> child;
}n[999999];
void dfs(int root, double price) {
    n[root].price = price;
    if(n[root].price > max_price) {
        max_price = n[root].price;
        cnt = 1;
    }else if(n[root].price == max_price) cnt++;
    for(int i = 0; i < n[root].child.size(); i++) 
        dfs(n[root].child[i], price * (1.0 + R / 100.0));
}
int main() {
    scanf("%d%lf%lf", &N, &P, &R);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        if(tmp == -1) root = i;
        else n[tmp].child.push_back(i);
    }
    dfs(root, P);
    printf("%.2lf %d", max_price, cnt);
    return 0;
}
