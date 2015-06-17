/*poj 1845 Sumdiv
  ���⣺
  ����������a,b����a^b��Լ���ĺͣ����ģ9901��
  ���ƣ�
  0 <= a,b <= 50000000
  ˼·��
  Լ���͹�ʽ��
  �����Ѿ��ֽ������a=(p1^k1)*(p2^k2)*(p3^k3)*....*(pn^kn)
  ��a������Լ��֮��Ϊ
  S=(1+p1+p1^2+p1^3+...p1^k1) * (1+p2+p2^2+p2^3+��.p2^k2) * (1+p3+ p3^3+��+ p3^k3) * .... * (1+pn+pn^2+pn^3+...pn^kn)
  Ȼ��a^b��Լ����Ҳ�Ϳ��Եõ���

  ���и�Ҫע��ĵط��ǣ�
  ���ģ9901�����a��9901�󣬻�������⣬���Եȱ��������ʱҪ�õ����Ʒ��ε�˼�롣
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
const int MOD=9901;
const int N=105;
int f[N],cnt[N],tot;
LL a_b_MOD_c(LL a,LL b,LL mod){
	LL ret = 1;
	a %= mod;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
//�ȱ��������mod�ر����
//����a=0�����
LL dbsum(LL a,LL b,LL mod){
	if(b==0)
		return 1;
	if(b&1)
		return (a_b_MOD_c(a,(b+1)/2,mod)+1)*dbsum(a,b/2,mod)%mod;
	else
		return ((a_b_MOD_c(a,b/2,mod)+1)*dbsum(a,(b-1)/2,mod)%mod + a_b_MOD_c(a,b,mod))%mod;
}
void gao(int n,int m){
	//if(n==0){ puts("0"); return ; }
	tot=0;
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			f[tot]=i;
			cnt[tot]=0;
			while(n%i==0){
				++cnt[tot];
				n/=i;
			}
			++tot;
		}
	}
	if(n>1){
		f[tot]=n;
		cnt[tot]=1;
		++tot;
	}
	for(int i=0;i<tot;++i){
		cnt[i]*=m;
	}
	LL ans=1;
	for(int i=0;i<tot;++i){
		//cout<<dbsum(i)<<endl;
		ans=ans*dbsum(f[i],cnt[i],MOD)%MOD;
	}
	printf("%lld\n",ans);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	gao(n,m);
	return 0;
}
