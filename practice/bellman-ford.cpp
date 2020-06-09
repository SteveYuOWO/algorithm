struct edge{ int from, to, cost; };
edge es[MAX];
int d[MAX];
int V, E;

bool Bellman_Ford(int s) //起点 如果存在负环返回true,否则返回true
{
    for(int i = 1;i <= V; i++) d[i] = INF_INT; //点从1开始编号
    d[s]=0;
    int cnt=0; //用来数更新多少次
    while(true) {
        bool update = false;
        for(int i = 0; i < E; i++) {
            edge e = es[i];
            if(d[e.from] != INF_INT && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update||cnt>=V) break;
        cnt++;
    }
    if(cnt>=V) return true;
    return false;
}