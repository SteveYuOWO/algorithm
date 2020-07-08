#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, index_v = 0 ;
vector<int> v, res;
void inorder(int index_res){
    if(index_res >= N) return;
    inorder(2 * index_res + 1);
    res[index_res] = v[index_v++];
    inorder(2 * index_res + 2);
}
int main(){
    cin >> N;
    v.resize(N);
    res.resize(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    inorder(0);
    cout << res[0];
    for(int i = 1; i < N; i++)
        cout << " " << res[i];
    return 0;
}
