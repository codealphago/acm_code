//Memory Time 
//1052K  47MS 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
	int N;   //��Ʒ���������������	
	int cash;  //��������������ȡ��
	int i,j;
	while(cin>>cash>>N){
		/*Input*/
		int* n=new int[N+1];  //n[i]��i����Ʒ�ĸ�������i������������
		int* w=new int[N+1];  //w[i]��i����Ʒ�ļ�ֵ����i�����ļ�ֵ��
		int* dp=new int[cash+1];  //dp[j]��¼���� ��ǰ��ӽ�״̬j��<=j��ֵ��dpֵ���ۻ�
		int* count=new int[cash+1];//������������ĳ����Ʒ������ѡȡ����
		for(i=1;i<=N;i++){
			cin>>n[i]>>w[i];
		}

		/*Initial*/
		memset(dp,0,4*(cash+1));  //����dp������Ƕ�̬�ڴ棬��sizeof���㳤�Ȼ����
		//����Ҫ�� ���ʹ�С*����,����Ϊ int*(cash+1) , int��СΪ4
		
		/*DP*/
		for(i=1;i<=N;i++){
			memset(count,0,4*(cash+1));  //ÿ����һ��������������
			for(j=w[i];j<=cash;j++)      //���ڵ�i�ֻ��ң������d[i]~cash����һ��״̬�����ܷ���
			  if(dp[j]<dp[j-w[i]]+w[i] && count[j-w[i]]<n[i]){	//count[j-c[i]]<n[i],ȡĳ�����ǰ�����뱣֤��β���֮ǰ��ȡ�������Ĵ���С��n[i]
				  dp[j] = dp[j-w[i]]+w[i];	//ѡȡ��i����Ʒ�󣬱�������������ȡ����������c[i]
				  count[j]=count[j-w[i]]+1;	//���ڵ�ǰ״̬j����i��������count[j]��
			  }
		}

		/*Output*/
		cout<<dp[cash]<<endl;
		
		/*Release Space*/
		delete n;
		delete w;
		delete dp;
		delete count;
	}
	return 0;
}

