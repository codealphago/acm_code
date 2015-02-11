/*poj 2689
  ���⣺
  ����(l,r), �������[l,r]֮�����С���Ͳ��������ڵ������ԡ�
  ���ƣ�
  1 <= l < r <= 2147483647; l,r֮�����1e6
  ˼·��
  ɸ��������2^32 ֻ��Ҫ 2^16��Χ�ڵ��������Ϳ��԰Ѻ��������ɸ����
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LL __int64
const int N = 1000005;
const int LIM = (1<<16)+5;
bool is_pri[N];
int pri[N],tot;
void predo(){
	tot=0;
	memset(is_pri,1,sizeof(bool)*LIM);
	is_pri[0]=is_pri[1]=0;
	for(int i=2;i<LIM;++i){
		if(is_pri[i]){
			if(LIM/i<i) break;
			for(LL j=i*i;j<LIM;j+=i) is_pri[j]=0;
		}
	}
	for(int i=2;i<=LIM;++i) if(is_pri[i]) pri[tot++]=i;
}
bool ans[N];
bool gao(LL l, LL r){
	memset(ans,1,sizeof(bool)*(r-l+1));
	if(l==1){ ans[0]=0; }
	for(int i=0;i<tot;++i){
		LL t=(LL)pri[i];
		if(r/t<t) break;
		for(LL j=t*max(t,(l+t-1)/t);j<=r;j+=t){
			ans[j-l]=0;
		}
	}
	LL l1, r1, l2, r2;
	int _max = 0, _min = 0x3f3f3f3f;
	int pre = 0;
	while(!ans[pre] && pre <= r - l) ++pre;
	for(int i = pre+1; i <= r - l; ++i){
		if(ans[i]){
			int tmp = i - pre;
			if(tmp > _max){ _max = max(_max, tmp); l1 = pre; r1 = i;}
			if(tmp < _min){ _min = min(_min, tmp); l2 = pre; r2 = i;}
			pre = i;
		}
	}
	if(_max == 0) puts("There are no adjacent primes.");
	else printf("%I64d,%I64d are closest, %I64d,%I64d are most distant.\n", l2 + l, r2 + l, l1 + l, r1 + l);
}
int main(){
	LL l, r;
	predo();
	while(scanf("%I64d%I64d", &l, &r) != EOF)
		gao(l, r);
	return 0;
}
