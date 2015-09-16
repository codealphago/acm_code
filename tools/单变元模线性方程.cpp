/*poj 2115
  ���⣺
  ����a,b,c,k,��x,ʹ��(a+c*x)%(2^k)=b
  ���ƣ�
  0 <= a,b,c < 2^k; 1 <= k <= 32
  ˼·��
  ��չŷ����õ���Ԫģ���Է���
  �� A=c;C=((b-a)%(2^k)+2^k)%(2^k);B=2^k
  �������ͻ�ΪAx%n=B

  ����Ax%B=C
  -> Ax+By=C
  -> d=Ext_gcd(A,B,x,y)	//d��ʵΪgcd(A,B)
  -> if(C%d!=0) �޽� else �н�
  -> x=(x*(C/d)%(B/d)+(B/d))%(B/d)	------1ʽ	//Ϊ��С��Ȼ����(��СΪ0)

  �����Ƶ�1ʽ��
  ��Ax%B=C ��: Ax+By=C
  d=gcd(A,B),�����һ��x1,y(��������չŷ��������)ʹ�� d=Ax1+By ---2ʽ
  ��"2ʽ"����ͬʱģB�ã�d%B=Ax1%B ---3ʽ
  ����Ϊ��C%d==0
  ����(B/d)Ϊ����
  ������"3ʽ"�ã�C%B=(C/d)*d%B  =  (C/d)*Ax1%B=A(x1*C/d)%B
  ����C%B=A(x1*C/d)%B
  ����x=x1*(C/d)��һ��������
  ��Ax%B=C -> (A/d)x%(B/d)=C/d -> ���Կ����⼯Ϊx+k*(B/d) (k=����)
  ������С������x0 = (x%(B/d)+(B/d))%(B/d) = (x1*(C/d)%(B/d)+(B/d))%(B/d)
 */
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define LL __int64
LL Ext_gcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) { x = 1, y = 0; return a; }
	LL ret = Ext_gcd(b, a % b, y, x);
	y -= a / b * x;
	return ret;
}
//ax%n=b,���%n��Χ�ڵõ����н�,������ò���
vector<LL> line_mod_equ(LL a, LL b, LL n) {
	LL x, y;
	LL d = Ext_gcd(a, n, x, y);
	vector<LL> ans;
	ans.clear();
	if (b % d == 0) {
		x = (x % n + n) % n;
		ans.push_back(x * (b / d) % (n / d));
		for (LL i = 1; i < d; ++i)
			ans.push_back((ans[0] + i * n / d) % n);
	}
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return ans;
}
int main() {
	LL a, b, c, k;
	while (scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &k) && (a || b || c || k)) {
		k = (1LL << k);
		a = ((b - a) % k + k) % k;
		LL x, y;
		LL d = Ext_gcd(c, k, x, y);
		if (a % d) puts("FOREVER");
		else {
			x = (a / d * x % (k / d) + (k / d)) % (k / d);
			//line_mod_equ(c,a,k);
			printf("%I64d\n", x);
		}
	}
	return 0;
}
