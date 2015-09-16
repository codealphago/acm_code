/*��ƫ��
  ��Ŀ���⣺
  N�����ӣ�����M�μܣ�ÿ�δ�ܵ�ʱ��˫�����Ӷ����ɳ��Լ�һ��ս������ߵĺ��ӣ�����ܺ�����ֻ���ӵ�ս���������롣ͬʱ��������ʶ��������Ӵ���ܺ�ͻ�����ʶ���ͬ�ﲻ���ٴ�ܡ����ÿ�δ�ܺ�ͨ����γ�ͻ�ϲ�����һ�������ս������ߵĺ��ӵ�ս����ֵ�������ͻ˫����ͬһ��Ļ�ֱ�����-1�ͺá�
  ��Ŀ���ƣ�
  N<=100000
  M<=100000
 */
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 100005
struct node {
	int l, r, value, dis;
} mon[N];
int n, m, f[N];
void init() {
	int i;
	for (i = 0; i <= n; ++i)
		f[i] = i;
	memset(mon, 0, sizeof(mon));
}
int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}
int merge(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	if (mon[a].value < mon[b].value)
		swap(a, b);
	mon[a].r = merge(mon[a].r, b);
	f[mon[a].r] = a;
	if (mon[mon[a].l].dis < mon[mon[a].r].dis)
		swap(mon[a].l, mon[a].r);
	if (mon[a].r == 0)
		mon[a].dis = 0;
	else
		mon[a].dis = mon[mon[a].r].dis + 1;
	return a;
}
int solve(int a, int b) {
	int fa = find(a), fb = find(b), tmp;
	if (fa == fb) return -1;
	mon[fa].value /= 2;
	tmp = merge(mon[fa].l, mon[fa].r);
	mon[fa].l = mon[fa].r = mon[fa].dis = 0;
	int fa_root = merge(tmp, fa);

	mon[fb].value /= 2;
	tmp = merge(mon[fb].l, mon[fb].r);
	mon[fb].l = mon[fb].r = mon[fb].dis = 0;
	int fb_root = merge(tmp, fb);

	tmp = merge(fa_root, fb_root);
	f[fa] = f[fb] = f[fa_root] = f[fb_root] = f[a] = f[b] = tmp;
	return mon[tmp].value;
}
int main() {
	int a, b, i;
	while (scanf("%d", &n) != EOF) {
		init();
		for (i = 1; i <= n; ++i)
			scanf("%d", &mon[i].value);
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			printf("%d\n", solve(a, b));
		}
	}
	return 0;
}
