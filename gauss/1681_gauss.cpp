/*
   ���⣺
   n*n�ķ�ת���⣬������ʼ״̬��ÿ�β�������λ������һ��ת������С�Ĳ���������
   (1<=n<=15)
   ��⣺
   ��˹��Ԫ��ö�����ɱ�Ԫ
 */
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
const int N=16*16,
	  INF=0x3f3f3f3f;
int n;
char _map[16][16];

//��˹��Ԫ����ģ��
//const int N=105;
int a[N][N];	//�������
int x[N];	//�⼯
int free_x[N];	//�����洢���ɱ�Ԫ
int free_num;	//���ɱ�Ԫ�ĸ���
//��equ�����̣�var����Ԫ�������������Ϊequ,�ֱ�Ϊ0��equ-1,����Ϊvar+1,�ֱ�Ϊ0��var��ʹ��ǰ��ʼ��a��x
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
			free_x[free_num++] = col;
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
	if(x>=0 && x<n && y>=0 && y<n)
		return true;
	return false;
}
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};
void build(int x,int y){
	int u=x*n+y,v;
	a[u][u]=1;
	if(_map[x][y]=='y')
		a[u][n*n]=0;
	else
		a[u][n*n]=1;
	for(int i=0;i<4;++i){
		int tmpx=x+dx[i],
			tmpy=y+dy[i];
		if(in(tmpx,tmpy)){
			v=tmpx*n+tmpy;
			a[v][u]=1;
		}
	}
}
void gao(){
	int fn=gauss(n*n,n*n);	//���ɱ�Ԫ����
	if(fn==-1){
		puts("inf");
		return ;
	}
	else if(fn==0){
		int ans=0;
		for(int i=0;i<n*n;++i)
			ans+=x[i];
		printf("%d\n",ans);
		return ;
	}
	else{
		//ö�����ɱ�Ԫ
		int ans = INF,
			tot = (1<<fn),
			var=n*n;
		for(int i = 0;i < tot;i++){
			int cnt = 0;
			for(int j = 0;j < fn;j++){
				if(i&(1<<j)){
					x[free_x[j]] = 1;
					cnt++;
				}
				else x[free_x[j]] = 0;
			}
			for(int j = var-fn-1;j >= 0;j--){
				int idx;
				for(idx = j;idx < var;idx++)
					if(a[j][idx])
						break;
				x[idx] = a[j][var];
				for(int l = idx+1;l < var;l++)
					if(a[j][l])
						x[idx] ^= x[l];
				cnt += x[idx];
			}
			ans = min(ans,cnt);
		}
		printf("%d\n",ans);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%s",_map[i]);
		memset(a,0,sizeof(a));
		memset(x,0,sizeof(x));
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				build(i,j);
		gao();
	}
	return 0;
}
