/*poj 2287
  ���⣺
  ������� 
  ���3ƥ����1000ƥ��������Ȼ�����������ŵ��ӵ�˳���������ɿ��԰�����˳��ѡ���������������Ӯһ�֣���ɿ��Եõ�200�����ӣ���һ�֣���ɾ�Ҫ���200�����ӣ�ƽ�ֵĻ����䲻Ӯ�� 
  ������������Ӯ��������?
  ˼·��
  ̰�ģ�
  �����ǰ��õ������ʤ������õ�����ô������ƥ���һ����
  �����ǰ��������ʤ������������ô������ƥ���һ����
  ����������������������㣬��ô�õ�ǰ�������������õ����һ����
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
int a[N],b[N];
void gao(int n){
	int p1=0,p2=0;
	int q1=n-1,q2=n-1;
	int ans=0;
	while(p1<=q1){
		if(a[p1]>b[p2]){
			++p1;
			++p2;
			++ans;
		}
		else if(a[q1]>b[q2]){
			--q1;
			--q2;
			++ans;
		}
		else{
			if(a[p1]!=b[q2])
				--ans;
			++p1;
			--q2;
		}
	}
	printf("%d\n",ans*200);
}
int main(){
	int n;
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		for(int i=0;i<n;++i)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		gao(n);
	}
	return 0;
}
