#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int f[8];
int n,d,w,sum;

struct Edge{
	int to,cap,rev;
};
const int MAX_V=405,
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

bool vis[MAX_V];
void init(){
	for(int i=0;i<=n+50*7+1;++i){	//
		G[i].clear();
	}
	sum=0;
	memset(vis,0,sizeof(vis));
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=7;++j){
				scanf("%d",&f[j]);
			}
			scanf("%d%d",&d,&w);
			sum+=d;
			addEdge(0,i,d);
			for(int j=0;j<w;++j){
				for(int k=1;k<=7;++k){
					if(f[k]){
						addEdge(i,n+k+j*7,1);
						if(vis[n+k+j*7]==0){
							addEdge(n+k+j*7,n+50*7+1,1);
							vis[n+k+j*7]=1;
						}
					}
				}
			}
		}
		/*for(int i=0;i<=n+w*7+1;++i){
		  cout<<i<<':';
		  for(int j=0;j<G[i].size();++j){
		  if(G[i][j].cap) cout<<G[i][j].to<<' ';
		  }
		  cout<<endl;
		  }
		  cout<<maxFlow(0,n+50*7+1)<<endl;*/
		if(maxFlow(0,n+50*7+1)==sum)
			puts("Yes");
		else
			puts("No");
	}
	return 0;

}
