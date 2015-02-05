/*
   ���⣺
   ����ÿ���ӽ��ÿһ����ĸ��ʣ���ÿ���Ӷ������ҹھ��������ٹ�n����ĸ��ʡ�
   m��ʾm���⣬t��ʾt���ӡ�
   (0<m<=30,1<t<=1000,0<n<=m)
   ��⣺
   dp[i][j]��ʾǰi�����j���ĸ��ʣ����У�
   dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i])
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;
double p[35],dp[1005][35][35];
int main(){
	int m,t,n;
	double ans;
	while(scanf("%d%d%d",&m,&t,&n) && (m || t || n)){
		for(int i=0;i<t;++i){
			for(int j=1;j<=m;++j){
				scanf("%lf",&p[j]);
			}
			dp[i][1][0]=1-p[1];
			dp[i][1][1]=p[1];
			for(int j=2;j<=m;++j){
				dp[i][j][0]=dp[i][j-1][0]*(1-p[j]);
				for(int k=1;k<=j;++k)
					dp[i][j][k]=dp[i][j-1][k-1]*p[j]+dp[i][j-1][k]*(1-p[j]);
			}
		}
		ans=1;
		for(int i=0;i<t;++i)
			ans*=(1-dp[i][m][0]);
		double tmp1,tmp2=1;
		for(int i=0;i<t;++i){
			tmp1=0;
			for(int j=1;j<n;++j){
				tmp1+=dp[i][m][j];
			}
			tmp2*=tmp1;
		}
		cout<<fixed<<setprecision(3)<<ans-tmp2<<endl;
		/*for(int i=0;i<t;++i){
			tmp1=0;
			for(int j=1;j<n;++j){
				tmp1+=dp[i][m][j];
			}
			tmp2*=tmp1/(1-dp[i][m][0]);
		}
		cout<<fixed<<setprecision(3)<<ans*(1-tmp2)<<endl;*/
		/*��д���������ݣ�
		  2 2 2
		  0.9 0.9
		  0 0
		  nan*/
	}
	return 0;
}

