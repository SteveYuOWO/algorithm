#include <iostream>
#include <string>
using namespace std;
bool isPrime(int N){
    if(N <= 1) return false;
    if(N == 2 || N == 3) return true;
    for(int i = 2; i * i <= N; i++)
        if(N % i ==0) return false;
    return true;
}
int rev(int N, int radix){
    string s = "";
    while(N != 0){
        s += (N % radix);
        N /= radix;
    }
    int p = 1, res = 0;
    for(int i = s.length()-1; i >= 0; i--){
        res += (s[i] * p);
        p *= radix;
    }
    return res;
}
int main(){
    int num, radix;
    while(true){
        cin >> num;
        if(num < 0) break;
        else {
            cin >> radix;
            int rev_num = rev(num, radix);
            if(isPrime(num) && isPrime(rev_num))
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
