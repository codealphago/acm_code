#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(a>b)
			swap(a,b);
		int tmp = floor((b-a) * (1 + sqrt(5.0)) / 2.0); //�ƽ�ָ�
		if(tmp == a) puts("0");	//�������
		else puts("1");
	}
	return 0;
}
