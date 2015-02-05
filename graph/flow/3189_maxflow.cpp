#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,b;

struct Edge{
	int to,cap,rev;
};
const int MAX_V=2005,
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
	for(int i=0;i<=n+b+1;++i){
		G[i].clear();
	}
}

int r[1005][25],cap[25];

int gao(){
	int _min=0x3f3f3f3f;
	for(int i=0;i<b;++i){
		for(int j=i;j<b;++j){
			if(j-i>=_min) continue;
			init();
			for(int k=1;k<=n;++k){
				addEdge(0,k,1);
				for(int l=i;l<=j;++l){
					addEdge(k,n+r[k][l],1);
				}
			}
			for(int k=1;k<=b;++k){
				addEdge(n+k,n+b+1,cap[k]);
			}
			if(maxFlow(0,n+b+1)==n){
				//cout<<i<<' '<<j<<endl;
				_min=min(_min,j-i);
			}
		}
	}
	return _min+1;
}

int main(){
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;++i){
		for(int j=0;j<b;++j){
			scanf("%d",&r[i][j]);
		}
	}
	for(int i=1;i<=b;++i){
		scanf("%d",&cap[i]);
	}
	printf("%d\n",gao());
}
