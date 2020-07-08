#include <iostream>
using namespace std;
int main()
{
    int M;
    scanf("%d", &M);
    string maxid, _max="", minid, _min="1111 1111", tmp, start, _end;
    while(M--) {
        cin >> tmp >> start >> _end;
        if(start < _min) {
            _min = start;
            minid = tmp;
        }
        if(_end > _max) {
            _max = _end;
            maxid = tmp;
        }
    }
    cout << minid << " " << maxid;
    return 0;
}
