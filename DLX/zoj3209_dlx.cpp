#include<iostream>
#include<cstdio>
using namespace std;
//����Dance
//ansd����-1��ʾû�и��Ƿ���������������ʾ�и��Ƿ���
//ans[]���渲������Ҫ�Ĳ���
const int maxnode = 500010;
const int MaxM = 1010;
const int MaxN = 510;
struct DLX{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
    int H[MaxN], S[MaxM];
    int ansd, ans[MaxN];	//ansd��ʾ��������Ҫ��������ans���渲������Ҫ�Ĳ���
    void init(int _n,int _m){
		ansd=-1;
        n = _n;
        m = _m;
        for(int i = 0;i <= m;i++){
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
        }
        R[m] = 0; L[0] = m;
        size = m;
        for(int i = 1;i <= n;i++)
            H[i] = -1;
    }
    void Link(int r,int c){
        ++S[Col[++size]=c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0)H[r] = L[size] = R[size] = size;
        else{
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }
    void remove(int c){
        L[R[c]] = L[c]; R[L[c]] = R[c];
        for(int i = D[c];i != c;i = D[i])
            for(int j = R[i];j != i;j = R[j]){
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]];
            }
    }
    void resume(int c){
        for(int i = U[c];i != c;i = U[i])
            for(int j = L[i];j != i;j = L[j])
                ++S[Col[U[D[j]]=D[U[j]]=j]];
        L[R[c]] = R[L[c]] = c;
    }
	void Dance(int d){
        //��֦��
        if(ansd != -1 && ansd <= d)return;	//�ģ�������Ŀ���������Ҫ������С�Ķ������ǣ�����������
        if(R[0] == 0){
            if(ansd == -1)ansd = d;	//�ģ�������Ŀ���������Ҫ������С�Ķ������ǣ�����������
            else if(d < ansd)ansd = d;	//�ģ�������Ŀ���������Ҫ������С�Ķ������ǣ�����������
            //ansd = d;	//�ģ�������Ŀ���������Ҫ������С�Ķ������ǣ�������ȥ��
			return;
        }
        int c = R[0];
        for(int i = R[0];i != 0;i = R[i])
            if(S[i] < S[c])
                c = i;
        remove(c);
        for(int i = D[c];i != c;i = D[i]){
			ans[d] = Row[i];
            for(int j = R[i];j != i;j = R[j])remove(Col[j]);
            Dance(d+1);
			//if(ansd!=-1) return ;	//�ģ�������Ŀ���������Ҫ������С�Ķ������ǣ�������ȥ��
            for(int j = L[i];j != i;j = L[j])resume(Col[j]);
        }
        resume(c);
    }
};
DLX g;

int main(){
	int T;
	int n,m,p;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&p);
		g.init(p,n*m);
		int x1,y1,x2,y2;
		for(int k=1;k<=p;++k){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for(int i=x1+1;i<=x2;++i)
				for(int j=y1+1;j<=y2;++j)
					g.Link(k,j+(i-1)*m);
		}
		g.Dance(0);
		printf("%d\n",g.ansd);
	}
}
