#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,m,k;

struct Edge{
	int to,cap,rev;
};
const int MAX_V=205,
	  INF=0x3f3f3f3f;
vector<Edge> G[MAX_V];
int level[MAX_V];	//���㵽Դ��ľ�����
int iter[MAX_V];	//��ǰ��������֮ǰ�ı��Ѿ�û������
void addEdge(int from,int to,int cap){
	G[from].push_back((Edge){to,cap,G[to].size()});
	G[to].push_back((Edge){from,0,G[from].size()-1});
}
//ͨ��bfs�����Դ������ľ�����
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();++i){
			Edge &e=G[v][i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
//ͨ��dfsѰ������·
int dfs(int v,int t,int f){
	if(v==t) return f;
	for(int &i=iter[v];i<G[v].size();++i){
		Edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
//����s��t�������
int maxFlow(int s,int t){
	int flow=0;
	while(1){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
	return flow;
}
void init(){
	for(int i=0;i<=n+m+1;++i){	//
		G[i].clear();
	}
}
bool vis[MAX_V][MAX_V];
int main(){
	while(scanf("%d",&n) && n){
		scanf("%d%d",&m,&k);
		init();
		int id,x,y;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=k;++i){
			scanf("%d%d%d",&id,&x,&y);
			if(x*y!=0 && vis[x][n+y]==0){
				vis[x][n+y]=1;
				addEdge(x,n+y,1);
			}
		}
		for(int i=1;i<=n;++i){
			addEdge(0,i,1);
		}
		for(int i=n+1;i<=n+m;++i){
			addEdge(i,n+m+1,1);
		}
		printf("%d\n",maxFlow(0,n+m+1));
	}
	return 0;
}


