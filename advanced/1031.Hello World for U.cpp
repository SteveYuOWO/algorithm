#include <iostream>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    int row, N = str.length(), recol;
    row = (N + 2) / 3 ;
    recol = (N + 2) / 3 + (N + 2) % 3 - 2;
    for(int i = 0; i < row; i++){
        cout << str[i];
        for(int j = 0; j < recol; j++)
            if(i != row - 1) cout << " ";
            else cout << str[j + row];
        cout << str[N - i -1] << endl;
    }
    return 0;
}
