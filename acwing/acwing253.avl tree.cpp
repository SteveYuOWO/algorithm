#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, INF = 1e8

int n;
struct node {
    int l, r, key, val, cnt, size;
}tr[N];

int root, idx;

int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;
    return idx;
}

void build() {
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
}
int main() {
    build();
    return 0;
}