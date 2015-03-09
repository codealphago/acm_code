/*bc32 1003 ��������
  ���⣺
  ���Ǹ������еݹ�ĺϷ��������еĶ��壺
  1. �������ǺϷ���������
  2. ���s��һ���Ϸ��������У���ô(s)Ҳ�ǺϷ���������
  3. ���a��b�ǺϷ��������У���ôabҲ�ǺϷ���������
  4. û����������ǺϷ���������

  �����������������ǺϷ���������
  (), (()), ()(), ()(())
  ����������������
  (, ), )(, ((), ((()

  ���ڣ�����Ҫ���쳤��Ϊn�ĺϷ��������У�ǰ���һЩ�����Ѿ��������ʿ��Թ�������ٺϷ����С�
  ���ƣ�
  1 <= n <= 1e6
  ˼·��
  �����ʣ���������a����������b��
  Ȼ��ans=C(a+b,a)-C(a+b,a-1)
  
  ֤����
  �����ȿ���һ�����������ľ���ģ�ͣ�

  ��n��1��m��-1(n>=m)����n+m�����ų�һ�У����������0<=k<=n+m��ǰk�����Ĳ��ֺ�Sk >= 0����������(������1��֮ͬ�����ڴ˴����ֺͿ���Ϊ0����Ҳ�Ǹ����������) ����ȼ�Ϊ��һ����������У���(0��0)���ߵ�(n��m)���Ҳ������Խ���x==y�ķ�����(�����ߵ�x==y�ĵ�)��
  ��(n��m)��任��(n+1��m)�㣬������������1��
  ������Ϊ��
  ((n+m+1, m)) - 2*((n+m+1-1, m-1))
  ��((n+m+1-1, m)) - ((n+m+1-1, m-1))

  ���ǴӺ���ǰ����Ȼ��')'�Ϳ��Ե���1��'('���Ե���-1���Ϳ����ˡ�
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int MOD=1000000007;
const int N=1e6+5;
char str[N];
LL fac[N],ny[N];
LL C(LL a,LL b){
	if(b<0 || a<0 || a<b) return 0;
	return fac[a]*ny[b]%MOD*ny[a-b]%MOD;
}
int n;
void gao(){
	int len=strlen(str);
	int c1=0,c2=0;
	for(int i=0;i<len;++i){
		if(str[i]=='(') ++c1;
		else ++c2;
		if(c1<c2){ puts("0"); return ; }
	}
	int a=n/2,b=n/2;
	a-=c1;
	b-=c2;
	//cout<<a<<' '<<b<<endl;
	if(a<0 || b<0){ puts("0"); return ; }
	LL ans=(C(a+b,a)-C(a+b,a-1)+MOD)%MOD;
	printf("%I64d\n",ans);
}
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}
void predo(){
	fac[0]=1;
	ny[0]=inv(fac[0],MOD);
	for(int i=1;i<N;++i){
		fac[i]=fac[i-1]*i%MOD;
		ny[i]=inv(fac[i],MOD);
	}
}
int main(){
	predo();
	while(scanf("%d",&n)!=EOF){
		getchar();
		gets(str);
		//cout<<str<<endl;
		//scanf("%s",str);
		if(n&1){ puts("0"); continue; }
		gao();
	}
}
