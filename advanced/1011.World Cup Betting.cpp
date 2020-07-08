#include <iostream>
using namespace std;
int main(){
    double m_num[3];
    double w, t, l, m;
    char m_char[3];
    for(int i = 0; i < 3; i++){
        scanf("%lf%lf%lf", &w, &t, &l);
        m = max(max(w, t), l);
        if(m == w){
            m_char[i] = 'W';
            m_num[i] = m;
        }else if(m == t){
            m_char[i] = 'T';
            m_num[i] = m;
        }else {
            m_char[i] = 'L';
            m_num[i] = m;
        }
    }
    double res = (m_num[0] * m_num[1] * m_num[2] * 0.65 - 1) * 2;
    printf("%c %c %c %.2f", m_char[0], m_char[1], m_char[2], res);
    return 0;
}
