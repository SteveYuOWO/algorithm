#include <iostream>
using namespace std;
int main() {
    int N, arr[200], judge[200];
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    for(int i = 1; i <= N - 1; i++) {
        for(int j = i + 1; j <= N; j++) {
            int cnt = 0, wolfcnt = 0;
            fill(judge + 1, judge + N + 1, 1); // 1代表好人
            judge[i] = judge[j] = -1; // -1代表狼
            for(int k = 1; k <= N; k++) 
                if(judge[abs(arr[k])] * arr[k] < 0) cnt++; 
            
            if(judge[abs(arr[i])] * arr[i] < 0) wolfcnt++;
            if(judge[abs(arr[j])] * arr[j] < 0) wolfcnt++;
            if(cnt == 2 && wolfcnt == 1) {
                cout << i << " " << j << endl;
                exit(0);
            }
        }
    }
    cout << "No Solution" << endl;
    return 0;
}