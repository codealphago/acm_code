/*poj 3761
  ���⣬��n����ͬԪ�ص�����ǡ�þ���k��ð��������������ԭ�����ж������������

  �ⷨ��
  ���ȣ�����һ�� f(x)��ʾ��������λ��Ԫ��x�����Ҵ���x�ĸ�������ô��
  1. f(x) = 0 (x = 1,2,...,n)�����������״̬
  2. f(x) <= n - x;
  3. ����ÿ��ð��������f(x) != 0����f(x)--;

  �ȽϺ�����Ǿ���������k��ð�ݵ�������g(k)
  ��֪��k��ð�ݴﵽ����ĳ�Ҫ������ max f(x) == k
  ���� n - x <= k;�� x >= n -  kʱ��x���Է������������λ�á�
  ��Ԫ�ط�Ϊ[1,n-k],[n-k+1,n],��n��λ���зź���ǰn-k�����󣬺�k�����ķ���Ϊk!
  ����ǰn-k ��������������
  ����Ҫ��f(1) <= k,��1��k+1��λ�ÿɷţ��ź�1������1��λ�ö�f(2)��Ӱ�죬
  2ͬ����k+1��λ�ÿɷ�...
  g(k) = (k+1)^(n-k) * k!

  ���ս����Ϊ g(k) - g(k-1) = k! * [(k + 1)^(n - k) - k^(n - k)];
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int MOD=20100713;
const int N=1e6+5;
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
LL fac[N];
void init(){
	fac[0]=1;
	for(int i=1;i<N;++i)
		fac[i]=fac[i-1]*i%MOD;
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		printf("%I64d\n",fac[k]*(a_b_MOD_c(k+1,n-k,MOD)-a_b_MOD_c(k,n-k,MOD)+MOD)%MOD);
	}
	return 0;
}
