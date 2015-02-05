/*poj 1284
  ���⣺
  ����һ����n,��ԭ����Ŀ��
  ���ƣ�
  3 <= n < 65536; nΪ��������
  ˼·��
  ��Ϊn������������ģn��ԭ����=phi(phi(n))=phi(n-1)��
  phi(i) ����Ԥ���������
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int pri[N],pcnt;
int phi[N];
void getphi(){
	phi[1]=1;
	for(int i=2;i<N;++i){
		if(!phi[i]){ pri[pcnt++]=i; phi[i]=i-1; }
		for(int j=0;pri[j]*i<N && j<pcnt;++j){
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			else phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
}
int main(){
	int n;
	getphi();
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",phi[n-1]);
	return 0;
}
