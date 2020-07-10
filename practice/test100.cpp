#include <iostream>
#include <set>
using namespace std;
struct node {
    int k, v;
    bool operator<(const node& n) const {
        return (k + v) < (n.k + n.v);
        if ((k+v) == (n.k + n.v)) return false;
    }
};
int main(int argc, char const *argv[])
{
    set<node> s;
    int a, b;
    s.insert({1, 9});
    s.insert({2, 8});
    for(auto& x: s) cout << x.k << x.v << endl;
    return 0;
}
