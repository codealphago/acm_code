/*���⣺���㣬�����ȥ��ÿ�����ͼ�ᱻ�ֳɼ�����ͨ��֧��
�������������tarjan�㷨������һ��O(n^2)���㷨�����Ƿֱ��ÿ������Ϊ��������dfs�������м����ӽ�㣬�������һ����Ϊ�������Ǹ�㡣������ǹ۲�ÿ����Ϊ��ʱ�м����ӽ�㣬ȥ���õ�����ͨ��֧���������ӽ������*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=1005;
int tot;
int dfn[N],low[N],sub[N];
vector<int> _map[N];
void dfs(int rt,int fa){
	low[rt]=dfn[rt]=++tot;
	int sz=_map[rt].size();
	for(int i=0;i<sz;++i){
		int v=_map[rt][i];
		if(v!=fa){
			if(!dfn[v]){
				dfs(v,rt);
				low[rt]=min(low[rt],low[v]);
				if(low[v]>=dfn[rt]){
					++sub[rt];
				}
			}
			else{
				low[rt]=min(low[rt],dfn[v]);
			}
		}
	}
}
int main(){
	int n,cas=1,u,v;
	while(scanf("%d",&u) && u){
		n=tot=0;
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(sub,0,sizeof(sub));
		for(int i=0;i<N;++i){
			_map[i].clear();
		}
		scanf("%d",&v);
		_map[u].push_back(v);
		_map[v].push_back(u);
		n=max(n,max(u,v));
		while(scanf("%d",&u) && u){
			scanf("%d",&v);
			_map[u].push_back(v);
			_map[v].push_back(u);
			n=max(n,max(u,v));
		}
		dfs(1,-1);
		printf("Network #%d\n", cas++);
		--sub[1];
		bool flag=0;
		for(int i=1;i<=n;++i){
			if(sub[i]>=1){
				printf("  SPF node %d leaves %d subnets\n", i, sub[i]+1);
                flag = 1;
			}
		}
		if(!flag){
			printf("  No SPF nodes\n");
		}
		printf("\n");
	}
	return 0;
}
