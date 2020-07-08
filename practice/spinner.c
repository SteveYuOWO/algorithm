#include <stdio.h>
#include <unistd.h>
int main() {
    char ch[5] = "-\\|/";
    while(1) {
        for(int i = 0; i < 4; i++) {
            printf("\r%c", ch[i]);
            fflush(stdout);
            sleep(1);
        }
    }
    return 0;
}
