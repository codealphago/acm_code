//Ford-Fulkerson�����
//���Ӷ�o(F|E|)	//Fָ������|E|ָ����
//GҪ����
const int MAX_V = 405,
          INF = 0x3f3f3f3f;
struct Edge {
	int to, cap, rev;
};

vector<Edge> G[MAX_V];
bool vis[MAX_V];
int n, m;
//��ͼ�м�һ����from��to����Ϊcap�ı�
void addEdge(int from, int to, int cap) {
	G[from].push_back((Edge) {to, cap, G[to].size()});
	G[to].push_back((Edge) {from, 0, G[from].size() - 1});
}
int dfs(int v, int t, int f) {
	if (v == t) return f;
	vis[v] = true;
	for (int i = 0; i < G[v].size(); ++i) {
		Edge &e = G[v][i];
		if (!vis[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int maxFlow(int s, int t) {
	int flow = 0;
	while (1) {
		memset(vis, 0, sizeof(vis));
		int f = dfs(s, t, INF);
		if (f == 0) return flow;
		flow += f;
	}
	return flow;
}
