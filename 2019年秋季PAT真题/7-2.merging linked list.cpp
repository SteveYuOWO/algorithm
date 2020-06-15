#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int start1, start2, N;
struct node {
    int addr, data, next;
}tmp;
unordered_map<int, node> m;
int main() {
    scanf("%d%d%d", &start1, &start2, &N);
    for(int i = 0; i < N; i++) {
        scanf("%d%d%d", &tmp.addr, &tmp.data, &tmp.next);
        m[tmp.addr] = tmp;
    }
    deque<node> list1, list2;
    vector<node> ans;
    while(start1 != -1) {
        list1.push_back(m[start1]);
        start1 = m[start1].next;
    }
    while(start2 != -1) {
        list2.push_back(m[start2]);
        start2 = m[start2].next;
    }
    if(list1.size() < list2.size()) swap(list1, list2);
    while(!list1.empty() || !list2.empty()) {
        if(!list1.empty()) {
            ans.push_back(list1.front());
            list1.pop_front();
        }
        if(!list1.empty()) {
            ans.push_back(list1.front());
            list1.pop_front();
        }
        if(!list2.empty()) {
            ans.push_back(list2.back());
            list2.pop_back();
        }
    }
    printf("%05d %d", ans[0].addr, ans[0].data);
    for(int i = 1; i < ans.size(); i++) 
        printf(" %05d\n%05d %d", ans[i].addr, ans[i].addr, ans[i].data);
    printf(" -1\n");
    return 0;
}