#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    priority_queue<int, vector<int>, greater<int>> a;
    a.push(1);
    a.push(2);
    a.push(3);
    cout << a.top();
    a.pop();
    a.pop();
    a.pop();
    cout << a.size();
    return 0;
}