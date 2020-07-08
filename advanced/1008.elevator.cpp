#include <iostream>
#include <map>
using namespace std;
int main() {
    int N, level = 0, tmp, sum = 0;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &tmp);
        if(tmp > level) sum = sum + (tmp - level) * 6 + 5;
        else sum = sum + (level - tmp) * 4 + 5;
        level = tmp;
    }
    cout << sum;
    return 0;
}
