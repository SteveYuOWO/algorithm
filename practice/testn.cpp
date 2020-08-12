#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
unordered_set<string> s;
void dfs(vector<int>& stu, vector<int>& room, string str) {
    if(str.size() == stu.size()) {
        s.insert(str);
        return;
    }
    for(auto r: room) dfs(stu, room, str + to_string(r));
}
int main() {
    vector<int> stu{1, 2, 3, 4}, room{1, 2, 3, 4, 5};
    dfs(stu, room, "");
    cout << "选择种类: " << s.size() << endl << "选择情况如下" << endl;
    for(auto c: s) cout << c << endl;
    return 0;
}
