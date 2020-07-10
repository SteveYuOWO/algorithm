#include<cstdio>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm> 
using namespace std;
unordered_map<int,int> m;
int n,num;
struct node{
	char card[15];
	int socre;
};
char players[10005][20];
int socre[10005];
bool cmp(int& a,int& b){
	if(socre[a]!=socre[b])
		return socre[a]>socre[b];
	else{
		for(int i=0;i<15;i++){
			if(players[a][i]!=players[b][i])
				return players[a][i]<players[b][i];
		}
	}
	return false;
}
bool cmp2(int& a,int& b){
	if(m[a]!=m[b])
		return m[a]>m[b];
	else
		return a<b;
}
void fun(int kth,int type,char term[]){
//	cout<<"Case "<<kth<<": "<<type<<" "<<term<<endl;
	printf("Case %d: %d %s\n",kth,type,term);
	if(type==1){
		vector<int> v;
		int sum=0;
		char level=term[0];
		for(int i=0;i<n;i++){
			if(players[i][0]==level){
				sum++;
				v.push_back(i);
			}
		}
		if(sum==0)
			printf("NA\n");
		else{
			sort(v.begin(),v.end(),cmp);
			for(int i=0;i<v.size();i++){
			//	cout<<players[v[i]]<<" "<<socre[v[i]]<<endl;
				printf("%s %d\n",players[v[i]],socre[v[i]]);
			}
		}
	}
	else if(type==2){
		int sum=0;
		int total=0;
		char site[5];
		for(int j=0;j<3;j++)
			site[j]=term[j];
		for(int i=0;i<n;i++){
			int mark=0;
			for(int j=1;j<=3;j++){
				if(players[i][j]!=site[j-1]){
					mark=1;
					break;
				}
			}
			if(mark==0){
				sum++;
				total+=socre[i];
			}
		}
		if(sum!=0)
		//	cout<<sum<<" "<<total<<endl;
			printf("%d %d\n",sum,total);
		else	
			printf("NA\n");
	}
	else if(type==3){
		int sum=0;
		m.clear();
		vector<int> v;
		char data[10];
		for(int i=4;i<=9;i++){
			data[i]=term[i-4];
		}
		for(int i=0;i<n;i++){
			int mark=0;
			for(int j=4;j<10;j++){
				if(players[i][j]!=data[j]){
					mark=1;
					break;
				}
			}
			if(mark==0){
				sum++;
				int site=0;
				for(int j=1;j<=3;j++){
					site=site*10+players[i][j]-'0';
				}
				if(m.count(site)==0){
					m[site]=1;
					v.push_back(site);
				}	
				else{
					m[site]=m[site]+1;
				}
					
			}
		}
		if(sum==0)
			printf("NA\n");
		else{
			sort(v.begin(),v.end(),cmp2);
			for(vector<int>::iterator it=v.begin();it!=v.end();it++){
				printf("%d %d\n",*it,m[*it]);
			}
		}

	}

}
int main(){
	scanf("%d %d",&n,&num);
	for(int i=0;i<n;i++){
		scanf("%s %d",&players[i][0],socre+i);
	//	players[i][13]='\0';
	}
//	for(int i=0;i<n;i++){
//		cout<<players[i]<<endl;
//	}
	int type;
	char term[15];
	for(int i=1;i<=num;i++){
		 scanf("%d %s",&type,term);
		 fun(i,type,term);
	} 
	return 0;
}

