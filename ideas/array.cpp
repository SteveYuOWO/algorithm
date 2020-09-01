#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> v{5, 2, -1, 1, 3, 4}; // 选 5 3 1 = 9
int dfs(int sum, int index, unordered_map<int, int>& m) {
    if(index >= v.size()) return sum;
    int a = -1;
    if(!m[v[index] + 1] && !m[v[index] - 1]) { // v[index] + 1 和 - 1 都没访问过
        m[v[index]] = true;
        a = dfs(sum + v[index], index + 1, m);
        m[v[index]] = false;
    }
    int b = dfs(sum, index + 1, m);
    return max(a, b);
}   
int main() {
    unordered_map<int, int> m;
    cout << dfs(0, 0, m) << endl;
    return 0;
}