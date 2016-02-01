/*��⣺
  ��Ϊ�ж���ֵ꣬���Կ��԰ѷֵ굱����㣬�Ѷ�����ѹ�����β��Ȼ����п��ѣ�Ȼ����Եõ�����һ���ֵ굽������һ��������Ҫ������С���������𰸵������е㲽��*�͵ķ����ĺ͡�
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define LL long long

const int N = 1e3 + 5;
const int INF = 1000000000;

//������
struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) {
		x = _x; y = _y;
	}
};

//��ͼ���飬����-2��ʾ���ܾ����ĵ㣬-1��ʾ�ֵ꣬������ʾҪ�͵��õ�Ĳ͵�����
int G[N][N];

//�������飬����step[x][y]��ʾ������һ���ֵ굽������Ϊ(x, y)�ĵ�����Ҫ������С����
int step[N][N];

//λ������
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

//�жϸõ��Ƿ���Լӵ���������
bool legal(int x, int y, int n) {
	if(x >= 1 && x <= n && y >= 1 && y <= n && 
			G[x][y] != -2 && step[x][y] == INF)
		return true;
	return false;
}

void solve(int n) {
	queue<Point> que;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(G[i][j] == -1) {
				que.push(Point(i, j));	//�����������β
				step[i][j] = 0;	//��ʼ����Ϊ0
			}

	while(!que.empty()) {
		Point now = que.front();
		que.pop();
		
		//�ӵ�ǰ�������ڵ��ĸ�������
		for(int i = 0; i < 4; ++i) {
			int tmp_x = now.x + dx[i];
			int tmp_y = now.y + dy[i];
			if(legal(tmp_x, tmp_y, n)) {
				que.push(Point(tmp_x, tmp_y));	//��������������������β
				step[tmp_x][tmp_y] = step[now.x][now.y] + 1;	//����+1
			}
		}
	}

	LL ans = 0;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(G[i][j] >= 0) {
				ans += (LL)G[i][j] * step[i][j];	//��Ϊ����*�͵ķ����ĺ�
			}

	cout<<ans<<endl;
}

//��ʼ������
void init(int n) {
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			step[i][j] = INF;
}

int main() {
	int n, m, k, d;
	scanf("%d%d%d%d", &n, &m, &k, &d);
	for(int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x][y] = -1;
	}
	for(int i = 0; i < k; ++i) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		G[x][y] += c;
	}
	for(int i = 0; i < d; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x][y] = -2;
	}
	
	init(n);
	solve(n);

	return 0;
}

