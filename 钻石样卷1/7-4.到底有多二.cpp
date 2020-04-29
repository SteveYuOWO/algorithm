#include <iostream>
using namespace std;
int main() {
    int year, diff, cnt = 0;
    cin >> year >> diff;
    while(true) {
        int tmp[10] = {0}, cal = 0;
        tmp[year % 10]++;
        tmp[year / 10 % 10]++;
        tmp[year / 100 % 10]++;
        tmp[year / 1000]++;
        for(int i = 0; i < 10; i++) 
            if(tmp[i]) cal++;
        if(cal == diff) {
            printf("%d %04d", cnt, year);
            break;
        }
        cnt++;
        year++;
    }
    return 0;
}