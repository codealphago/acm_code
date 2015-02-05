/*hdu5160
  ���⣺
  ����Ҫ��n��С���ѷ�ƻ������ƻ����ʱ��С�����ȴ��������վ��һ�š���վ�ú������С���ѵı���� p1,p2,p3,...,pn����������Ҫ��ƻ����Ŀ�� Ap1,Ap2,Ap3,...,Apn����������ߵ���Ҫ������ Ap1��ƻ�������ڵ�i (i>1)���ˣ����ǰ����һ���˵�ƻ��Ҫ�����Ŀ�����࣬��ô�Ͳ��÷�����ƻ�������򷢸��� Api��ƻ������ô����ĳһ��������Ҫ����ƻ���Ϳ��Լ�������ˡ�����������֪���������е������ܹ�Ҫ������ƻ�����������в�һ�����ҽ������ٴ���һ��λ��Ҫ���ƻ����Ŀ��һ����
  ���ƣ�
  1 <= n <= 100000
  1 <= Ai <= 1000000000
  ˼·��
  ��Ϊnֻ��100000�����Զ���ÿ��Api�����O(1)����O(log(n))�������ͳ���˶��ٴξ��ܽ��������⡣
  ������������ô���Api��ͳ���˶��ٴΣ�����һ�������ѧ�����⣬�磺
  ������һ������
  �±꣺ 1 2 3 4 5 6 7 8 9 10
  ��ֵ�� 1 1 1 2 2 3 3 4 4 5
  ������Ҫ���±�Ϊ6����ֵ3��ͳ���˶��ٴΣ�
  C(10,3)*C(7,2) * C(4,1)*C(3,2)*C(1,1)
  ͳ��ǰ���       ͳ�ƺ����(3445)����
  (11122)������    �����
  ���
  ͬ�������±�Ϊ7����ֵ3��ͳ���˶��ٴΣ�
  C(10,3)*C(7,2) * C(3,2)*C(1,1)
  ͳ��ǰ���       ͳ�ƺ����(445)
  (11122)������    ���������
  ���

  Ȼ�����ǿ��Է���ǰ��ͺ���������������Ԥ���������Ȼ�����Ǻ���Ϳ���O(1)�õ�Api��ͳ���˶��ٴΡ�
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define LL __int64
const int N=100005;
const int MOD=1000000007;
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
	if(b==0) { x=1, y=0; return a; }
	LL ret= Ext_gcd(b,a%b,y,x);
	y-= a/b*x;
	return ret;
}

LL Inv(LL a,int m){ //����Ԫ
	LL d,x,y,t= (LL)m;
	d= Ext_gcd(a,t,x,y);
	if(d==1) return (x%t+t)%t;
	return -1;
}

LL Cm(LL n, LL m, LL p){ //�������
	LL a=1, b=1;
	if(m>n) return 0;
	while(m){
		a=(a*n)%p;
		b=(b*m)%p;
		m--;
		n--;
	}
	return (LL)a*Inv(b,p)%p;
}
struct Dt{
	LL x;
	int cnt;
	Dt(){}
	Dt(LL _x,int _c){
		x=_x;
		cnt=_c;
	}
};
LL a[N],fro[N],bac[N];
int main(){
	int T;
	int n,cas=0;
	scanf("%d",&T);
	while(T--){
		memset(fro,0,sizeof(fro));
		memset(bac,0,sizeof(bac));
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%I64d",&a[i]);
		sort(a,a+n);

		int len=n,cnt=1;
		fro[0]=1;
		for(int i=1;i<n;++i){
			if(a[i]==a[i-1]){
				++cnt;
				fro[i]=fro[i-1];
			}
			else{
				fro[i]=fro[i-1]*Cm(len,cnt,MOD)%MOD;
				len-=cnt;
				cnt=1;
			}
		}

		LL pre=1,cnm=1;
		len=cnt=1;
		bac[n-1]=1;
		for(int i=n-2;i>=0;--i){
			++len;
			if(a[i]==a[i+1]){
				++cnt;
				cnm=cnm*len%MOD*Inv(cnt,MOD)%MOD;	//cnm*lenҪMOD,�����˱�long long
				bac[i]=pre*cnm%MOD;
			}
			else{
				cnt=1;
				cnm=len;
				pre=bac[i+1];
				bac[i]=pre*cnm%MOD;
			}
		}
		bac[n]=1;
		LL ans=0;

		for(int i=0;i<n;++i){
			ans=(ans+(fro[i]*bac[i+1]%MOD*a[i]%MOD))%MOD;
		}
		printf("Case #%d: %I64d\n",++cas,ans);
	}
	return 0;
}
