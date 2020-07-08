#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> res;
    int N, Max = -1;
    cin >> N;
    int arr[N], cp[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        cp[i] = arr[i];
    }
    sort(cp, cp+N);
    for(int i = 0; i < N; i++){
        if(cp[i] == arr[i] && arr[i] > Max)
            res.push_back(arr[i]);
        if(arr[i] > Max) Max = arr[i];
    }
    printf("%d\n",res.size());
    for(int i = 0; i < res.size(); i++)
        if(i != res.size() - 1) printf("%d ", res[i]);
        else printf("%d", res[i]);
    printf("\n");
    return 0;
}
