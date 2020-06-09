#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    string A, B;
    unordered_map<char, int> m;
    int lost = 0;
    getline(cin, A);
    getline(cin, B);
    for(int i = 0; i < A.length(); i++)
        m[A[i]]++;
    for(int i = 0; i < B.length(); i++)
        if(m[B[i]] > 0) m[B[i]]--;
        else lost++;
    if(lost != 0) cout << "No " << lost;
    else cout << "Yes " << A.length() - B.length();
    return 0;
}
