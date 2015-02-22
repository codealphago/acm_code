/*poj 3696
  ���⣺
  ����һ������L,�����̵�888...8�ܱ�L�����������̵ĳ��ȡ�
  ���ƣ�
  1 <= L <= 2*10^9
  ˼·��
  ��xΪ��С����
  888...8=(10^x-1)/9*8
  ������ã�
  (10^x-1)/9*8 % L=0
  -> (10^x-1)*8 % (9L) = 0
  -> (10^x-1) % (9L/gcd(L,8)) = 0
  -> 10^x % (9L/gcd(L,8)) = 1
  �����һ����ɢ���������⣬��һ���뵽��������չBSGS��������ʱ�ˡ�
  ��Ϊ����Ϊ1
  �����뵽ŷ������a^phi(m) % m = 1 , ��a��m���ʵ������¡�
  �ص�����⣺
  ��10 �� 9L/gcd(L,8) �����ʵ������£��޽�
  ��10 �� 9L/gcd(L,8) ���ʵ�������
  ���tmp=phi(9L/gcd(L,8))��Ȼ��O(sqrt(tmp))ö��tmp�����ӣ�ѡ����С�ķ������������Ӿ����ˡ�
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define LL __int64
LL mul(LL a,LL b,LL m){
    LL ret = 0;
    a %= m;
    while(b){
        if(b & 1) ret = (ret + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return ret;
}
LL a_b_MOD_c(LL a, LL b, LL m){
	LL ret = 1;
	a %= m;
	while(b){
		if(b & 1) ret = mul(ret, a, m);
		a = mul(a, a, m);
		b >>= 1;
	}
	return ret;
}
bool test(LL n, LL a, LL d){
	if(n == 2) return true;
	if(n == a) return true;
	if((n & 1) == 0) return false;
	while(!(d & 1)) d = d >> 1;
	LL t = a_b_MOD_c(a, d, n);
	while((d != n-1) && (t != 1) && (t != n-1)){
		t = mul(t, t, n);
		d = d << 1;
	}
	return (t == n-1 || (d & 1) == 1);
}
//Ҫע��1�����
const int Times=10;
bool Miller_Rabin(LL n){
	if(n < 2) return false;
	for(int i = 0; i <= Times; ++i){
		LL a=rand()%(n-1)+1;
		if(!test(n, a, n-1)) return false;
	}
	return true;
}
LL pollard_rho(LL n,LL c){
	LL i=1,k=2;
	LL x=rand()%(n-1)+1;
	LL y=x;
	while(1){
		++i;
		x=(mul(x,x,n)+c)%n;
		LL d=__gcd((y-x+n)%n,n);
		if(1<d && d<n) return d;
		if(y==x) return n;
		if(i==k){
			y=x;
			k<<=1;
		}
	}
}
//Ҫע��1�����
//LL ans;
LL fac[105];
int tot;
void find_fac(LL n,int c){
	if(n==1) return ;
	if(Miller_Rabin(n)){
		//ans=min(ans,n);
		fac[tot++]=n;
		return ;
	}
	LL p=n;
	LL k=c;
	while(p>=n) p=pollard_rho(p,c--);
	find_fac(p,k);
	find_fac(n/p,k);
}
void init(){
	//ans=n;
	tot=0;
}
//С��1�����
LL get_phi(LL x){
	init();
	find_fac(x,12345);
	sort(fac,fac+tot);
	LL ret=1;
	for(int i=0;i<tot;++i){
		LL sqr=fac[i]*fac[i];
		if(x%sqr) ret*=fac[i]-1;
		else ret*=fac[i];
		x/=fac[i];
	}
	return ret;
}
int main(){
	LL L;
	int cas=0;
	int t;
	srand(12345);
	while(scanf("%I64d",&L) && L){
		LL m=L*9/__gcd(L,(LL)8);
		//cout<<m<<endl;
		printf("Case %d: ",++cas);
		if(__gcd(m,(LL)10)!=1) puts("0");
		else{
			LL phi=get_phi(m);
			//cout<<phi<<endl;
			int lim=sqrt(phi);
			LL ans=phi;
			for(int i=1;i<=lim;++i){
				if(phi%i==0){
					if(a_b_MOD_c(10,i,m)==1)
						ans=min((LL)i,ans);
					else if(a_b_MOD_c(10,phi/i,m)==1)
						ans=min(phi/i,ans);
				}
			}
			printf("%I64d\n",ans);
		}
	}
	return 0;
}
