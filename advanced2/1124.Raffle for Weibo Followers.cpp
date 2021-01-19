#include <iostream>
#include <map>
using namespace std;
int M, N, S;
char arr[99999][25];
map<string, bool> m;
int main() {
    scanf("%d%d%d", &M, &N, &S);
    for(int i = 1; i <= M; i++) 
        scanf("%s", arr[i]);
    for(int i = S; i <= M; i += N) {
        while(i <= M && m[arr[i]] == 1) i++;
        if(i > M) break;
        printf("%s\n", arr[i]);
        m[arr[i]] = 1;
    }
    if(m.size() == 0) printf("Keep going...\n");
    return 0;
}