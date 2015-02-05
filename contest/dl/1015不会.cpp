#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define N 100005
#define M 200005
bool hash[N],vis[N];
int d[N],head[N];
int n,m,e;
struct edge{
	int v,next;	//vΪ��ֹ��,cΪ��Ȩ,nextΪ�¸����
}p[M];
void addEdge(int u,int v){
	p[e].v=v;
	p[e].next=head[u];		//����β��Ϊ-1
	head[u]=e++;
}
void init(){	//�����ڽӱ� 
	int i,u,v;	//u���,v�յ�,cȨ 
	memset(head,-1,sizeof(head));
	e=0;
	for(i=0;i<n-1;++i){
		scanf("%d%d",&u,&v);
		addEdge(u,v);		//����
		addEdge(v,u);		//˫��
	}
}
int bfs(int n){
	int i,pre;
	queue<int> q;
	memset(vis,0,sizeof(vis));
	if(hash[n]) return 0;
	q.push(n);
	vis[n]=1;
	d[n]=0;
	while(!q.empty()){
		pre=q.front();
		q.pop();
		for(i=head[pre];i+1;i=p[i].next){
			if(!vis[p[i].v]){
				vis[p[i].v]=1;
				if(hash[p[i].v]) return d[pre]+1;
				else{
					d[p[i].v]=d[pre]+1;
					q.push(p[i].v);
				}
			}
		}
	}
	return -1;
}
int main(){
	int ans,a,b,i,u,v;
	hash[1]=1;
	scanf("%d%d",&n,&m);
	init();
	for(i=0;i<m;++i){
		scanf("%d%d",&a,&b);
		if(a==1) hash[b]=1;
		else{
			ans=bfs(b);
			printf("%d\n",ans);
		}
	}
	return 0;
}
