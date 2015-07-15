/*zoj 3822 Domination
  ���⣺
  ����һ��N*M�����̣�ÿ����ѡһ��λ�÷���һö���ӣ�ֱ��ÿ��ÿ���϶�������һö���ӣ��ʷ������Ӹ�����������
  ���ƣ�
  1 <= n,m <= 50
  ˼·��
  ����dp
  dp[i][j][k]��ʾ����k�����ӣ�ռ��i��j�С�
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=55;
double dp[N][N][N*N];
void gao(int n,int m){
	memset(dp,0,sizeof(dp));

	dp[0][0][0]=1;
	//for(int i=0;i<=n;++i)
	//	dp[i][0][0]=1;
	//for(int j=0;j<=m;++j)
	//	dp[0][j][0]=1;
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int k=1;k<=i*j;++k){
				dp[i][j][k]=dp[i-1][j][k-1]*((double)(n-i+1)*j)/((double)n*m-k+1) +
							dp[i][j-1][k-1]*((double)i*(m-j+1))/((double)n*m-k+1) +
							dp[i-1][j-1][k-1]*((double)(n-i+1)*(m-j+1))/((double)n*m-k+1);
							
				if(i!=n || j!=m)
					dp[i][j][k]+=dp[i][j][k-1]*((double)i*j-k+1)/((double)n*m-k+1);
				//if(i==1 && j==2 && k==2) cout<<'!'<<((double)n*(m-j+1))<<' '<<((double)n*m-k+1)<<endl;
				//cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
			}
		}
	}
	double ans=0;
	for(int i=0;i<=n*m;++i){
		ans+=dp[n][m][i]*i;
	}
	printf("%.8f\n",ans);
}
int main(){
	int T;
	int n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		gao(n,m);
	}
	return 0;
}
