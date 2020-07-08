#include <iostream>
#include <deque>
using namespace std;
int main(){
    int N, R;
    cin >> N >> R;
    deque<int> d, dr;
    while(N != 0){
        d.push_back(N % R);
        dr.push_front(N % R);
        N /= R;
    }
    bool right = true;
    for(int i = 0; i < d.size(); i++)
        if(d[i] != dr[i]) right = false;
    cout << (right ? "Yes" : "No") << endl;
    for(int i = 0; i < dr.size(); i++)
        if(i != 0) cout << " " << dr[i];
        else cout << dr[i];
    return 0;
}
