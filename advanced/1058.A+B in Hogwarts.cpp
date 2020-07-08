#include <iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f;
    scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&d,&e,&f);
    a+=d;b+=e;c+=f;
    b+=c/29;c%=29;
    a+=b/17;b%=17;
    printf("%d.%d.%d",a,b,c);
    return 0;
}
