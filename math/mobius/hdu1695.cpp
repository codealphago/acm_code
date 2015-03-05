/*hdu 1695
  ���⣺
  ����a,b,c,d,k, ������a <= x <= b && c <= y <= d && gcd(x,y)=k ������(x,y)�Ķ�����
  ���ƣ�
  a=c=1; 0 < b,c <= 1e5; (n1,n2) �� (n2,n1) ��Ϊͬ�����
  ˼·��
  ��ʵ��������1 <= x <= b/k && 1 <= y <= d/k && gcd(x,y)=1 �� ����(x,y)�Ķ�����
  Ī����˹����������
  ��f(k)Ϊgcd(x,y)=k������(x,y)�Ķ���������Ҫ�����f(1)
  ��F(k)Ϊgcd(x,y)Ϊk�ı���������(x,y)�Ķ����������뵽F(k)=floor(b/k)*floor(d/k)��
  ��Ī����˹���ݵã�
  ��lim=min(b/k,d/k)
  f(1)=mu[1]*F(1) + mu[2]*F[2] + ... + mu[lim]*F(lim)
  ��Ϊ(n1,n2)��(n2,n1)��Ϊͬһ������������������Ҫ�����ظ��������
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=1e5+5;
int mu[N];
//O(nlog(n))
void getMu(){
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
}

int main(){
	int T,cas=0;
	int a,b,c,d,k;
	getMu();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		printf("Case %d: ",++cas);
		if(k==0){
			puts("0");
			continue;
		}
		b/=k;
		d/=k;
		if(b>d) swap(b,d);
		LL ans1=0;
		for(int i=1;i<=b;++i)
			ans1+=(LL)mu[i]*(b/i)*(d/i);
		LL ans2=0;
		for(int i=1;i<=b;++i)
			ans2+=(LL)mu[i]*(b/i)*(b/i);
		ans1-=ans2/2;
		printf("%I64d\n",ans1);
	}
	return 0;
}
