/*
   Լɪ�����⣬��n����վ��һȦ�����α��0��n�����Ϊm%n���˳��֣�Ȼ��ʣ�µ�n-1�������±�ţ���ԭ����m������Ǹ��˱��Ϊ0��ʣ�µ����ε�������Ŵ�1��n-1���ٴ��ñ��Ϊm%(n-1)���˳��֡������ظ��˹��̣�ֱ��ֻʣһ����Ϊֹ��
*/
#include<iostream>
#include<cstdio>
using namespace std;
int k,m,n;
int Joseph(int num){
	int tmp;
	if(num==1) return 0;
	tmp=(Joseph(num-1)+k)%num;
	cout<<num<<' '<<tmp<<endl;
	return tmp;
}
int main(){
	while(scanf("%d%d%d",&n,&k,&m) && (n || k || m))
	  printf("%d\n",(Joseph(n-1)+m)%n+1);
	return 0;
}

