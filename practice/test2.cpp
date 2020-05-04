#include <iostream>
using namespace std;
class progress {//PCB
public:
	int domin;
	int runtime;
	string name;
	int reach;
	int st = 0;
	progress* next = NULL;
	progress(int runtime, string name, int reach,int domin ) {
		this->runtime = runtime;
		this->name = name;
		this->reach = reach;
		this->domin = domin;	
		
	}
	int running() {
		st++;
		cout << name << " has ran for " << st << endl;	
	}
};
struct head {
	progress*head;
	progress*rear;
};
int main() {
    
    return 0;
}