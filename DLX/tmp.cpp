/*poj 1084
  ���⣺n*n�ľ�����(n<=5)����2*n*(n+1)����񹹳ɣ���ô���л��кܶ�����߳�Ϊ1��Ϊ2...Ϊn�������Σ����ڿ�������һЩ�����ô�ͻ���һЩ�����α��ƻ������ʣ����Ѿ�����һЩ��������£�����Ҫ�������ٶ��ٸ��Ϳ��԰����е��������ƻ�����
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define pb push_back
const int N = 5;

//�ظ�����ģ��
//��С����
const int MAXM = 105;
const int MAXN = 105;
const int N = MAXN * MAXM;
const int INF = 0x3f3f3f3f;
struct DLX {
	int n, m, size;
	int U[N], D[N], R[N], L[N], row[N], col[N];
	int H[MAXN], S[MAXM];
	int ans_cnt;
	void init(int _n, int _m) {
		ans_cnt = INF;
		n = _n;
		m = _m;
		for (int i = 0; i <= m; i++) {
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++)H[i] = -1;
	}
	void link(int r, int c) {
		++S[col[++size] = c];
		row[size] = r;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] < 0)H[r] = L[size] = R[size] = size;
		else {
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}
	void remove(int c) {
		for (int i = D[c]; i != c; i = D[i])
			L[R[i]] = L[i], R[L[i]] = R[i];
	}
	void resume(int c) {
		for (int i = U[c]; i != c; i = U[i])
			L[R[i]] = R[L[i]] = i;
	}
	bool v[MAXM];
	int f() {
		int ret = 0;
		for (int c = R[0]; c != 0; c = R[c])v[c] = true;
		for (int c = R[0]; c != 0; c = R[c])
			if (v[c]) {
				ret++;
				v[c] = false;
				for (int i = D[c]; i != c; i = D[i])
					for (int j = R[i]; j != i; j = R[j])
						v[col[j]] = false;
			}
		return ret;
	}
	void dance(int d) {
		if (d + f() >= ans_cnt)return;
		if (R[0] == 0) {
			if (d < ans_cnt)ans_cnt = d;
			return;
		}
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
			if (S[i] < S[c])
				c = i;
		for (int i = D[c]; i != c; i = D[i]) {
			remove(i);
			for (int j = R[i]; j != i; j = R[j])remove(j);
			dance(d + 1);
			for (int j = L[i]; j != i; j = L[j])resume(j);
			resume(i);
		}
	}
};
DLX g;

int n;
int hash[105];
void init() {
	vector<int> rec[105];
	vector<int> cell;
	int cnt = 1;
	for (int i = 1; i <= n; ++i) {
		cell.clear();
		for (int j = 1; j <= i; ++j) cell.pb(j), rec[cnt].pb(j);	//��
		for (int j = (2 * n + 1) * i + 1; j <= (2 * n + 1)*i + i; ++j) cell.pb(j), rec[cnt].pb(j);	//��
		for (int j = n + 1; j <= n + 1 + (2 * n + 1) * (i - 1); j += 2 * n + 1) cell.pb(j), rec[cnt].pb(j);	//��
		for (int j = n + i + 1; j <= n + i + 1 + (2 * n + 1) * (i - 1); j += 2 * n + 1) cell.pb(j), rec[cnt].pb(j);	//��
		++cnt;
		int sz = cell.size();
		for (int j = 1; j <= n - i + 1; ++j) {
			for (int k = 1; k <= n - i + 1; ++k) {
				if (j == 1 && k == 1) continue;
				int id = (2 * n + 1) * (k - 1) + j;
				for (int l = 0; l < sz; ++l) {
					rec[cnt].pb(cell[l] - cell[0] + id);
				}
				++cnt;
			}
		}
	}
	--cnt;
	g.init(2 * n * (n + 1), cnt);

	int m, rm;
	scanf("%d", &m);
	memset(hash, 0, sizeof(hash));
	for (int i = 0; i < m; ++i) {
		scanf("%d", &rm);
		hash[rm] = 1;
	}

	for (int i = 1; i <= cnt; ++i) {
		int flag = 0;
		for (int j = 0; j < rec[i].size(); ++j) {
			if (hash[rec[i][j]]) {
				flag = 1;
				break;
			}
		}
		if (flag) {	//ȥ��ĳЩ���
			g.R[g.L[i]] = g.R[i];
			g.L[g.R[i]] = g.L[i];
			continue;
		}
		for (int j = 0; j < rec[i].size(); ++j) {
			g.link(rec[i][j], i);
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		init();
		g.dance(0);
		printf("%d\n", g.ans_cnt);
	}
	return 0;
}
