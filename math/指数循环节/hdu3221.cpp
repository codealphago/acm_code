/*hdu3221
  ���⣺
  Function Find(int n,function func)
	If n=1
		For i=1 to a do func()
	Elseif n=2
		For i=1 to b do func()
	Else Find(n-1,Find(n-2,func))
  Function Main
	Find(n,funny)
  ����n,a,b,p����funny��ִ�ж��ٴΣ����ģp��
  ���ƣ�1 <= n <= 1e9��1 <= p <= 1e6��0 <= a,b < 1e6
  ˼·���ҹ��ɣ��ݵ�ѭ����
  ��f(n)Ϊfunnyִ�ж��ٴ�
  �ᷢ�� f(n)=f(n-1)*f(n-2)
  Ȼ��:
  f(1)=(a^1)*(b^0)
  f(2)=(a^0)*(b^1)
  Ȼ��
  �ᷢ��a��b��ָ����쳲�������һ�������������þ�������ݽ��ָ������
  ��ָ��̫������Ҫ�õ��ݵ�ѭ����
  ��ʽx >= Phi(C), A^x = A ^ (x%Phi(C) + Phi(C)) (mod C)
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=1000005;
int phi[N];
LL a,b,p,n;
void get_phi(){
    for(int i=0;i<N;++i) phi[i]=i;
    for(int i=2;i<N;++i) if(phi[i]==i)
        for(int j=i;j<N;j+=i)
            phi[j]=phi[j]/i*(i-1);
}
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
struct Matrix
{
    LL a[5][5];
    int n,m;
    Matrix(int _n=0,int _m=0,LL val=0)
    {
        n=_n; m=_m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i][j]=(i==j?val:0);
    }
    void print()
    {
        for(int i=0;i<n;i++,puts(""))
            for(int j=0;j<m;j++)
                cout<<a[i][j]<<' ';
        puts("");
    }
    Matrix operator *(Matrix tmp)
    {
        Matrix ret(n,tmp.m);
        for(int i=0;i<n;i++)
            for(int j=0;j<tmp.m;j++)
                for(int k=0;k<m;k++){
                    ret.a[i][j]+=a[i][k]*tmp.a[k][j];
                    if(ret.a[i][j]>phi[p]) ret.a[i][j]=ret.a[i][j]%phi[p]+phi[p];
                }
        return ret;
    }
    Matrix operator ^(LL b)
    {
        Matrix ret(n,m,1),base=(*this);
        while(b)
        {
            if(b&1) ret=ret*base;
            b>>=1;
            base=base*base;
        }
        return ret;
    }
};
LL cal(LL a,Matrix m1,Matrix m2){
	m2=m1*m2;
    return a_b_MOD_c(a,m2.a[1][0],p);
}
int main(){
    get_phi();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas){
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&p,&n);
        Matrix m1=Matrix(2,2),m2=Matrix(2,1);
        m1.a[0][0]=m1.a[0][1]=m1.a[1][0]=1;
		m1=m1^(n-1);
        m2.a[0][0]=0;
        m2.a[1][0]=1;
        LL ans=cal(a,m1,m2);
        m2.a[0][0]=1;
        m2.a[1][0]=0;
        ans=ans*cal(b,m1,m2);
        ans%=p;
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}
