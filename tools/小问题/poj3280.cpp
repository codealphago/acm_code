/*poj 3280
  ���⣺
  ����n,m, ��ʾ����Ϊm���ַ�����ֻ��n����ĸ, �����ַ���, �ٸ���ÿ����ĸ���Ӻ�ɾ���Ĵ���c1,c2, �������ַ�����ɻ��Ĵ�����С���ۡ�
  ���ƣ�
  1 <= n <= 26; 1 <= m <= 2000; 0 <= c1,c2 <= 10000
  ˼·��
  if(str[l]!=str[r]) dp[l][r]=min(dp[l+1][r]+cost[l],dp[l][r-1]+cost[r])
  else dp[l][r]=dp[l+1][r-1]
  �ü��仯�ȽϺ�д��
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2005;
const int INF=0x3f3f3f3f;
char str[N];
int c[30];
int dp[N][N];
int gao(int l,int r){
	if(dp[l][r]!=INF) return dp[l][r];
	if(l==r) return dp[l][r]=0;
	if(l+1==r && str[l]==str[r]) return dp[l][r]=0; 
	if(str[l]!=str[r]) dp[l][r]=min(gao(l+1,r)+c[str[l]-'a'],gao(l,r-1)+c[str[r]-'a']);
	else dp[l][r]=gao(l+1,r-1);
	return dp[l][r];
}
int main(){
	int n,m;
	memset(dp,0x3f,sizeof(dp));
	scanf("%d%d",&n,&m);
	scanf("%s",str);
	for(int i=0;i<n;++i){
		char ch[3];
		int a,b;
		scanf("%s%d%d",ch,&a,&b);
		c[ch[0]-'a']=min(a,b);
	}
	printf("%d\n",gao(0,m-1));
	return 0;
}
