//���������
struct Matrix{
	int a[][];	//�޸Ĵ�
	int x,y;
};
int n;
Matrix mul(Matrix a,Matrix b){
	Matrix ret;
	for(int i=0;i<a.x;++i){
		for(int j=0;j<b.y;++j){
			int tmp=0;	//�޸Ĵ�
			for(int k=0;k<a.y;++k){
				tmp=(tmp+a.a[i][k]*b.a[k][j]%MOD)%MOD;	//�޸Ĵ�
			}
			ret.a[i][j]=tmp;
		}
	}
	ret.x=a.x;
	ret.y=b.y;
	return ret;
}
Matrix power(Matrix m,int n){
	Matrix ret;
	memset(ret.a,0,sizeof(ret.a));
	for(int i=0;i<m.x;++i){		//�����������޸�
		ret.a[i][i]=1;
	}
	ret.x=ret.y=m.x;	//�����������޸�
	for(int i=1;i<=n;i<<=1){
		if(i&n){
			ret=mul(ret,m);
		}
		m=mul(m,m);
	}
	return ret;
}
