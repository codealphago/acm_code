/*poj 1808
  ���⣺
  �ж�ƽ��ʣ�࣬���ж�(x^2)%p=a�Ƿ��н⡣
  ���ƣ�
  |a| <= 1e9 && a % p !=0; 2 < p < 1e9 && pΪ��������
  ˼·��
  ��ŷ��׼��������õ·���(�����ж�ƽ��ʣ��)
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
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
//(x^2)%n=a ��ƽ��ʣ�࣬n������������
//ע�⣺���aΪ���������⣬�Ƿ�Ҫ��Ϊa=(a%n+n)%n
int modsqr(int a,int n){
	int b,k,i,x;
	if(n==2) return a%n;
	if(a_b_MOD_c(a,(n-1)/2,n)==1){
		if(n%4==3)
			x=a_b_MOD_c(a,(n+1)/4,n);
		else{
			for(b=1;a_b_MOD_c(b,(n-1)/2,n)==1;b++){
				i=(n-1)/2;
				k=0;
			}
			do{
				i/=2;
				k/=2;
				if((a_b_MOD_c(a,i,n)*a_b_MOD_c(b,k,n)+1)%n==0)
					k+=(n-1)/2;
			}
			while(i%2==0);
			x=(a_b_MOD_c(a,(i+1)/2,n)*a_b_MOD_c(b,k/2,n))%n;
		}
		if(x*2>n)
			x=n-x;
		return x;
	}
	return -1;
}
//��ŷ��׼��������õ·���(�����ж�ƽ��ʣ��)
//��ʾΪ(a|p) aΪ������pΪ������(����m=2���������õ·���)�������������
//1. (a|p)=0, if(a%p==0)
//2. (a|p)=1, if(a%p!=0 && (x^2)%p=a ��������)
//3. (a|p)=-1,if((x^2)%p=a ��������)
//ע�⣺���aΪ���������⣬�Ƿ�Ҫ��Ϊa=(a%p+p)%p
int lrd(LL a,LL p){
	LL ret=a_b_MOD_c(a,(p-1)>>1,p);
	if(ret==1)
		return 1;
	return -1;
}
int main(){
	int T,cas=0;
	int a,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&n);
		a=(a+n)%n;	//�Ժ�ע�����������ʱ��Ҫע�����ǲ��Ǹ���
		
		//��ƽ��ʣ��
		//cout<<modsqr(a,n)<<endl;
		printf("Scenario #%d:\n%d\n\n",++cas,lrd(a,n));
	}
	return 0;
}
