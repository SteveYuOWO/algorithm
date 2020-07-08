#include <iostream>
using namespace std;
int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int i = 0;
    for(;; i++) if(a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G') break;
    switch(a[i]) {
        case 'A': printf("MON "); break;
        case 'B': printf("TUE "); break;
        case 'C': printf("WED "); break;
        case 'D': printf("THU "); break;
        case 'E': printf("FRI "); break;
        case 'F': printf("SAT "); break;
        case 'G': printf("SUN "); break;
    }
    while(++i) if(a[i] == b[i] && ((isdigit(a[i]) || (a[i] >= 'A' && a[i] <= 'N')))) break;
    if(isdigit(a[i])) printf("%02d:", a[i] - '0');
    else printf("%02d:", a[i] - 'A' + 10);
    for(i = 0;; i++) if(c[i] == d[i] && isalpha(c[i])) break;
    printf("%02d", i);
    system("pause");
    return 0;
}