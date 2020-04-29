#include "iostream"
#include "string"
#include "stack"
using namespace std;
int N, start = true;
string str;
int pre[10000], in[10000], pre_i = 0, in_i = 0;
int post[10000], post_i = 0;
void get_post(int root, int start, int end) {
    if(start > end) return;
    int i = start;
    while(i < end && pre[root] != in[i]) i++;
    get_post(root + 1, start, i - 1);
    get_post(root + 1 + i - start, i + 1, end);
    post[post_i++] = in[i];
}
int main() {
    stack<int> sta;
    scanf("%d", &N);
    while(pre_i != N || in_i != N) {
        cin >> str;
        if(str[1] == 'u') {
            cin >> str;
            pre[pre_i++] = stoi(str);
            sta.push(pre[pre_i - 1]);
        }
        else {
            in[in_i++] = sta.top();
            sta.pop();
        }
    }
    get_post(0, 0, N - 1);
    printf("%d", post[0]);
    for(int i = 1; i < N; i++) 
        printf(" %d", post[i]);
    return 0;
}