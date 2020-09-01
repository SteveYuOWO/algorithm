#include <iostream>
#include <string>
using namespace std;
bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}   
int main() {
    int N, M;
    string s;
    cin >> N >> M >> s;
    for(int i = 0; i < s.size() - M + 1; i++)
        if(isPrime(stoi(s.substr(i, M)))) {
            printf("%s\n", s.substr(i, M).c_str());
            exit(0);
        }
    printf("404");
    return 0;
}