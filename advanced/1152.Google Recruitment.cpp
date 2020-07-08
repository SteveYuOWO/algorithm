#include <iostream>
using namespace std;
bool isPrime(int N) {
    if(N == 2 || N == 3) return true;
    for(int i = 2; i * i <= N; i++) 
        if(N % i == 0) return  false;
    return true;
}
int main() {
    int L, K;
    string data;
    cin >> L >> K >> data;
    for(int i = 0; i < data.length() - K + 1; i++) {
        string tmp_str = data.substr(i, K);
        int tmp = stoi(tmp_str);
        bool right = isPrime(tmp);
        if(right) {
            printf("%s", tmp_str.c_str());
            exit(0);
        } 
    }
    printf("404");
    return 0;
}