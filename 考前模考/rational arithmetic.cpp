#include <iostream>
using namespace std;
long long a, b, c, d;
/** 最大公约数 */
long long gcd(long long n1, long long n2) {
    return n2 == 0 ? n1 : gcd(n2, n1 % n2);
}
/** 约分 */
void reduce(long long& n1, long long& n2) {
    long long num_gcd = gcd(abs(n1), abs(n2));
    if(num_gcd != 0) {
        n1 /= num_gcd;
        n2 /= num_gcd;
    }
}
/** 打印 */
void print(long long n1, long long n2) {
    reduce(n1, n2);
    if(n2 == 0) printf("Inf");
    else if(n1 == 0) printf("0");
    else {
        bool rightP = false;
        if(n1 * n2 < 0) {
            printf("(-");
            rightP = true;
        }
        n1 = abs(n1); n2 = abs(n2);
        if(n1 / n2 != 0) printf("%lld", n1/n2);
        if(n1 % n2 != 0 && n1 / n2 != 0) printf(" ");
        if(n1 % n2 != 0) printf("%lld/%lld", n1%n2, n2);
        if(rightP) printf(")");
    }
}
int main() {
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    reduce(a, b);
    reduce(c, d);
    /** 通分 */
    long long above1 = a * d, above2 = c * b, under = b * d;
    /** 计算 */
    long add = above1 + above2, un_add = under;
    long sub = above1 - above2, un_sub = under;
    long mul = above1 * above2, un_mul = under * under;
    long div = above1, un_div = above2;
    /** 打印 */
    print(a, b); printf(" + "); print(c, d); printf(" = "); print(add, un_add); printf("\n");
    print(a, b); printf(" - "); print(c, d); printf(" = "); print(sub, un_sub); printf("\n");
    print(a, b); printf(" * "); print(c, d); printf(" = "); print(mul, un_mul); printf("\n");
    print(a, b); printf(" / "); print(c, d); printf(" = "); print(div, un_div); printf("\n");
    return 0;
}
