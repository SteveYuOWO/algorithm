#include <iostream>
using namespace std;
string s = "2";
bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}
void add(int i) {
    int n = s.size() - i;
    if(s[n] == '2') s[n] = '3';
    else if(s[n] == '3') s[n] = '5';
    else if(s[n] == '5') {
        s[n] = '2';
        if(n == 0) s = "2" + s;
        else add(i + 1);
    }
    if(!isPrime(stoi(s))) add(1);
}
int main() {
    int N; 
    scanf("%d", &N);
    N--;
    while(N--) add(1);
    cout << s << endl;
    return 0;
}