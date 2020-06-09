#include <iostream>
typedef pair<int,int> P;
struct edge{int to,cost;};
vector<edge> es[MAX];
bool vis[MAX];
int d[MAX];
int V,E;

bool SPFA(int s) //s为起点 存在负环返回true,否则返回false
{
    queue<P> que;
    for(int i=1;i<=V;i++) d[i]=INF_INT,vis[i]=false; //点编号从1开始
    d[s]=0;vis[s]=true;
    que.push(P(s,0));
    while(que.size())
    {
        P p=que.front();que.pop();
        if(p.second>=V) return true;
        int x=p.first;
        vis[x]=false;
        for(int i=0;i<es[x].size();i++)
        {
            edge e=es[x][i];
            if(d[e.to]>d[x]+e.cost)
            {
                d[e.to]=d[x]+e.cost;
                if(!vis[e.to]) que.push(P(e.to,p.second+1));
            }
        }
    }
    return false;
}