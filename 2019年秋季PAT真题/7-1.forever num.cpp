#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2, sqr = sqrt(x); i <= sqr; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int digitSum(int x) {
    int sum = 0;

    string s = to_string(x);
    for (int i = 0, len = s.length(); i < len; ++i)
        sum += s[i] - '0';

    return sum;
}

struct record {
    int sum, val;

    record(int v, int n) : val(v), sum(n) {}

    bool operator<(record &x) {
        if (sum != x.sum) return sum < x.sum;
        else return val < x.val;
    }
};

vector<record> r;

void dfs(int sum, int val, int left, int target) {
    if (left == 0 && sum == target) {
        int n = digitSum(val + 1), g = gcd(sum, n);
        if (g > 2 && isPrime(g)) r.push_back(record(val, n));
    } else if (left > 0)
        for (int i = 0; i <= 9; ++i)
            if (sum + i + left * 9 - 9 >= target && sum + i <= target)
                dfs(sum + i, val * 10 + i, left - 1, target);
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, k, m;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        r.clear();
        cin >> k >> m;
        cout << "Case " << i << "\n";
        for (int j = 1; j <= 9; ++j) dfs(j, j, k - 1, m);
        if (r.empty()) cout << "No Solution\n";
        else {
            sort(r.begin(), r.end());
            for (int j = 0; j < r.size(); ++j)
                cout << r[j].sum << " " << r[j].val << "\n";
        }
    }
}
