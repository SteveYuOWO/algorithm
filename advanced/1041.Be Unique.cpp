#include <iostream>
using namespace std;
int m[10000] = {0};
int main(){
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        m[arr[i]]++;
    }
    for(int i = 0; i < N; i++){
        if(m[arr[i]] == 1){
            cout << arr[i];
            return 0;
        }
    }
    cout << "None";
    return 0;
}
