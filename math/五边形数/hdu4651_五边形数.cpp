/*hdu4651
  题意：
  普通的整数拆分
  限制：
  1 <= n <= 1e5
  思路：
  五边形数定理
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=100005;
const int MOD=1000000007;
LL dp[N],fi[N];
LL five(LL x){ return (3*x*x-x)/2; }
//五边形数
void wbxs(){
    dp[0]=1;
    int t=1000; //其实可以等于sqrt(N)
    for(int i=-t;i<=t;++i)
        fi[i+t]=five(i);	//Q
    for(int i=1;i<=100000;++i){
        int flag=1;
        for(int j=1;;++j){
            LL a=fi[j+t],b=fi[-j+t];
            if(a>i && b>i) break;
            if(a<=i) dp[i]=(dp[i]+dp[i-a]*flag+MOD)%MOD;	//p
            if(b<=i) dp[i]=(dp[i]+dp[i-b]*flag+MOD)%MOD;
            flag*=-1;
        }
    }
}
int main(){
    wbxs();
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%I64d\n",dp[n]);
    }
    return 0;
}
