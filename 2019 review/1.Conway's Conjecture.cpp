#include <iostream>
using namespace std;
bool isPrime(long long N) {
    if(N < 2) return false;
    for(long long i = 2; i * i <= N; i++) 
        if(N % i == 0) return false;
    return true;
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    long long N;
    scanf("%lld", &N);
    string ans;
    if(N < 2) ans = to_string(N);
    else {
        for(long long i = 2; i <= N; i++) {
            int cnt = 0;
            while(N % i == 0) {
                N /= i;
                cnt++;
            }
            if(cnt != 0) {
                ans += to_string(i);
                if(cnt != 1) ans += to_string(cnt);
            }
        }
    }
    
    printf("%s\n%s", ans.c_str(), isPrime(stoll(ans)) ? "Yes": "No");
    return 0;
}
