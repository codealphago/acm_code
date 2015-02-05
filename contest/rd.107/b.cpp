/*Dijkstra�ڽӱ�ʵ��*/
/*�˿ڲ���:n,m,src(���),�ڽӱ�*/
/*���ڲ���:����dis[],�����src����������·*/
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define inf 0x3f3f3f3f
#define N 1005
#define M 100005
int head[N],dis[N];
int n,m,e;		//n����������,m����ߵ�����,e�������ڱߵ���Ŀ
bool vis[N];
struct note{
	int u,v,c,next;
}p[M];
struct ab{
	int v,c;
	ab(){}
	ab(int v,int c):v(v),c(c){}
	bool operator < (const ab &other) const{
		return c>other.c;
	}
};
void addnote(int u,int v,int c){
	p[e].v=v;
	p[e].c=c;
	p[e].next=head[u];		//����β��Ϊ-1
	head[u]=e++;
}
void init(){	//�����ڽӱ� 
	int i,j,v;	//u���,v�յ�,cȨ 
	memset(head,-1,sizeof(head));
	e=0;
	for(i=1;i<=n;++i){
		int cnt;
		scanf("%d",&cnt);
		for(j=0;j<cnt;++j){
			scanf("%d",&v);
			if(j==0) addnote(i,v,0);		//����
			else addnote(i,v,1);
		}
		//addnote(v,u,c);		//˫��
	}
}
void dij(int src){
	int i,j;
	ab u;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;++i) dis[i]=inf;
	dis[src]=0;
	priority_queue<ab> q;
	q.push(ab(src,dis[src]));
	for(i=0;i<n;++i){
		u=q.top();
		q.pop();
		vis[u.v]=1;
		for(j=head[u.v];j+1;j=p[j].next){
			if(!vis[p[j].v]&&dis[p[j].v]>dis[u.v]+p[j].c){
				dis[p[j].v]=dis[u.v]+p[j].c;
				q.push(ab(p[j].v,dis[p[j].v]));
			}
		}
		while(!q.empty()&&vis[q.top().v]) q.pop();
		if(q.empty()) break;
	}
}
int main(){
	int d,src,end;
	scanf("%d%d%d",&n,&src,&end);
	init();
	dij(src);
	d=dis[end];	//�ӵ�src����2�����· 
	if(d==inf) printf("-1\n");
	else printf("%d\n",d);
	return 0;
}

