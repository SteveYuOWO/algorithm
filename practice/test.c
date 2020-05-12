#include <stdio.h>
int main() {
    char ch[100];
    FILE *f = fopen("a.txt", "r");
    fscanf(f, "%s", ch);
    puts(ch);
    fscanf(f, "%s", ch);
    puts(ch);
    return 0;
}