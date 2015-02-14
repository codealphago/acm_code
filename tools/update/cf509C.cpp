/*cf 509C Sums of Digits
  ���⣺
  ����n�����ָ�λ�ļӺ�bi����һ���ϸ���������С�Ҫ�����һ��������С��
  �磺
  3 2 1 -> 3 11 100
  ���ƣ�
  1 <= n <= 300; 1 <= bi <=300
  ˼·��
  ̰�ģ�Ҫ�����һ��������С��ֻҪ��֤һ·���������ֶ�����С���С�
  ��d=b[i]-b[i-1],
  ���d>0��������λ���𣬾����ѵ�λ�9
  ���d<=0,���ȴӵ�λ��ʼ��λ��ʹ��d>0��Ȼ��Ϳ���ת��Ϊ��һ������ˡ�
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int N=505;
int a[N];
int res[N],tot;
void init(){
	tot=0;
}
int trans(int d){
	int pos=0;
	while(res[pos]==9 || d<=0){
		d+=res[pos];
		res[pos]=0;
		++pos;
	}
	++res[pos];
	--d;
	tot=max(tot,pos+1);
	return d;
}
void gao(int d){
	if(d<=0) d=trans(d);
	int pos=0;
	while(d>0){
		if(9-res[pos]<=d){
			d-=9-res[pos];
			res[pos]=9;
		}
		else{
			res[pos]+=d;
			d=0;
		}
		++pos;
	}
	tot=max(tot,pos);
	for(int i=tot-1;i>=0;--i)
		printf("%d",res[i]);
	puts("");
}
int main(){
	int n;
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		gao(a[i]-a[i-1]);
	return 0;
}
