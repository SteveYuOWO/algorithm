#include <iostream>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    long long P = 0, A = 0, T = 0, sum = 0;
    for(int i = 0; i < s.length(); i++)
        if(s[i] == 'T') T++;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'P') P++;
        if(s[i] == 'T') T--;
        if(s[i] == 'A') sum += ((P % 1000000007 * T % 1000000007) % 1000000007);
    }
    cout << sum % 1000000007;
    return 0;
}
