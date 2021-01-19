#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    long int N, sqrt_n;
    cin >> N;
    sqrt_n = sqrt(N);
    vector<int> m, tmp_v;
    for(int i = 2; i <= sqrt_n; i++){
        int cp_i = i, sum = i;
        while(N % sum == 0 && cp_i <= sqrt_n){
            tmp_v.push_back(cp_i);
            cp_i++;
            sum *= cp_i;
        }
        if(tmp_v.size() > m.size())
            m = tmp_v;
        tmp_v.clear();
    }
    if(m.size() == 0) cout << 1 << endl << N;
    else {
        cout << m.size() << endl;
        for(int i = 0; i < m.size(); i++)
            if(i != m.size() - 1) cout << m[i] << "*";
            else cout << m[i];
    }
    return 0;
}
