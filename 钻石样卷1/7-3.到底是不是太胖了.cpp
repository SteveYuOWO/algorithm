#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int N, height, weight;
    scanf("%d", &N);
    while(N--) {
        scanf("%d%d", &height, &weight);
        double biao = (height - 100.0) * 1.8;
        if(fabs(biao - weight) < (0.1 * biao)) printf("You are wan mei!\n");
        else if(biao < weight) printf("You are tai pang le!\n");
        else printf("You are tai shou le!\n");
    }
    return 0;
}
