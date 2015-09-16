/*���������
  poj 1151
  ��Ŀ���⣺
  (x1,y1),(x2,y2)���ɾ��Σ���N�����εĲ����������
  ��Ŀ����:
  x1;y1;x2;y2 (0 <= x1 < x2 <= 100000;0 <= y1 < y2 <= 100000)
 */

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define N 300
struct line {
	int f;
	double x, y1, y2;
} l[N];
struct node {
	int l, r, f;
	double ml, mr, len;
} v[N * 3];
double y[N];
bool cmp(line a, line b) {
	return a.x < b.x;
}
void build(int l, int r, int i) {
	v[i].l = l;
	v[i].r = r;
	v[i].ml = y[l - 1];	//��ֵ��ʱ��Ҫע��һ��
	v[i].mr = y[r - 1];	//
	v[i].f = 0;
	v[i].len = 0;
	if (v[i].l + 1 == v[i].r) {
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, i * 2);
	build(mid, r, i * 2 + 1); //����ʱע�����ﲻ��mid+1����Ϊ�������ʱ�����mid+1��ô���ص�ֵ���ӵ��ұ����к��ӵ�����޷���������
}
void callen(int i) {
	if (v[i].f > 0) {
		v[i].len = v[i].mr - v[i].ml;
	}
	else if (v[i].r - v[i].l == 1) {
		v[i].len = 0;
	}
	else {
		v[i].len = v[i * 2].len + v[i * 2 + 1].len;
	}
	return ;
}
void update(int i, line a) {
	if (v[i].ml == a.y1 && v[i].mr == a.y2) {
		v[i].f += a.f;
		callen(i);
		return ;
	}
	if (a.y2 <= v[i * 2].mr) update(i * 2, a);
	else if (a.y1 >= v[i * 2 + 1].ml) update(i * 2 + 1, a);
	else {
		line tmp = a;
		tmp.y2 = v[i * 2].mr;
		update(i * 2, tmp);
		tmp = a;
		tmp.y1 = v[i * 2 + 1].ml;
		update(i * 2 + 1, tmp);
	}
	callen(i);
	return ;
}
int main() {
	int cas = 0, cnt, i, n;
	double x1, x2, y1, y2, sum;
	while (scanf("%d", &n) && n) {
		cnt = 0;
		for (i = 0; i < n; ++i) {
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			l[cnt].x = x1;
			l[cnt].y1 = y1;
			l[cnt].y2 = y2;
			l[cnt].f = 1;
			y[cnt++] = y1;
			l[cnt].x = x2;
			l[cnt].y1 = y1;
			l[cnt].y2 = y2;
			l[cnt].f = -1;
			y[cnt++] = y2;
		}
		sort(l, l + cnt, cmp);
		sort(y, y + cnt);
		build(1, cnt, 1);
		update(1, l[0]);
		sum = 0;
		for (i = 1; i < cnt; ++i) {
			sum += v[1].len * (l[i].x - l[i - 1].x);
			update(1, l[i]);
		}
		cout << "Test case #" << ++cas << endl;
		cout << "Total explored area: " << fixed << setprecision(2) << sum << endl << endl;
	}
	return 0;
}

