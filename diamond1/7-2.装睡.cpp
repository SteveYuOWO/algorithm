#include <iostream>
using namespace std;
int main() {
    int N, hu, mai;
    char name[100];
    scanf("%d", &N);
    while(N--) {
        scanf("%s%d%d", name, &hu, &mai);
        if(hu < 15 || hu > 20 || mai < 50 || mai > 70) 
            printf("%s\n", name);
    }
    return 0;
}