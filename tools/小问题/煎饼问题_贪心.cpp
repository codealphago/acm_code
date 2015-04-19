/*zoj 3778 Talented Chef
  ���⣺
  ��n�������������ÿ��������Ҫ��ʱ��t1,t2,...,tn��������m����(Ҳ����˵����ͬʱ��m����)����������б�������Ҫ����ʱ�䡣
  ���ƣ�
  1 <= n,m,ti <= 40000
  ˼·��
  ̰��
  ans=max(ceil(sigma(1~n,ti)/m),max(ti))
 */
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		int a;
		int sum=0,_max=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			sum+=a;
			_max=max(_max,a);
		}
		int ans=max((sum+m-1)/m,_max);
		printf("%d\n",ans);
	}
	return 0;
}
