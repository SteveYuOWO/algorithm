#include "iostream"
#include "vector"
#include "stack"
using namespace std;
int N, pre_index = 0, in_index = 0, tmp_i;
stack<int> sta;
int pre[99999], in[99999];
vector<int> post;
void build_post(int root, int start, int end) {
    if(start > end) return;
    int i = start;
    while(i < end && pre[root] != in[i]) i++;
    build_post(root + 1, start, i - 1);
    build_post(root + 1 + (i - start), i + 1, end);
    post.push_back(in[i]);
}
int main() {
    scanf("%d", &N);
    string tmp;
    while(N != pre_index || !sta.empty()) {
        cin >> tmp;
        if(tmp[1] == 'u') {
            cin >> tmp_i;
            pre[pre_index++] = tmp_i;
            sta.push(tmp_i);
        } else {
            in[in_index++] = sta.top();
            sta.pop();
        }
    }
    build_post(0, 0, N - 1);
    printf("%d", post[0]);
    for(int i = 1; i < N; i++) 
        printf(" %d", post[i]);
    return 0;
}
