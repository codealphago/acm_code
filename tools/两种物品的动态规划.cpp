/*codeforces 526 c Om Nom and Candies
  ���⣺
  ����һ������Ϊc������������Ʒ�ļ�ֵhr,hb������cr,cb����װ��������װ������ֵ��
  ���ƣ�
  1 <= c,hr,hb,wr,wb <= 1e9
  ˼·��
  ʣ��ϵ
  ���һ����Ʒ��x�����ڶ�����Ʒ��y�������У�
  x*hr + y*hb <= c
  ���У�
  (c-y*hb) % hr = t
  ���ѿ�������ͬһ��ʣ��ϵt������ֵ�����ˡ�
  �����������ʣ��ϵ���Ƚ�����ֵ���õ�ȫ�����š�
  ���Ӷ�O(sqrt(n))
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int N = 1000000;
#define LL __int64
map<LL, int> mp;
int a[N], r[N], cnt;
int main() {
	LL c, Hr, Hb, Wr, Wb;
	cin >> c >> Hr >> Hb >> Wr >> Wb;
	if (Wr < Wb) {
		swap(Hr, Hb);
		swap(Wr, Wb);
	}
	cnt = 0;
	LL lim = min(Wb + 1, c / Wr + 1);
	for (int i = 0; i <= lim; ++i) {
		LL tmp = ((c - Wr * i) % Wb + Wb) % Wb;
		if (mp.find(tmp) == mp.end()) {
			r[cnt] = tmp;
			a[cnt++] = i;
			mp[tmp] = 1;
		}
	}
	LL ans = 0;
	if (Hr * Wb <= Hb * Wr) {
		for (int i = 0; i < cnt; ++i) {
			LL tmp = Wr * a[i];
			if (tmp > c) continue;
			ans = max(ans, Hr * a[i] + (c - tmp) / Wb * Hb);
		}
	}
	else {
		for (int i = 0; i < cnt; ++i) {
			LL d = __gcd(Wr, Wb);
			LL nn = (c / Wr - a[i]) / (Wb / d);
			nn = nn * Wb / d + i;
			LL tmp = nn * Wr;
			if (tmp > c) continue;
			ans = max(ans, Hr * nn + (c - tmp) / Wb * Hb);
		}
	}
	cout << ans << endl;
	return 0;
}
