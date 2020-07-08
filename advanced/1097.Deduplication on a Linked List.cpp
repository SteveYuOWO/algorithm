#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct node {
    int addr, val, next;
};
int main() {
    int start;
    int N;
    node tmp;
    vector<node> v, v_del;
    unordered_map<int, node> m;
    cin >> start >> N;
    while(N--) {
        cin >> tmp.addr >> tmp.val >> tmp.next;
        m[tmp.addr] = tmp;
    }
    unordered_map<int, bool> has;
    while(start != -1) {
        if(!has[abs(m[start].val)]) {
            v.push_back(m[start]);
            has[abs(m[start].val)] = true;
        }else v_del.push_back(m[start]);
        start = m[start].next;
    }
    for(int i = 0; i < v.size(); i++)
        if(i == 0) printf("%05d %d ", v[i].addr, v[i].val);
        else printf("%05d\n%05d %d ", v[i].addr, v[i].addr, v[i].val);
    printf("-1\n");
    if(v_del.size() > 0) {
        for(int i = 0; i < v_del.size(); i++)
            if(i == 0) printf("%05d %d ", v_del[i].addr, v_del[i].val);
            else printf("%05d\n%05d %d ", v_del[i].addr, v_del[i].addr, v_del[i].val);
        printf("-1\n");
    }
    return 0;
}
