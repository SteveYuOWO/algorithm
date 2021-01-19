# include <stdio.h>
int x=1;

int f(int x)
{   
    static int k=0;
    return (k++) + x;
}

int main()
{   int k;
    for(k=1; k<4; k++)
        f(k + x);
          printf("%d#", f(k+x)); // 执行 3 次
            // f(1 + 1) f(2 + 1) f(3 + 1)
            // f(2) f(3) f(4)
}