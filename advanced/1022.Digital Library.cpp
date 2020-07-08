#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
using namespace std;
int main(){
    int N, M;
    cin >> N;
    string id, title, author, kw, publisher, year, search_s;
    getline(cin, search_s);
    unordered_map<string, map<string, string>> m;
    while(N--) {
        getline(cin,id);
        getline(cin,title);
        getline(cin,author);
        getline(cin,kw);
        getline(cin,publisher);
        getline(cin,year);
        m[title][id] = id;
        m[author][id] = id;
        stringstream ss;
        ss << kw;
        while(ss >> kw) m[kw][id] = id;
        m[publisher][id] = id;
        m[year][id] = id;
    }
    cin >> M;
    getline(cin, search_s);
    while(M--) {
        getline(cin, search_s);
        cout << search_s << endl;
        search_s = search_s.substr(3);
        if(m[search_s].size() == 0)
            cout << "Not Found" <<endl;
        else {
            for(auto x: m[search_s])
                cout << x.second << endl;
        }
    }
    return 0;
}
