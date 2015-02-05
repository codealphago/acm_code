/*Dijkstra���·*/
/*�˿ڲ���:a[][],s,t,n*/
/*a[][]Ϊ�ڽӾ���,sΪ���,tΪ�յ�,nΪ�����Ŀ*/
/*���ڲ������·*/
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define Min(x,y) ((x)<(y)?(x):(y))
#define inf 0x3f3f3f3f
#define N 1005
int a[N][N],dis[N];		//a[][]Ϊ�ڽӾ���,dis[]�����/��·
bool vis[N];	//���ʹ��ĵ�
int n;
int dij(){
	int i,j,k,tmp;
	int s=1;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;++i) dis[i]=a[s][i];
	vis[s]=1;
	for(i=1;i<n;++i){
		tmp=inf,k=s;	//tmp=0ʱΪ�·
		for(j=1;j<=n;++j){
			if(!a[j][i]||vis[j]) continue;
			if(tmp>dis[j]){		//<ʱΪ�·
				tmp=dis[j];
				k=j;
			}
		}
		vis[k]=1;
		//if(k==t) return tmp;	//�������/��·
		for(j=1;j<=n;++j){
			if(vis[j]) continue;
			dis[j]=Min(dis[j],dis[k]+a[k][j]);
		}
	}
}
int main(){
	int c,d,i,m,t,u,v;
	int cnt=1;
	while(scanf("%d",&n)!=EOF){
		++n;
		memset(a,0x3f,sizeof(a));
		/*�����·ʱҪmemset(a,0x3f,sizeof(a)),�·Ҫmemset(a,0,sizeof(a))*/
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&a[i][j]);
		dij();
		if(cnt==62){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j)
					cout<<a[i][j]<<' ';
				cout<<endl;
			}
			printf("%d",dis[2]);
			for(int i=3;i<=n;++i){
				printf(" %d",dis[i]);
			}
			puts(" ");
		}
		++cnt;
	}
	return 0;
}
