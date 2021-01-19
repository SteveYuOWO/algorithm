#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	vector<double> data(N, 0.0);
	for (int i = 0; i < N; i++)
		scanf("%lf", &data[i]);
	double result = 0.0;
	for (int i = 0; i < N; i++)
		result += data[i] * (N - i)*(i + 1);
	printf("%.2f", result);
}
