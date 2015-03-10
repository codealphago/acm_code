/*hdu 5185
  ��Ŀ��
  x[1]+x[2]+x[3]+...+x[n]=n, ���� 
  0 <= x[i] <= n && 1 <= i <= n
  x[i] <= x[i+1] <= x[i]+1 && 1 <= i <= n-1
  ����һ��������n,Gorwin��Ҫ֪���ж���xi���������������ʽ�����ڽ���Ƚϴ�����𰸶�mȡ��Ľ�����С�
  ���ƣ�
  T�����ݣ�1 <= T <=20
  1 <= n <= 50000
  1 <= m <= 1e9
  ˼·��
  ���Ʊ�����dp��ֻ����΢��һ�¶��ѡ�
  dp[i][j] ��ʾװ������Ϊi�ı��������������������ƷΪj�ķ�����
  dp[i][j]=dp[i-j][j-1]+dp[i-j][j]

  ��Ҫע���һ����������Ŀ���ƣ���������Ʒ�����Ϊx�����У�
  (x+1)*x/2=n������x���ֵС��sqrt(2*n)��
  ����ÿ������ʱ�ո��Ӷȶ�ΪO(50000*320)��
 */
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL __int64
int MOD;
const int N=50005;
int dp[N][320];
void gao(int n,int m){
	MOD=m;
	int lim=sqrt(2*n);
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=min(i,lim);++j){
			dp[i][j]=((LL)dp[i-j][j-1]+dp[i-j][j])%MOD;
		}
	}
	//for(int i=0;i<=n;++i){
	//	for(int j=1;j<=lim;++j)
	//		cout<<dp[i][j]<<' ';
	//	cout<<endl;
	//}
	LL ans=0;
	for(int i=1;i<=lim;++i){
		ans=(ans+dp[n][i])%MOD;
	}
	printf("%I64d\n",ans);
}
int main(){
	int T,cas=0;
	int n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		printf("Case #%d: ",++cas);
		gao(n,m);
	}
	return 0;
}
