/*spoj 1812 LCS2 - Longest Common Substring II
  ���⣺
  �������n���ַ���A[1], ..., A[n], ����n���ַ�����������Ӵ���
  ���ƣ�
  1 <= n <= 10
  |A[i]| <= 1e5
  ˼·��
  ��spoj 1811 LCS��������

  ������һ��A����׺�Զ���
  ����һ��״̬s, ���A֮���������������ƥ�䳤�ȷֱ���a[1], a[2], ..., a[n - 1], ��ômin(a[1], a[2], ..., a[n - 1], Max(s))�Ϳ��Ը��´𰸡�

  ע��:
  ��������Ƕ�������һ��Right�����е�r������ƥ�䳤�ȡ���ô����һ��״̬s�����Ľ����ȻҲ������Ϊ��Parent�Ľ�������ǿ��Դӵ׵��ϸ���һ�顣
  �������ͨ��һ����������㶨��
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;
char str[15][N];

int maxx[2 * N], minn[2 * N];

struct SAM {
	struct Node {
		int fa, ch[27];
		int val;
		void init() {
			fa = val = 0;
			memset(ch, 0, sizeof(ch));
		}
	} node[2 * N];

	int tot;
	int new_node() {
		node[++tot].init();
		return tot;
	}

	int root, last;
	void init() {
		root = last = tot = 1;
		node[0].init();
		node[1].init();
	}

	void add(int x) {
		int p = last;
		int np = new_node(); node[np].val = node[p].val + 1;
		while (p && node[p].ch[x] == 0) {
			node[p].ch[x] = np;
			p = node[p].fa;
		}
		if (p == 0)
			node[np].fa = root;
		else {
			int q = node[p].ch[x];
			if (node[p].val + 1 == node[q].val)
				node[np].fa = q;
			else {
				int nq = new_node(); node[nq].val = node[p].val + 1;
				memcpy(node[nq].ch, node[q].ch, sizeof(node[q].ch));
				node[nq].fa = node[q].fa;
				node[q].fa = node[np].fa = nq;
				while (p && node[p].ch[x] == q) {
					node[p].ch[x] = nq;
					p = node[p].fa;
				}
			}
		}
		last = np;
	}
	void debug() {
		for (int i = 1; i <= tot; ++i) {
			printf("id=%d, fa=%d, step=%d, ch=[ ", i, node[i].fa, node[i].val);
			for (int j = 0; j < 26; ++j) {
				if (node[i].ch[j])
					printf("%c,%d ", j + 'a', node[i].ch[j]);
			}
			puts("]");
		}
	}

	void gao(int);
} sam;

int du[2 * N];
int que[2 * N], fr, ta;
int b[2 * N], b_tot;

void SAM::gao(int n) {
	init();
	int len1 = strlen(str[0]);
	for (int i = 0; i < len1; ++i)
		add(str[0][i] - 'a');

	//debug();

	b_tot = fr = ta = 0;
	for (int i = 1; i <= tot; ++i)
		++du[node[i].fa];
	for (int i = 1; i <= tot; ++i)
		if (du[i] == 0) que[ta++] = i, b[b_tot++] = i;
	while (fr != ta) {
		int u = que[fr++];
		int v = node[u].fa;
		--du[v];
		if (du[v] == 0) que[ta++] = v, b[b_tot++] = v;
	}

	for (int i = 1; i <= tot; ++i)
		minn[i] = node[i].val;
	for (int i = 1; i < n; ++i) {
		int len = strlen(str[i]);
		int p = root;
		int tmp = 0;
		fill(maxx, maxx + tot + 1, 0);
		for (int j = 0; j < len; ++j) {
			int x = str[i][j] - 'a';
			if (node[p].ch[x]) {
				++tmp;
				p = node[p].ch[x];
			} else {
				while (p && node[p].ch[x] == 0)
					p = node[p].fa;
				if (p) {
					tmp = node[p].val + 1;
					p = node[p].ch[x];
				} else {
					p = root;
					tmp = 0;
				}
			}
			maxx[p] = max(maxx[p], tmp);
		}
		for (int j = 0; j < tot; ++j) {
			int u = b[j];
			minn[u] = min(minn[u], maxx[u]);
			int v = node[u].fa;
			maxx[v] = max(maxx[v], maxx[u]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= tot; ++i)
		ans = max(ans, minn[i]);
	printf("%d\n", ans);
}

int main() {
	int n = 0;
	while (scanf("%s", str[n]) != EOF) ++n;
	sam.gao(n);
	return 0;
}
