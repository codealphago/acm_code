/*bzoj 2299
  ���⣺
  ����һ����a,b�����������ʹ��(a,b), (a,-b), (-a,b), (-a,-b), (b,a), (b,-a), (-b,a), (-b,-a)��Щ�����������ܲ���ƴ����һ������(x,y)��
  ���ƣ�
  -2*1e9 <= a,b,x,y <= 2*1e9
  ˼·��
  ��Ŀ�Ĳ������Ի�Ϊ��
  1. x +- 2a;
  2. y +- 2a;
  3. x +- 2b;
  4. y +- 2b;
  5. x + a && y + b;
  6. x + b && y + a;
  7. x + a + b  && y + a + b;
  ����5��6��7���ִ��һ�Ρ�
  ֤����
  ԭ����(x,y)�������ƴ�����Ļ���һ���ǣ�
  (t1*a + t2*b, t3*a + t4*b)
  t1��t2��t3��t4����ż�Ծ���5��6��7��ִ�д�����
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
bool ok(LL x,LL y,LL d){
	if(x%d==0 && y%d==0) return true;
	return false;
}
int main(){
	LL a,b,x,y;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
		LL d=__gcd(2*a,2*b);
		if(ok(x,y,d) || ok(x+a,y+b,d) || ok(x+b,y+a,d) || ok(x+a+b,y+a+b,d)) puts("Y");
		else puts("N");
	}
	return 0;
}
