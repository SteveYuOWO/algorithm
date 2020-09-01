#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int main() {
    freopen("in.txt", "r", stdin);
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> arr(N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    priority_queue<int, vector<int>, greater<int>> q;//模拟内存的排序，从小到大排列
    vector<int> v,line;//v存放下轮的数；line存放本轮的数
    int index = 0,count=0, last;
    for (; index < M; index++) q.push(arr[index]);
    while (count != N) {//如果从队列里出来的数小于N
        last = q.top();
        line.push_back(last);//根据有序性，每次列头的数会决定arr的下一个数去哪
        q.pop();
        count++;
        if (index < N) {//如果arr里还有数未处理
            if (arr[index] > last) q.push(arr[index++]);
            else v.push_back(arr[index++]);
        }
        if (q.empty()) {//当本轮的数已处理结束，即q为空
            for (int i = 0; i < line.size(); i++) {//输出line
                if (i != 0) printf(" ");
                printf("%d", line[i]);
            }
            printf("\n");
            line.clear();
            for (int i = 0; i < v.size(); i++)//v的数全都放到q里
                q.push(v[i]);
            v.clear();
        }
    }
}