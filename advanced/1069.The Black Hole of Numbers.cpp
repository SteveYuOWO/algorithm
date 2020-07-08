#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    string str, rev;
    do {
        str = to_string(N);
        while(str.length() != 4) str = "0" + str;
        sort(str.begin(), str.end());
        rev = str;
        reverse(rev.begin(), rev.end());
        N = stoi(rev) - stoi(str);
        printf("%s - %s = %04d\n", rev.c_str(), str.c_str(), N);
    }while(N != 0 && N != 6174);
    return 0;
}
