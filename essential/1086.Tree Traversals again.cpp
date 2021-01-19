#include <iostream>
#include <stack>
using namespace std;
int N, pre[50], in[50], post[50], tmp, p, ii, i, po;
stack<int> s; string str;
void getPost(int index, int start, int end) {
    if(start > end) return;
    int k = 0; 
    while(k < end && pre[index] != in[k]) k++;
    getPost(index + 1, start, k -1);
    getPost(index + 1 + k - start, k + 1, end);
    post[po++] = in[k];
}
int main() {
    // freopen("in.txt", "r", stdin);
    cin >> N;
    while(i < N || s.size()) {
        cin >> str;
        if(str[1] == 'u') {
            cin >> tmp;
            s.push(tmp);
            pre[p++] = tmp;
            i++;
        }
        else {
            in[ii++] = s.top(); 
            s.pop();
        }
    }
    getPost(0, 0, N - 1);
    printf("%d", post[0]);
    for(int i = 1; i < N; i++) printf(" %d", post[i]);
    return 0;
}