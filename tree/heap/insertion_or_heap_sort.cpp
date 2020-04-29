#include "iostream"
#include "vector"
using namespace std;
int N;
vector<int> ini, first;
int main() {
    scanf("%d", &N);
    ini.resize(N); first.resize(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &ini[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &first[i]);
    
    return 0;
}