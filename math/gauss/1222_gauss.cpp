/*
   ���⣺
   ����һ��5*6��01���󣬸�����״̬���Ͳ�����ÿ�β�����Ը����������ܵ������з�ת����һ�ַ�ת������
   ��⣺
   ��˹��Ԫ��
 */
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
const int N=35;
int mat[10][10];

//��˹��Ԫ����ģ��
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

bool in(int x,int y){
	if(x>=0 && x<5 && y>=0 && y<6)
		return true;
	return false;
}
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};
void build(int x,int y){
	int u=x*6+y,v;
	a[u][u]=1;
	a[u][30]=mat[x][y]^0;
	for(int i=0;i<4;++i){
		int tmpx=x+dx[i],
			tmpy=y+dy[i];
		if(in(tmpx,tmpy)){
			v=tmpx*6+tmpy;
			a[v][u]=1;
		}
	}
}
int main(){
	int cas=0,T;
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		for(int i=0;i<5;++i){
			for(int j=0;j<6;++j){
				scanf("%d",&mat[i][j]);
				build(i,j);
			}
		}
		int ans=gauss(30,30);
		//cout<<ans<<endl;
		printf("PUZZLE #%d\n",++cas);
		for(int i=0;i<30;++i){
			printf("%d%c",x[i],(i+1)%6!=0?' ':'\n');
		}
	}
	return 0;
}
