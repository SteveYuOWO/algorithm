#include <iostream>
using namespace std;

#define vMax 100   //最大结点数
#define lMax 100   //最长边长度
#define inf 10001    //不可达长度
typedef int vertex;  //顶点类型


int G[vMax][vMax] = {};  //图的初始化
int Nv, Ne;              //结点和边

int D[vMax][vMax];       //最短距离矩阵

void Read() {            //图的邻接矩阵
    vertex v1, v2;
    int len;
    for (int i = 0; i < Ne; i++) {
        cin >> v1 >> v2 >> len;
        v1--;
        v2--;
        G[v1][v2] = len;
        G[v2][v1] = len;
    }
}

void floyd() {           //floyd算法
    //距离矩阵的初始化
    for(int i=0;i<Nv;i++)
        for (int j = 0; j < Nv; j++) {
            if (G[i][j])D[i][j] = G[i][j];
            else D[i][j] = inf;
        }
    //遍历中间点k
    for(int k=0;k<Nv;k++)
        for(int i=0;i<Nv;i++)
            for (int j = 0; j < Nv; j++) {
                if (D[i][j] > D[i][k] + D[k][j])
                    D[i][j] = D[i][k] + D[k][j];
 }
}

int findMAxDist(int i) {
    int maxDist = 0;
    for (int j = 0; j < Nv; j++) {
        if (D[i][j] > maxDist&& i != j)
            maxDist = D[i][j];
    }
    return maxDist;
}

void findAnimal() {       //查找应该带的动物
    int animal, anidist;     //动物编号和最短距离
    anidist = inf;
    int maxDist;     //最难变的动物符号长度
    for (int i = 0; i < Nv; i++) {
        maxDist = findMAxDist(i);
        if (maxDist == inf) {
            printf("0");
            return;
        }
        if (anidist > maxDist) {
            animal = i;
            anidist = maxDist;
        }
    }
    cout << animal + 1 << " " << anidist;
}

int main()
{
    cin >> Nv >> Ne;
    Read();
    floyd();
    findAnimal();
}

