/*poj 2135
  ���⣺
  ����һ����n����m���ߵ�ͼ����ӵ�1����n�ٴӵ�n�ص���1�����·����Ҫ��ÿ��·���ֻ�ܾ���һ�Ρ�
  ���ƣ�
  1 <= n <= 1000; 1 <= m <= 10000
  ˼·��
  ������
  ��ͼ��
  ����Դ��0�����ߣ�0->1������Ϊ2������Ϊ0��
  �������n+1�����ߣ�n->n+1������Ϊ2������Ϊ0��
  ������ͼ�ı�һ������˫��ߣ�����Ϊ1������Ϊ��Ȩ��

  ��ģ������dij�����·, ���Ӷ�O(F |E| log|V|);
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_V = 1005;
#define PII pair<int,int>
#define PB push_back
#define X first
#define Y second
struct edge{ int to, cap, cost, rev; };
int V;	//������
vector<edge> G[MAX_V];
int h[MAX_V]; //�������
int dist[MAX_V]; //��̾���
int prevv[MAX_V], preve[MAX_V]; //���·�е�ǰ���ڵ�Ͷ�Ӧ�ı�
void add_edge(int fr, int to, int cap, int cost){
	G[fr].PB((edge){to, cap, cost, G[to].size()});
	G[to].PB((edge){fr, 0, -cost, G[fr].size()-1});
}
//����s��t����Ϊf����С������
//���û������Ϊf�������򷵻�-1
int min_cost_flow(int s, int t, int f){
	int res = 0;
	fill(h, h+V, 0);
	while(f > 0){
		//ʹ��dij����h
		priority_queue< PII, vector<PII>, greater<PII> > que;
		fill(dist, dist+V, INF);
		dist[s] = 0;
		que.push(PII(0, s));
		while(!que.empty()){
			PII p = que.top(); que.pop();
			int v = p.Y;
			if(dist[v] < p.X) continue;
			for(int i = 0; i < G[v].size(); ++i){
				edge &e = G[v][i];
				int tmp = dist[v] + e.cost + h[v] - h[e.to];
				if(e.cap > 0 && dist[e.to] > tmp){
					dist[e.to] = tmp;
					prevv[e.to] = v;
					preve[e.to] = i;
					que.push(PII(dist[e.to], e.to));
				}
			}
		}
		if(dist[t] == INF){
			//����������
			return -1;
		}
		for(int v = 0; v < V; ++v) h[v] += dist[v];
		//��s��t���·��������
		int d = f;
		for(int v = t; v != s; v = prevv[v]){
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += d * h[t];
		for(int v = t; v != s; v = prevv[v]){
			 edge &e = G[prevv[v]][preve[v]];
			 e.cap -= d;
			 G[v][e.rev].cap += d;
		}
	}
	return res;
}
void init(){
	for(int i = 0; i < V; ++i) G[i].clear();
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	V = n + 2;
	init();
	while(m--){
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		add_edge(u, v, 1, c);
		add_edge(v, u, 1, c);
	}
	add_edge(0, 1, 2, 0);
	add_edge(n, n+1, 2, 0);
	int ans = min_cost_flow(0, n+1, 2);
	cout<<ans<<endl;
	return 0;
}
