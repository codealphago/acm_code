/*hdu 3579
  ���⣺
  ����m_1,m_2,...m_n;a_1,a_2,...,a_n,�ǻ����й�ʣ�ඨ��
  ˼·��
  �й�ʣ�ඨ��

  ���ڲ��������ʣ�����ֻ�����������⡣
  ��ͨ��ΪN
  ->N=m1*k1+r1,N=m2*k2+r2
  ->m1*k1+r1=m2*k2+r2
  ->k1*m1+(-k2*m2)=r2-r1
  ->��a=m1,b=m2,x=k1,y=(-k2),c=r2-r1
  ->ax+by=c ͨ�� d=ext_gcd(a,b,x,y) �� d,x
  ->��С������x=(x*(c/d)%(b/d)+(b/d))%(b/d)
  ->N=a*(x+n*(b/d))+r1
  ->N=(a*b/d)*n+(a*x+r1)
  ->��m3=a*b/d,r3=a*x+r1,k3=n
  ->N=m3*k3+r3 ������һ���µ�ʽ�ӣ����ϵ���Ȼ��������
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
LL ext_gcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) { x = 1, y = 0; return a; }
	LL ret = ext_gcd(b, a % b, y, x);
	y -= a / b * x;
	return ret;
}
int n;
LL a[100005], m[100005];
LL CRT() {
	LL M = m[0];
	LL ret = a[0];
	for (int i = 1; i < n; ++i) {
		LL x, y, d;
		d = ext_gcd(M, m[i], x, y);
		if ((a[i] - ret) % d) return -1;	//ע���޽�ʱ�ķ���ֵ
		x = (a[i] - ret) / d * x % (m[i] / d);
		ret += x * M;
		M = M / d * m[i];
		ret %= M;
	}
	ret = (ret + M) % M;
	return ret == 0 ? M : ret;	//ģ��������Ҫע����ܲ���Ϊ0
}
int main() {
	int T;
	int cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%I64d", &m[i]);
		for (int i = 0; i < n; ++i)
			scanf("%I64d", &a[i]);
		printf("Case %d: %I64d\n", ++cas, CRT());
	}
	return 0;
}
