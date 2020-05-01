#include <unistd.h>
int main() {
    char buf[100];
    read(0, buf, sizeof(buf));
    puts(buf);
    return 0;
}