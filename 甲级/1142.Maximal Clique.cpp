#include <iostream>
using namespace std;
int N, M, K, G[300][300] = {0}, a, b, sz, *arr;
int main() {
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d", &a, &b);
        G[a][b] = G[b][a] = 1;
    }
    scanf("%d", &K);
    while(K--) {
        int m[300] = {0};
        bool notClique = false, notMaximal = false;
        scanf("%d", &sz);
        arr = new int(sz);
        for(int i = 0; i < sz; i++) {
            scanf("%d", &arr[i]);
            m[arr[i]] = 1;
        }
        for(int i = 0; i < sz - 1; i++) 
            for(int j = i + 1; j < sz; j++) 
                if(G[arr[i]][arr[j]] == 0) notClique = true;
        if(notClique) printf("Not a Clique\n");
        else {
            // check maximal
            for(int i = 1; i <= N; i++) {
                if(m[i] == 0) {
                    int judge = 0;
                    for(int j = 0; j < sz; j++) 
                        if(i != arr[j] && G[i][arr[j]] == 1) 
                            judge++;
                    if(judge == sz) {
                        notMaximal = true;
                        break;
                    }
                }
            }
            if(notMaximal) printf("Not Maximal\n");
            else printf("Yes\n");
        }
    }
    return 0;
}