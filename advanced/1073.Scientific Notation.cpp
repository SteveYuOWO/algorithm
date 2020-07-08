#include <iostream>
#include <deque>
using namespace std;
int main() {
    string str, move;
    getline(cin, str);
    deque<char> de, xi;
    if(str[0] == '-') putchar('-');
    int i = 1;
    while(isdigit(str[i])) de.push_back(str[i++]);
    i++;
    while(isdigit(str[i])) xi.push_back(str[i++]);
    i++;
    move = str[i++] == '-' ? "left": "right";
    int num = 0; // move_num
    while(i < str.size()) num = num * 10 + (str[i++] - '0');
    while(num--) {
        if(move == "left") {
            if(de.size() != 0) {
                xi.push_front(de.back());
                de.pop_back();
            } else xi.push_front('0');
        }else {
            if(xi.size() != 0) {
                de.push_back(xi.front());
                xi.pop_front();
            } else de.push_back('0');
        }
    }
    if(de.size() != 0) for(auto x: de) putchar(x);
    else putchar('0');
    if(xi.size() != 0) putchar('.');
    for(auto x: xi) putchar(x);
    return 0;
}
