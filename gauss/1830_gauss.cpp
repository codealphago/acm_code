/*
   ���⣺
   n�����أ�����n�����ز���ǰ�Ͳ������״̬���ٸ�������ϵ�Ŀ��أ�ÿ��������i j����ʾ���������i�����أ���j�����ص�״̬Ҳ��仯����ӳ�״̬��ĩ״̬�ж����ַ�����
   (0<n<29)
   ��⣺
   ��˹��Ԫ����
   */
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
const int N=35;
int st[N],en[N];

//const int N=105;
int a[N][N];	//�������
int x[N];	//�⼯
int free_x[N];	//����Ƿ������ɱ�Ԫ
int free_num;
//��equ�����̣�var����Ԫ�������������Ϊequ,�ֱ�Ϊ0��equ-1,����Ϊvar+1,�ֱ�Ϊ0��var��ʹ��ǰ��ʼ��a
//����ֵΪ-1��ʾ�޽⣬Ϊ0��Ψһ�⣬���򷵻����ɱ�Ԫ����
int gauss(int equ,int var){
	int max_r, col, k;
	free_num = 0;
	for(k = 0, col = 0; k < equ && col < var; k++, col++){
		max_r = k;
		for(int i = k+1 ; i < equ; i++)
			if(abs(a[i][col]) > abs(a[max_r][col]))
				max_r = i;
		if(a[max_r][col] == 0){
			k--;
			free_x[free_num++] = col; //���ɱ�Ԫ
			continue;
		}
		if(max_r != k){
			for(int j = col; j < var+1; j++)
				swap(a[k][j],a[max_r][j]);
		}
		for(int i = k+1; i < equ;i++)
			if(a[i][col] != 0)
				for(int j = col; j < var+1;j++)
					a[i][j] ^= a[k][j];
	}
	for(int i = k;i < equ;i++)
		if(a[i][col] != 0)
			return -1;
	if(k < var)return var-k;
	for(int i = var-1; i >= 0;i--){
		x[i] = a[i][var];
		for(int j = i+1; j < var;j++)
			x[i] ^= (a[i][j] && x[j]);
	}
	return 0;
}

int main(){
	int n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&st[i]);
		for(int i=0;i<n;++i)
			scanf("%d",&en[i]);
		memset(a,0,sizeof(a));
		int u,v;
		while(scanf("%d%d",&u,&v) && (u || v))
			a[v-1][u-1]=1; //�Ŀ���
		for(int i=0;i<n;++i)
			a[i][i]=1;
		for(int i=0;i<n;++i)
			a[i][n]=st[i]^en[i];
		int ans=gauss(n,n);
		if(ans==-1)
			puts("Oh,it's impossible~!!");
		else
			printf("%d\n",1<<ans);
	}
	return 0;
}
