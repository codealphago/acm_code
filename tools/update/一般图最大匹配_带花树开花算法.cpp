/*poj 3020 һ��ͼ���ƥ�� �����������㷨
  ���⣺
  ����һ��h*w��ͼ��ÿ���㶼��'o'��'*'������Ҫ�ö��ٸ�1*2�ľ��β��ܰ�ͼ�����е�'*'�����ǵ���
  ���ƣ�
  1 <= h <= 40; 1 <= w <= 10
  ˼·��
  ��С�߸���=|V|-���ƥ��
  һ��ͼ���ƥ�䣬�����������㷨
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_V = 405;

// ���鼯ά��
int fa[MAX_V];
int getFa(int x) { 
	return fa[x] == x ? x : fa[x] = getFa(fa[x]);
}
void merge(int a, int b) {
	a = getFa(a);
	b = getFa(b);
	if (a != b) fa[a] = b;
}

int V, match[MAX_V];
vector<int> e[MAX_V];
int Q[MAX_V], rear;
int next[MAX_V], mark[MAX_V], vis[MAX_V];

// �����㷨��ĳ�׶���������������x, y�������������r
int LCA(int x, int y) {
	static int t = 0; t++;
	while (true) {
		if (x != -1) {
			x = getFa(x); // ��Ҫ��Ӧ����Ӧ�Ļ���ȥ
			if (vis[x] == t) return x;
			vis[x] = t;
			if (match[x] != -1) x = next[match[x]];
			else x = -1;
		}
		swap(x, y);
	}
}

void group(int a, int p) {
	while (a != p) {
		int b = match[a], c = next[b];

		// next������������ǻ����е�·���ģ��ۺ�match�������ã�ʵ�����γ���
		// ˫��������(x, y)��ƥ��ģ�next[x]��next[y]�Ϳ���ָ���������ˡ�
		if (getFa(c) != p) next[c] = b;

		// �滷�еĵ㶼�л��������ҵ�ƥ�䣬���Զ�Ҫ��ǳ�S�͵�ӵ�������ȥ��
		// ���ڵ�ƥ�����ѱ��ͣ������Щ�����ֻ����ƥ��ɹ�һ���㣬��aug��
		// ÿ��ƥ�䵽һ�����break��ֹ�˵�ǰ�׶ε������������½׶εı������
		// �������ģ�����������Ϊ�˱�֤��һ�㡣
		if (mark[b] == 2) mark[Q[rear++] = b] = 1;
		if (mark[c] == 2) mark[Q[rear++] = c] = 1;

		merge(a, b); merge(b, c);
		a = c;
	}
}

// ����
void aug(int s) {
	for (int i = 0; i < V; i++) // ÿ���׶ζ�Ҫ���±��
		next[i] = -1, fa[i] = i, mark[i] = 0, vis[i] = -1;
	mark[s] = 1;
	Q[0] = s; rear = 1; 
	for (int front = 0; match[s] == -1 && front < rear; front++) {
		int x = Q[front]; // ����Q�еĵ㶼��S�͵�
		for (int i = 0; i < (int)e[x].size(); i++) {
			int y = e[x][i];
			if (match[x] == y) continue; // x��y��ƥ�䣬����
			if (getFa(x) == getFa(y)) continue; // x��yͬ��һ�仨������
			if (mark[y] == 2) continue; // y��T�͵㣬����
			if (mark[y] == 1) { // y��S�͵㣬�滷����
				int r = LCA(x, y); // rΪ��i��j��s��·���ϵĵ�һ�������ڵ�
				if (getFa(x) != r) next[x] = y; // r��x����ͬһ�����䣬next��ǻ�����·��
				if (getFa(y) != r) next[y] = x; // r��y����ͬһ�����䣬next��ǻ�����·��

				// ������r -- x - y --- r���滷���ɵ㣬r��Ϊ������ı�ǽڵ㣬�൱�������еĳ����ڵ�
				group(x, r); // ��·��r --- xΪ��
				group(y, r); // ��·��r --- yΪ��
			}
			else if (match[y] == -1) { // y���ɣ��������㣬R12������
				next[y] = x;
				for (int u = y; u != -1; ) { // ������ȡ��
					int v = next[u];
					int mv = match[v];
					match[v] = u, match[u] = v;
					u = mv;
				}
				break; // �����ɹ����˳�ѭ����������һ�׶�
			}
			else { // ��ǰ�����Ľ�����+y+match[y]�γ��µĽ���������match[y]���������Ϊ���ѽڵ�
				next[y] = x;
				mark[Q[rear++] = match[y]] = 1; // match[y]Ҳ��S�͵�
				mark[y] = 2; // y��ǳ�T��
			}
		}
	}
}

bool g[MAX_V][MAX_V];
const int N=45;
char str[N][N];
int mp[N][N];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int h,w;
bool ok(int x,int y){
	if(x>=0 && x<h && y>=0 && y<w && str[x][y]=='*')
		return true;
	return false;
}
void init(){
	memset(g,0,sizeof(g));
	for(int i=0;i<MAX_V;++i) e[i].clear();
}
void add_edge(int u,int v){
	if(g[u][v]) return ;
	e[u].push_back(v);
	e[v].push_back(u);
	g[u][v]=g[v][u]=1;
}
int gao(){	//����ƥ�䣬�����ƥ��
	int ret=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<V;++i)
		if(match[i]==-1) aug(i);
	for(int i=0;i<V;++i)
		if(match[i]!=-1) ++ret;
	return ret;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&h,&w);
		for(int i=0;i<h;++i)
			scanf("%s",str[i]);
		V=0;
		for(int i=0;i<h;++i)
			for(int j=0;j<w;++j){
				if(str[i][j]=='*') mp[i][j]=V++;
				else mp[i][j]=-1;
			}
		for(int i=0;i<h;++i)
			for(int j=0;j<w;++j){
				if(mp[i][j]!=-1){
					int u=mp[i][j],v;
					for(int k=0;k<4;++k){
						int tmpx=i+dx[k];
						int tmpy=j+dy[k];
						if(ok(tmpx,tmpy)){
							v=mp[tmpx][tmpy];
							add_edge(u,v);
						}
					}
				}
			}
		int ans=gao();
		ans=V-ans/2;
		printf("%d\n",ans);
	}
	return 0;
}
