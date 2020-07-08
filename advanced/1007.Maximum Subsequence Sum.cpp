#include <iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int a[N];
    int sum=0,sumMax=-1,startPoint=0,tempPoint=0,endPoint=N-1;
    //sum 和 sumMax最大数 tempPoint记录临时指针
    for(int i=0;i<N;i++){
        cin>>a[i];
        sum+=a[i];
        if(sum<0){
            sum=0;
            tempPoint=i+1;
        }else if(sum>sumMax){
            sumMax=sum;
            startPoint=tempPoint;
            endPoint=i;
        }
    }
    if(sumMax<0)sumMax=0;//应该注意如果没有一个为0，那么应该输出0，首项，末项
    cout<<sumMax<<" "<<a[startPoint]<<" "<<a[endPoint];
    return 0;
}
