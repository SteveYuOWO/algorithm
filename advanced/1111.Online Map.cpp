#include <iostream>
#include <vector>
#define INF 99999999
using namespace std;
int N, M, a, b, oneway, len, tim;
int L[550][550] = {0}, T[550][550] = {0}, vis[550] = {0};
int start, end0;
int main() {
    // input
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d%d%d%d", &a, &b, &oneway, &len, &tim);
        L[a][b] = len;
        T[a][b] = tim;
        if(oneway != 1) {
            L[b][a] = len;
            T[b][a] = tim;
        }
    }
    scanf("%d%d", &start, &end0);
    // Len & Time
    int dis[550], prevDis[550], weight[550];
    fill(weight, weight + 550, INF);
    fill(dis, dis + 550, INF);
    for(int i = 0; i < 550; i++)
        prevDis[i] = i;
    dis[start] = 0; weight[start] = 0;
    while(true) {
        int u = -1, minn = INF;
        for(int v = 0; v < N; v++) {
            if(!vis[v] && dis[v] < minn) {
                minn = dis[v];
                u = v;
            }
        }
        if(u == -1) break;
        vis[u] = 1;
        for(int v = 0; v < N; v++) {
            if(!vis[v] && L[u][v] != 0) {
                if(L[u][v] + dis[u] < dis[v]) {
                    dis[v] = L[u][v] + dis[u];
                    prevDis[v] = u;
                    weight[v] = weight[u] + T[u][v];
                } else if(L[u][v] + dis[u] == dis[v] && T[u][v] + weight[u] < weight[v]) {
                    prevDis[v] = u;
                    weight[v] = weight[u] + T[u][v];
                }
            }
        }
    }
    // Time & Node
    int time[550], prevTime[550], node[550];
    fill(time, time + 550, INF);
    fill(node, node + 550, INF);
    fill(vis, vis + 550, 0);
    for(int i = 0; i < 550; i++)
        prevTime[i] = i;
    time[start] = 0; node[start] = 0;
    while(true) {
        int u = -1, minn = INF;
        for(int v = 0; v < N; v++) {
            if(!vis[v] && time[v] < minn) {
                minn = time[v];
                u = v;
            }
        }
        if(u == -1) break;
        vis[u] = 1;
        for(int v = 0; v < N; v++) {
            if(!vis[v] && T[u][v] != 0) {
                if(T[u][v] + time[u] < time[v]) {
                    time[v] = T[u][v] + time[u];
                    prevTime[v] = u;
                    node[v] = node[u] + 1;
                } else if(T[u][v] + time[u] == time[v] && node[u] + 1 < node[v]) {
                    prevTime[v] = u;
                    node[v] = node[u] + 1;
                }
            }
        }
    }
    // deal with path
    int cp = end0, ans_dis = 0, ans_tim = 0, cp1 = end0, ans_dis1 = 0, ans_tim1 = 0;
    vector<int> ans1, ans2;
    while(cp != start) {
        int tmp = cp;
        ans1.push_back(cp);
        cp = prevDis[cp];
        ans_dis += L[cp][tmp];
        ans_tim += T[cp][tmp];
    }
    while(cp1 != start) {
        int tmp = cp1;
        ans2.push_back(cp1);
        cp1 = prevTime[cp1];
        ans_dis1 += L[cp1][tmp];
        ans_tim1 += T[cp1][tmp];
    }
    if(ans1 != ans2) {
        printf("Distance = %d: %d", ans_dis, start);
        for(int i = ans1.size() - 1; i >= 0; i--)
            printf(" -> %d", ans1[i]);
        putchar('\n');
        printf("Time = %d: %d", ans_tim1, start);
        for(int i = ans2.size() - 1; i >= 0; i--)
            printf(" -> %d", ans2[i]);
        putchar('\n');
    } else {
        printf("Distance = %d; Time = %d: %d", ans_dis, ans_tim, start);
        for(int i = ans1.size() - 1; i >= 0; i--)
            printf(" -> %d", ans1[i]);
        putchar('\n');
    }

    return 0;
}