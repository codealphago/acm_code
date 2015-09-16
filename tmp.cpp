/*--------------------------------------------
 * File Name: EX
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-04 14:22:48
 --------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
//�ⷽ��ax+by=gcd(a,b) ����gcd(a,b) �õ�һ���ؽ�(x,y)
LL extend_Euclid(LL a, LL b, LL &x, LL &y){
	if(b==0){
		x=1; 
			y = 0;
		return a;
	}
	LL r = extend_Euclid(b, a%b, y, x);
	y -= a/b*x;
	return r;
}
#define N 10
//���ax+by=c ����0Ϊ�޽�,���򷵻�gcd(a,b)����,��X[],Y[]��;
LL X[N], Y[N];

LL equation(LL a, LL b, LL c)
{
	LL x, y;
	LL g = extend_Euclid(a, b, x, y);
	if(c % g)
	  return 0;    //��ʾ�޽�
	x *= c/g, y *= c/g;
	for(int k = 0;k < g;k++)
	{
		X[k] = (x+b/g*k)%b;
		Y[k] = (c-a*X[k])/b;
	}
	return g;
}

//���ax=b(mod m) ����0Ϊ�޽⣬���򷵻�gcd(a,m)��mod m�����µĽ�,��X[]��
LL mod(LL a, LL b, LL m)
{
	return equation(a, m, b);
}

void eq_set()
{
	LL n, b1, m1, b2, m2, m;
	while(~scanf("%lld", &n))
	{
		scanf("%lld%lld", &m1, &b1);
		n--;
		LL r = 1;
		while(n--)
		{
			scanf("%lld%lld", &m2, &b2);
			if(!r)
			  continue;
			r = equation(m1, m2, b2-b1);
			if(!r)
			  continue;
			b1 += m1*X[0];
			m1 = m1/r*m2;
			b1 = (b1%m1+m1)%m1; 
		}
		if(!r)
		{
			printf("-1\n");
			continue;
		}
		mod(1, b1, m1);
		printf("%lld\n", (X[0]%m1+m1)%m1);
	}
	return;
}

int main()
{
	eq_set();
	return 0;
}
