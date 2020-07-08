#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    char ch[] = "0123456789ABC";
    scanf("%d%d%d", &a, &b, &c);
    printf("#%c%c%c%c%c%c", ch[a/13], ch[a%13], ch[b/13], ch[b%13], ch[c/13], ch[c%13]);
    return 0;
}
