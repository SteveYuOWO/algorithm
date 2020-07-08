#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int a){
    if(a <= 1) return  false;
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0) return false;
    }
    return true;
}
int award[10000000]={0};
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) award[a[i]]=3;
    award[a[0]]=1;
    for(int i=1;i<n;i++) if(isPrime(i+1)) award[a[i]] = 2;
    int m,tmp;
    cin>>m;
    while(m--){
        cin>>tmp;
        if(award[tmp]==1){
            printf("%04d: Mystery Award\n",tmp);
            award[tmp]=4;
        }else if(award[tmp]==2){
            printf("%04d: Minion\n",tmp);
            award[tmp]=4;
        }else if(award[tmp]==3){
            printf("%04d: Chocolate\n",tmp);
            award[tmp]=4;
        }else if(award[tmp]==4) printf("%04d: Checked\n",tmp);
        else printf("%04d: Are you kidding?\n",tmp);
    }
    return 0;
}
