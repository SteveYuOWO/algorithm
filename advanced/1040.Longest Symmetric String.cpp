#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s;int ans=1;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        int j,k;
        for(j=1;i-j>=0&&i+j<s.length();j++)/** 奇数 */
            if(s[i-j]!=s[i+j]) break;
        if(2*j-1>ans) ans=2*j-1;
        if(s[i]==s[i+1])/** 偶数 */
            for(k=1;i-k>=0&&i+k+1<s.length();k++)
                if(s[i-k]!=s[i+k+1]) break;
        if(2*k>ans) ans=2*k;
    }
    cout<<ans;
    return 0;
}
