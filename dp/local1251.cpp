/*njoj 1251 zlly����һ�Ű�����
  ���⣺
  zlly����һ�Ű����������ر�ϲ�����ǹ�����������ͷ���������ǹ���ÿ���ǹ��и���ζֵ��ÿ���ǹ������������Ȼ��¦ͯЬҲ�ǳ�ϲ�����ǹ������Ŀ�ζ�ر�㷺����ϲ�����ָ����Ŀ�ζֵ����Ҫ��zlly�����еĿ�ζֵƴ���µĿ�ζֵ�����ڣ�¦ͯЬ��֪�������ܳԵ��Ŀ�ζֵ����Ƕ��٣����ܰ�����æ��
  �ٸ����ӣ�����zlly��ͷ��3,6,10�����ǹ�����ƴ������ζֵΪ1��2��4��5��7��17���ǹ������Խ������17��
  ���⣬�ǹ�������<=10��ÿ���ǹ��Ŀ�ζֵ<=265�����Ա�֤���Ľ��������2,000,000,000�����������ƴ�������ֵ�����ڣ����0��
  ˼·��
  ��ʵ2*1e9����ģ�
  gcd(a1,...,an)!=1ʱ���޽⣬
  gcd(a1,...,an)==1ʱ���н⣬����Ͻ�Ϊmax(ai*aj)������֤��
  ���Ա������ɡ�
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=15;
const int MAX_N=1000005;
int a[N];
bool arr[MAX_N];
void gao(int n){
	memset(arr,0,sizeof(arr));
	int gcd=a[0];
	for(int i=1;i<n;++i){
		gcd=__gcd(gcd,a[i]);
	}
	if(gcd!=1){
		puts("0");
		return ;
	}
	int _min=300;
	for(int i=0;i<n;++i)
		_min=min(a[i],_min);
	int cnt=0;
	int ans;
	arr[0]=1;
	for(int i=1;i<MAX_N;++i){
		for(int j=0;j<n;++j){
			if(a[j]>i) continue;
			if(arr[i-a[j]]){
				arr[i]=1;
				break;
			}
		}
		if(arr[i]) ++cnt;
		else cnt=0;
		if(cnt==_min){
			ans=i-_min;
			break;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		gao(n);
	}
	return 0;
}
