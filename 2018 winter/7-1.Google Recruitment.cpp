#include <iostream>
using namespace std;
int L, K, flag = 1;
string str;
bool isPrime(int N) {
    if(N < 2) return false;
    for(int i = 2; i * i <= N; i++)
        if(N % i == 0) return false;
    return true;
}
int main() {
    cin >> L >> K >> str;
    for(int i = 0; i < str.length() - K + 1; i++) {
        if(isPrime(stoi(str.substr(i, K)))) {
            flag = 0;
            cout << str.substr(i, K) << endl;
            break;
        }
    }
    if(flag) cout << "404" << endl;
    return 0;
}
