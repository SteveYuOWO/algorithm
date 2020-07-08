#include <iostream>
using namespace std;
struct stu {
    string name = "Absent", sex, id;
    int grade;
};
int main()
{
    int N;
    scanf("%d", &N);
    stu _max, _min, tmp;
    _max.grade = -1;
    _min.grade = 101;
    while(N--) {
        cin >> tmp.name >> tmp.sex >> tmp.id >> tmp.grade;
        if(tmp.sex == "F" && tmp.grade > _max.grade) _max = tmp;
        if(tmp.sex == "M" && tmp.grade < _min.grade) _min = tmp;
    }
    if(_max.name == "Absent") cout << _max.name << endl;
    else cout << _max.name << " " << _max.id << endl;
    if(_min.name == "Absent") cout << _min.name << endl;
    else cout << _min.name << " " << _min.id << endl;
    if(_max.name == "Absent" || _min.name == "Absent")
        cout << "NA" << endl;
    else cout << _max.grade - _min.grade << endl;
    system("pause");
    return 0;
}
