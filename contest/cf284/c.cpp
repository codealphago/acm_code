/*cf284div1c
  ���⣺����n����a[1],a[2],...,a[n]������m������(i,j)������ÿ�β���������ѡ��һ�����ԣ��������һ������v��ʹ��a[i]%v==0 && a[j]%v==0������a[i]/=v,a[j]/=v��һ��������ʹ�ö�Ρ�������ܲ������Ρ�
  ���ƣ�2 <= n <= 100 , 1 <= m <= 100 , 1 <= a[i] <= 1e9 , i+j������ && 1 <= i < j <= n
  ˼·�����������ֽ�������
  �ȶ�ÿ��a[i]�ֽ������ӣ���Ϊֻ��ÿ�β������������Ӳ���ʹ�����������
  Ȼ����ż��ͼ(��������Ϊ�㣬��Ϊ�������кܶ��ظ��ģ����Բ����кܶ��)
  ��һ������������ˡ�
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define pb push_back
struct Edge{
	int to,cap,rev;
};
const int MAX_V=3005,
	  INF=0x3f3f3f3f;
vector<Edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void addEdge(int from,int to,int cap){
	G[from].push_back((Edge){to,cap,G[to].size()});
	G[to].push_back((Edge){from,0,G[from].size()-1});
}
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

struct Dt{
	int v,f;
	Dt(){}
	Dt(int _v,int _f){
		v=_v;
		f=_f;
	}
};
const int N=105;
vector<Dt> vec[N];
int seq[N][N];

void _div(int id,int a){
	int lim=sqrt(a),tmp=a;
	for(int i=2;i<=lim;++i){
		if(tmp%i==0){
			tmp/=i;
			int sz=vec[id].size();
			if(sz==0)
				vec[id].pb(Dt(i,1));
			else{
				if(i==vec[id][sz-1].v)
					++vec[id][sz-1].f;
				else
					vec[id].pb(Dt(i,1));
			}
			--i;
		}
		if(tmp==1) break;
	}
	//�ֽ������Ӳ�Ҫ©�����
	if(tmp!=1) vec[id].pb(Dt(tmp,1)); 
	if(vec[id].size()==0 && a!=1)
		vec[id].pb(Dt(a,1));
}

int n,m;
int cnt0=0,cnt1=0;
void predo(){
	for(int i=0;i<n;++i){
		for(int j=0;j<vec[i].size();++j){
			seq[i][j]=(cnt0++)+1;
		}
	}
}
int main(){
	int a;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		_div(i,a);
	}
	predo();
	int u,v;
	int S=0,T=cnt0+1;
	
	for(int i=0;i<n;++i){
		for(int j=0;j<vec[i].size();++j){
			int fr=seq[i][j];
			if(i%2==1) addEdge(S,fr,vec[i][j].f);
			else addEdge(fr,T,vec[i][j].f);
		}
	}
	for(int i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		if(u%2==1) swap(u,v);
		--u,--v;
		for(int j=0;j<vec[u].size();++j){
			int fr,to;
			fr=seq[u][j];
			for(int k=0;k<vec[v].size();++k){
				if(vec[u][j].v==vec[v][k].v){
					to=seq[v][k];
					addEdge(fr,to,vec[u][j].f);
				}
				else if(vec[u][j].v>vec[v][k].v) continue;
				else break;
			}
		}
	}
	cout<<maxFlow(S,T)<<endl;
	return 0;
}
