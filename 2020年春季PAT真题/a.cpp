#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    vector<int> v2;
    v2 = v;
    v[0] = 100;
    for(auto x: v2) cout << x << endl;
    return 0;
}