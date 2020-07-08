#include "iostream"
#include "vector"
#include "map"
using namespace std;
struct node {
    int val, addr, next;
}tmp;
vector<node> v, tmp_v, ans;
map<int, node> m;
int main() {
    int start, N, K;
    scanf("%d%d%d", &start, &N, &K);
    for(int i = 0; i < N; i++) { // 读数
        scanf("%d%d%d", &tmp.addr, &tmp.val, &tmp.next);
        m[tmp.addr] = tmp;
    }
    while(start != -1) { // 顺序化链表
        v.push_back(m[start]);
        start = m[start].next;
    }
    for(int i = 0; i < v.size(); i++) {
        tmp_v.push_back(v[i]); 
        if(tmp_v.size() == K) { // k个反转
            for(int j = tmp_v.size() - 1; j >= 0; j--)
                ans.push_back(tmp_v[j]);
            tmp_v.clear();
        }
    }
    for(int  i = 0; i < tmp_v.size(); i++) 
        ans.push_back(tmp_v[i]); // 剩余顺序放入
    for(int i = 0; i < ans.size(); i++)  // 打印
        if(i == 0) printf("%05d %d", ans[i].addr, ans[i].val);
        else printf(" %05d\n%05d %d", ans[i].addr, ans[i].addr, ans[i].val);
    if(ans.size() != 0) printf(" -1");
    return 0;
}