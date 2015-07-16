/*poj 1330 Nearest Common Ancestors
  ���⣺
  ����һ�ô�СΪn������һ��ѯ��(u,v), ��(u,v)������������ȡ�
  ���ƣ�
  2 <= n <= 10000
  ˼·��
  �����漰�и��������⣬����ת��Ϊ�Ӹ�dfs��ź�õ������д���ļ��ɳ���ʮ����Ч������LCA���������Ҳʮ����Ч�����ȣ����Ӹ�dfs���ʵ�˳��õ���������vs[i]�Ͷ�Ӧ�����depth[i]������ÿ������v��������vs���״γ��ֵ��±�Ϊid[v]��
  ��Щ������dfsһ��㶨����LCA(u,v)���Ƿ���u֮�󵽷���v֮ǰ���������������������Ǹ�������id[u] <= id[v]���У�
  LCA(u,v) = vs[id[u] <= i <= id[v]����depth(i)��С��i]
  ���������rmq��á�

 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
#define PB push_back
const int N=100005;

int dp[N*2][18];
void make_rmq_index(int n,int b[]){ //������Сֵ��Ӧ���±�
    for(int i=0;i<n;i++)
        dp[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
            dp[i][j]=b[dp[i][j-1]] < b[dp[i+(1<<(j-1))][j-1]]? dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
}
int rmq_index(int s,int v,int b[]){
	int k=(int)(log((v-s+1)*1.0)/log(2.0));
	return b[dp[s][k]]<b[dp[v-(1<<k)+1][k]]? dp[s][k]:dp[v-(1<<k)+1][k];
}


vector<int> tree[N];
int vs[N*2]; //dfs���ʵ�˳��
int depth[N*2]; //�ڵ�����
int id[N]; //����������vs���״γ��ֵ��±�

void dfs(int u,int p,int d,int &k){
	id[u]=k;
	vs[k]=u;
	depth[k++]=d;
	for(int i=0;i<tree[u].size();++i){
		if(tree[u][i]!=p){
			dfs(tree[u][i],u,d+1,k);
			vs[k]=u;
			depth[k++]=d;
		}
	}
}

int indeg[N];

void predo(int n){
	int root;
	for(int i=1;i<=n;++i){
		if(indeg[i]==0){
			root=i;
			break;
		}
	}
	int k=0;
	dfs(root,-1,0,k);

	/*
	for(int i=0;i<k;++i)
		cout<<i<<':'<<vs[i]<<' ';
	cout<<endl;
	for(int i=0;i<k;++i)
		cout<<i<<':'<<depth[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;++i)
		cout<<i<<':'<<id[i]<<' ';
	cout<<endl;
	*/

	make_rmq_index(n*2-1,depth);
}

int LCA(int u,int v){
	return vs[rmq_index(min(id[u],id[v]), max(id[u],id[v])+1, depth)];
}

void init(int n){
	memset(indeg,0,sizeof(indeg));
	for(int i=1;i<=n;++i)
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
/*
input:
1
5
2 3
3 4
3 1
1 5
3 5

output:
0:2 1:3 2:4 3:3 4:1 5:5 6:1 7:3 8:2
0:0 1:1 2:2 3:1 4:2 5:3 6:2 7:1 8:0
1:4 2:0 3:1 4:2 5:5
3
*/
