#include <iostream>
using namespace std;
bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++) 
        if(n % i == 0) return false;
    return true;
}
int main() {
    string str; bool flag = true;
    cin >> str;
    while(str != "") {
        bool ok = isPrime(stoi(str));
        printf("%s %s\n", str.c_str(), ok ? "Yes": "No");
        if(!ok) flag = false;
        str = str.substr(1);
    }
    if(flag) printf("All Prime!\n");
    return 0;
}