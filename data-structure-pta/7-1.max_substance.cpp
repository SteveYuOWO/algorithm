#include <iostream>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    int sum = 0, max_sum = 0, tmp;
    for(int i = 0; i < N; i++){
        scanf("%d", &tmp);
        sum += tmp;
        if(sum < 0) sum = 0;
        if(sum > max_sum) max_sum = sum;
    }
    printf("%d", max_sum);
    return 0;
}
