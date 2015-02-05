/*poj1221
  ���⣺
  ������֣��ԳƲ��
  ���磺4: (4), (1 2 1), (2 2), (1 1 1 1) 
  ����һ������n�����ֵ���������
  ���ƣ�
  0 <= n < 250
  ˼·��
  ĸ����
  G[x]=(1+x+x^2+...)*(1+x^2+x^4+...)*(1+x^3+x^6+...)*...*(1+x^m+x^(2*m)+...)
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=250;
LL c1[N],c2[N];
//G[x]=(1+x+x^2+...)*(1+x^2+x^4+...)*(1+x^3+x^6+...)*...*(1+x^m+x^(2*m)+...)
LL mhs(int n,int m){
	for(int i=0;i<=n;++i)	//��һ�����ʽ
		c1[i]=1,c2[i]=0;
	for(int i=2;i<=m;++i){	//��i�����ʽ
		for(int j=0;j<=n;++j)	//��i�����ʽ�ĵ�j��
			for(int k=0;k+j<=n;k+=i)	//ת��
				c2[j+k]+=c1[j];
		for(int j=0;j<=n;++j)
			c1[j]=c2[j],c2[j]=0;
	}
	return c1[n];
}
int n;
void gao(){
	LL ans=0;
	if(n&1){
		for(int i=1;i<=n;i+=2)
			ans+=mhs((n-i)/2,i);
	}
	else{
		ans=mhs(n/2,n);
		for(int i=2;i<=n;i+=2)
			ans+=mhs((n-i)/2,i);
	}
	printf("%d %I64d\n",n,ans);
}
int main(){
	while(scanf("%d",&n) && n){
		gao();
	}
	return 0;
}
