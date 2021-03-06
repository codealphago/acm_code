#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=1e5+5;
LL f[N],ny[N];
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}
void predo(int n,int MOD){
	f[0]=1;
	ny[0]=inv(f[0],MOD);
	for(int i=1;i<=n;++i){
		f[i]=f[i-1]*i%MOD;
		ny[i]=inv(f[i],MOD);
	}
}
LL C(int n,int k,int MOD){
	if(k>n) return 0;
	return f[n]*ny[k]%MOD*ny[n-k]%MOD;
}
LL lucas(int n,int k,int MOD){
	if(n<MOD && k<MOD) return C(n,k,MOD);
	return lucas(n/MOD,k/MOD,MOD)*C(n%MOD,k%MOD,MOD)%MOD;
}
LL cal(int l,int r,int k,int MOD){
	if(l>r) return 0;
	return (lucas(r+1,k+1,MOD)-lucas(l,k+1,MOD)+MOD)%MOD;
}
void gao(int x1,int y1,int x2,int y2,int MOD){
	LL ans=0;
	for(int i=y1;i<=y2;++i){
		int l=max(i,x1);
		int r=x2;
		ans=(ans+cal(l,r,i,MOD))%MOD;
	}
	printf("%I64d\n",ans);
}
int main(){
	int x1,y1,x2,y2,p;
	while(scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&p)!=EOF){
		predo(min(max(x2,y2)+2,p),p);
		gao(x1,y1,x2,y2,p);
	}
	return 0;
}
