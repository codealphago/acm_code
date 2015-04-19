/*hdu 5203 Rikka with wood sticks
  ���⣺
  ��̫��һ������Ϊn��ľ�������ľ������n������Ϊ1��Сľ��ƴ�Ӷ��ɣ���Ȼ����ʱ����õľ��ˣ�һЩСľ���Ѿ����ι��ˣ�������̫�������������ľ���ֳ����������ȵ�4�Σ�������3��Ҫû�в��ι̵�Сľ������̫ϣ����3��ľ���ĳ��ȺͿ������ͬʱ����ϣ����������̫Ҫ����������������ľ����ƴ��һ�������Σ����������������ж����ֿ��еķָ���أ�
  ���ƣ�
  1 <= n <= 1e6; 1 <= m <= 1e3
  ˼·��
  ʵ��������ữΪ��
  1. ��������Ϊl1,l2��ľ����������һ���س�2�Σ�������������εķ�������
  2. ����Ϊl��ľ�����س�3�Σ�������������εķ�������
  �����ɲ���ʽ�⡣
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
//�󳤶�Ϊl��ľ�����س�3�Σ�������������εķ�������
LL gao(int l){
	LL ret=0;
	for(int i=1;2*i<l;++i){
		ret+=(l-1)/2-(l/2-i);
	}
	return ret;
}

bool ok(int a,int b,int c){
	if(a>b) swap(a,b);
	if(b>c) swap(b,c);
	if(a>b) swap(a,b);
	if(a+b>c && b-a<c) return true;
	return false;
}
int main(){
	int n,m;
	int _max,_min;
	while(scanf("%d%d",&n,&m)!=EOF){
		_max=-1;
		_min=n+1;
		int a;
		for(int i=0;i<m;++i){
			scanf("%d",&a);
			_max=max(_max,a);
			_min=min(_min,a);
		}
		int len1=_min-1;
		int len2=n-_max;
		LL ans=0;
		if(len1>len2) swap(len1,len2);
		if(len1==len2){
			puts("0");
			continue;
		}
		else if(len1){
			for(int i=1;i<len2;++i){
				int a=i,b=len2-i;
				if(ok(len1,a,b)) ++ans;
			}
		}
		else{
			ans=gao(len2);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
