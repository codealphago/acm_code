#include<iostream>
#include<queue>
#define Max 201
using namespace std;
int _map[Max][Max];//��¼ԭͼ��i��j���������
int min(int a,int b){
	return a<b? a:b;
}
int maxflow(int s,int t){//s��Դ��t�ǻ��Ҳ�ǽڵ�����ֵ�������s��t�������
	int f=0;//�����
	int a[Max];//��¼��ǰ·��������������
	bool visit[Max];
	int flow[Max][Max];//��¼��i��j��ռ���˵�����
	int p[Max];//��¼������һ����㣬����p[i]����i
	int u,i;
	queue<int> q;
	memset(flow,0,sizeof(flow));
	while(1){
		memset(visit,0,sizeof(visit));
		memset(a,0,sizeof(a));
		a[s]=INT_MAX;
		visit[s]=1;
		q.push(s);
		while(!q.empty()){
			u=q.front();
			q.pop();
			for(i=1;i<=t;i++){
				if(!visit[i]&&_map[u][i]-flow[u][i]>0){
					visit[i]=1;
					a[i]=min(a[u],_map[u][i]-flow[u][i]);
					p[i]=u;
					q.push(i);
				}
			}
		}
		if(a[t]==0)break;
		for(i=t;i!=s;i=p[i]){
			flow[i][p[i]]-=a[t];
			flow[p[i]][i]+=a[t];
		}
		f+=a[t];
	}
	return f;
}
int main(){
	int n,m,i,u,v,w;
	while(cin>>n>>m){
		memset(_map,0,sizeof(_map));  
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&u,&v,&w);
			_map[u][v]+=w;
		}
		cout<<maxflow(1,m)<<endl; 
	}
	return 0;
}
