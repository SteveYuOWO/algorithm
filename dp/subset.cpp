#include <iostream>
using namespace std;
int arr[] = { 3, 34, 4, 12, 2 };
bool subset(int i, int sum) {
    if(sum == 0) return true;
    else if(i == 0) return arr[0] == sum;
    else if(arr[i] > sum) return subset(i - 1, sum);
    else return subset(i - 1, sum - arr[i]) || subset(i - 1, sum);
}
int main() {
    printf("%d", subset(4, 4));
    return 0;
}
