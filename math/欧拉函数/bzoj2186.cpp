/*bzoj 2186 [Sdoi2008]ɳ������������
  ���⣺
  ���̹���Ϊͨ�����ͣ��Լ��ٳ����ģ����������Ƴ�һ���µ����ߣ����г�Ʊ��ŷ�ΧΪ1��N�Ľ׳ˣ����ǣ�����ֻ���б����M!���ʵĳ�Ʊ�����ز���һ��ɳ����������Ԥ��һ�´��̹����������泮Ʊ�����������ڣ��������ɳ���������������⣬���ڿ��������ǳ�����ֻ��������Rȡģ��Ĵ𰸼��ɡ�R��һ��������
  ���ƣ�
  ��������T��1 <= T <= 10000
  R <= 1e9+10
  1 <= N,M <=10000000
  ˼·��
  ���ȴ�Ϊ��
  phi(m!)*n!/m!
  ֤���������£�
  gcd(a,b)=1 <=> gcd(a+b,b)=1
  phi(m!)��ʾС��m!����m!���ʵ����ĸ�����
  ����������Ϊp[1],p[2],p[3],...,p[k]������gcd(p[i],m!)=1������1 <= i <= k��
  ����gcd(p[i]+m!,m!)=1��
  ��������Ϊphi(m!)*n!/m!

  Ȼ����������phi(m!)�������棬
  ����ŷ�������й�ʽ��
  phi(x)=x * (p[1] - 1)/p[1] * (p[2] - 1)/p[2] * ... * (p[k] - 1)/p[k]������p[i] (1 <= i <= k) Ϊx��������
  ���ԣ���һ��m!�������Ӽ��ɣ���Ϊ1~m�ڵ�������
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
const int N=1e7+5;
LL fac[N];

LL ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}

//Ҫ��a��m����
LL inv(LL a,int m){   //����Ԫ
    LL d,x,y,t= (LL)m;
    d= ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}

bool is_pri[N];
//int pri[N], tot;
void get_pri(int n){
	//tot = 0;
	memset(is_pri, 1, sizeof(is_pri));
	is_pri[0] = is_pri[1] = 0;
	for(int i = 2; i <= n; ++i)
		if(is_pri[i]){
			if(n / i < i) break;
			for(int j = i * i; j <= n; j += i) is_pri[j] = false;
		}
	//for(int i = 2; i <= n; ++i) if(is_pri[i]) pri[tot++] = i;
}

LL ans[N];

void predo(int mod){
	fac[0]=1;
	for(int i=1;i<N;++i){
		fac[i]=fac[i-1]*i%mod;
	}
	get_pri(N-1);
	ans[0]=1;
	for(int i=1;i<N;++i){
		ans[i]=ans[i-1];
		if(is_pri[i]) ans[i]=ans[i]*(i-1)%mod*inv(i,mod)%mod;
	}
}

void gao(int n,int m,int mod){
	printf("%lld\n",ans[m]*fac[n]%mod);
}

int main(){
	int T,R;
	scanf("%d%d",&T,&R);
	predo(R);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		gao(n,m,R);
	}
	return 0;
}
