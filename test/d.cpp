#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
	//��������ͨ���
	double a = 123.123456789;
	cout<<a<<endl;	//���Ĭ�ϱ���6λ��Ч����
	printf("%lf\n", a);	//���Ĭ�ϱ���С�����6λ

	//����������С�����3λ�����������
	cout<<fixed<<setprecision(3)<<a<<endl; //������Ļ�Ҫ#include<iomanip>
	printf("%.3lf\n", a);

	return 0;
}
