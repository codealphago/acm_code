# include <iostream>
using namespace std;

# define N 6

void listInput(int a[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
    	cin>>a[i];
}

int calNum(int a[],int n)
{
	int b1=0;//b1Ϊ2*2�Ŀ���λ
	int b0=0;//b0Ϊ1*1�Ŀ���λ

	int num=0;
	num+=a[5]+a[4]+a[3]+(a[2]+3)/4;//4*4,5*5,6*6,3*3����Ҫ������
	int x=a[2]%4;

	if(x==0) b1=a[3]*5;
	if(x==1) b1=a[3]*5+a[2]*5; 
	if(x==2) b1=a[3]*5+a[2]*3;
	if(x==3) b1=a[3]*5+a[2];

	if(b1<a[1])  //����Ҫ������
    	num+=(a[1]-b1+8)/9;
    	//b0=a[4]*11+a[3]*0+a[2]*5+(36-(a[1]-b1)%8*4);

		b0=36*num-(a[5]*36+a[4]*25+a[3]*16+a[2]*9+a[1]*4);

	if(b0<a[0])
			num+=(a[0]-b0+35)/36;

	return num;
}

int main()
{
	int a[6];
	while(1)
	{
		listInput(a,N);
		if(!a[0]&&!a[1]&&!a[2]&&!a[3]&&!a[4]&&!a[5])
			break; 
		cout<<calNum(a,N)<<endl;
	}
	return 0;
}
