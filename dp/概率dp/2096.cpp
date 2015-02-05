/*
   ���⣺
   һ�������s����ϵͳ�������n��bug�� ĳ��һ�췢��һ��bug�����bug����ĳ��bug��������ĳ����ϵͳ�С����ҵ����е�n��bug����ÿ����ϵͳ���ҵ�bug��������Ҫ����������������Ҫע����ǣ�bug�������������ģ����Է���һ��bug��������ĳ����ϵͳ�ĸ�����1/s������ĳ�����͵ĸ�����1/n��
   ��⣺
   dp[i][j]=dp[i][j]*i/n*j/m + dp[i+1][j]*(n-i)/n*j/m + dp[i][j+1]*i/n*(m-j)/m+dp[i+1][j+1]*(n-i)/n*(m-j)/m
   ���򼴿ɡ�
 */
#include<cstdio>
#include<iostream>
#include<iomanip>
using namespace std;
const int N=1005;
double dp[N][N];
int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	dp[n][s]=0;
	for(int i=n;i>=0;--i){
		for(int j=s;j>=0;--j){
			if(i!=n || j!=s)
				dp[i][j]=(dp[i+1][j]*(n-i)*j+dp[i][j+1]*i*(s-j)+dp[i+1][j+1]*(n-i)*(s-j)+n*s)/(n*s-i*j);
		}
	}
	cout<<fixed<<setprecision(4)<<dp[0][0]<<endl;
	return 0;
}
