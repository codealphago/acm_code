/*bzoj 1251 �����ս���
  ���⣺
  ����һ������ΪN�����У�ÿ�����е�Ԫ����һ��������Ҫ֧���������ֲ�����
  1. ��[L,R]��������ڵ�����������V;
  2. ��[L,R]������䷭ת������1 2 3 4���4 3 2 1;
  3. ��[L,R]��������е����ֵ;
  �ʼ����Ԫ�ض���0��
  ���ƣ�
  N <= 50000, M <= 100000
  ˼·��
  ��չ��

  �ؼ��㣺
  1. ��չ��Ϊ��С�Ҵ�Ķ�������������ת��������Ӱ����������
  2. �������Ϊ��
		int u = select(L - 1), v = select(R + 1);
		splay(u, 0); splay(v, u);	//ͨ����ת������ѯ�ʵ�����ۼ�����������������������
	 ��Ϊ��չ��Ϊ��С�Ҵ�Ķ���������ת����������Զ��ڱ�����[L, R]֮�������Ԫ�ض��ۼ��ڸ�������������������
	 ��Ϊ������[L, R]��
	 1) ����ÿ�ζ�Ҫ�鿪����(L - 1, R + 1)��
	 2) ������չ��Ԫ��1��Ӧ�ı��Ϊ2��
	 3) ����node[0]��Ӧ�սڵ㣬node[1]��Ӧ������Ԫ�ر�Ŷ�С�ĵ㣬node[2 ~ n + 1]��ӦԪ��1 ~ n��node[n + 2]��Ӧ������Ԫ�ر�Ŷ���ĵ㣬����node[0], node[1], node[n + 2]������ڵ㣬�������κ�Ԫ�ء�
 */
#include <iostream>
#include <cstdio>
using namespace std;

#define LS(x) node[(x)].ch[0]
#define RS(x) node[(x)].ch[1]

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
struct Splay {
	struct Node {
		int fa, ch[2];
		bool rev;
		int val, add, maxx, size;
		void init(int _val) {
			val = maxx = _val;
			size = 1;
			add = rev = ch[0] = ch[1] = 0;
		}
	} node[N];
	int root;

	void up(int x) {
		node[x].maxx = max(node[x].val, max(node[LS(x)].maxx, node[RS(x)].maxx));
		node[x].size = node[LS(x)].size + node[RS(x)].size + 1;
	}

	void down(int x) {
		if (x == 0) return ;
		if (node[x].add) {
			if (LS(x)) {
				node[LS(x)].val += node[x].add;
				node[LS(x)].maxx += node[x].add;
				node[LS(x)].add += node[x].add;
			}
			if (RS(x)) {
				node[RS(x)].val += node[x].add;
				node[RS(x)].maxx += node[x].add;
				node[RS(x)].add += node[x].add;
			}
			node[x].add = 0;
		}
		if (node[x].rev) {
			if (LS(x)) node[LS(x)].rev ^= 1;
			if (RS(x)) node[RS(x)].rev ^= 1;
			swap(LS(x), RS(x));
			node[x].rev = 0;
		}
	}

	void rotate(int x, bool kind) {
		int fx = node[x].fa;
		int ffx = node[fx].fa;
		node[fx].ch[!kind] = node[x].ch[kind];
		node[node[x].ch[kind]].fa = fx;

		node[x].ch[kind] = fx;
		node[fx].fa = x;

		node[ffx].ch[RS(ffx) == fx] = x;
		node[x].fa = ffx;
		up(fx);
	}

	void splay(int x, int goal) {
		while (node[x].fa != goal) {
			int fx = node[x].fa;
			int ffx = node[fx].fa;
			down(ffx); down(fx); down(x);
			bool rotate_x = (LS(fx) == x);
			bool rotate_fx = (LS(ffx) == fx);
			if (ffx == goal) rotate(x, rotate_x);
			else {
				if (rotate_x == rotate_fx) rotate(fx, rotate_fx);
				else rotate(x, rotate_x);
				rotate(x, rotate_fx);
			}
		}
		up(x);
		if (goal == 0) root = x;
	}

	int select(int pos) {
		int u = root;
		down(u);
		while (node[LS(u)].size != pos) {
			if (pos < node[LS(u)].size)
				u = LS(u);
			else {
				pos -= node[LS(u)].size + 1;
				u = RS(u);
			}
			down(u);
		}
		return u;
	}

	int query(int L, int R) {
		int u = select(L - 1), v = select(R + 1);
		splay(u, 0); splay(v, u);	//ͨ����ת������ѯ�ʵ�����ۼ�����������������������
		return node[LS(v)].maxx;
	}

	void update(int L, int R, int val) {
		int u = select(L - 1), v = select(R + 1);
		splay(u, 0); splay(v, u);
		node[LS(v)].val += val;
		node[LS(v)].maxx += val;
		node[LS(v)].add += val;
	}

	void reverse(int L, int R) {
		int u = select(L - 1), v = select(R + 1);
		splay(u, 0); splay(v, u);
		node[LS(v)].rev ^= 1;
	}

	int build(int L, int R) {
		if (L > R) return 0;
		if (L == R) return L;
		int mid = (L + R) >> 1;
		int r_L, r_R;
		LS(mid) = r_L = build(L, mid - 1);
		RS(mid) = r_R = build(mid + 1, R);
		node[r_L].fa = node[r_R].fa = mid;
		up(mid);
		return mid;
	}

	void init(int n) {
		node[0].init(-INF); node[0].size = 0;
		node[1].init(-INF);
		node[n + 2].init(-INF);
		for (int i = 2; i <= n + 1; ++i)
			node[i].init(0);

		root = build(1, n + 2);
		node[root].fa = 0;

		node[0].fa = 0;
		LS(0) = root;
	}
} splay_tree;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	splay_tree.init(n);
	for (int i = 0; i < m; ++i) {
		int op, l, r, v;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &l, &r, &v);
			splay_tree.update(l, r, v);
		} else if (op == 2) {
			scanf("%d%d", &l, &r);
			splay_tree.reverse(l, r);
		} else {
			scanf("%d%d", &l, &r);
			printf("%d\n", splay_tree.query(l, r));
		}
	}
	return 0;
}
