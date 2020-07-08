#include <iostream>
using namespace std;
string m[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main() {
    int sum = 0;
    string str, str_sum;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++)
        sum += (str[i] - '0');
    str_sum = to_string(sum);
    printf("%s", m[str_sum[0] - '0'].data());
    for(int i = 1; i < str_sum.size(); i++)
        printf(" %s", m[str_sum[i] - '0'].data());
    system("pause");
    return 0;
}
