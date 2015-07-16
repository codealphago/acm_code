/*poj 1330 Nearest Common Ancestors
  ���⣺
  ����һ�ô�СΪn������һ��ѯ��(u,v), ��(u,v)������������ȡ�
  ���ƣ�
  2 <= n <= 10000
  ˼·��
  ���ڱ��������㷨��
  ���ص��㷨Ϊ��
  ����ڵ�w��u��v�Ĺ������ȵĻ���������u��v�н����һ��������|depth(u)-depth(v)|����Ȼ����һ��һ�������ߣ�ֱ��ͬһ���ڵ�
  ���ڱ��������Ż���
  ����ÿ���ڵ�Ԥ�����2, 4, 8, ... 2^k�������ȣ�Ȼ��㡣
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define PB push_back
const int N=100005;
const int LOGN=22;

vector<int> tree[N];

int fa[N][LOGN];
int depth[N];

void dfs(int u,int p,int d){
	depth[u]=d;
	fa[u][0]=p;
	for(int i=0;i<tree[u].size();++i){
		if(tree[u][i]!=p)
			dfs(tree[u][i],u,d+1);
	}
}

int LCA(int u,int v){
	if(depth[u]>depth[v]) swap(u,v);
	for(int i=0;i<LOGN;++i){
		if(((depth[v]-depth[u]) >> i) & 1)
			v=fa[v][i];
	}
	if(u==v) return u;
	for(int i=LOGN-1;i>=0;--i){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}


int indeg[N];

void predo(int n){
	int root;
	for(int i=1;i<=n;++i){
		if(!indeg[i]){
			root=i;
			break;
		}
	}
	dfs(root,-1,0);
	for(int j=0;j+1<LOGN;++j){
		for(int i=1;i<=n;++i){
			if(fa[i][j]<0) fa[i][j+1]=-1;
			else fa[i][j+1]=fa[fa[i][j]][j];
		}
	}
}

void init(int n){
	memset(indeg,0,sizeof(indeg));
	for(int i=0;i<=n;++i)
		tree[i].clear();
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		init(n);
		int u,v;
		for(int i=0;i<n-1;++i){
			scanf("%d%d",&u,&v);
			tree[u].PB(v);
			++indeg[v];
		}
		predo(n);
		scanf("%d%d",&u,&v);
		printf("%d\n",LCA(u,v));
	}
	return 0;
}
