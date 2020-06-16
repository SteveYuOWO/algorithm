#include <iostream>
#include <queue>
using namespace std;
int N, level;
char op[10], msg[10];
struct message {
    string msg; int level;
    bool operator<(const message m) const {
        return level > m.level;
    }
};
priority_queue<message> que;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d", &N);
    while(N--) {
        scanf("%s", op);
        if(op[0] == 'P') {
            scanf("%s%d", msg, &level);
            que.push({msg, level});
        } else {
            if(!que.empty()) {
                printf("%s\n", que.top().msg.c_str());
                que.pop();
            } else printf("EMPTY QUEUE!\n");
        }
    }
    return 0;
}
