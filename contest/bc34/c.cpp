/*hdu 5192
  ���⣺
  �����ֿ�ʼ���ľ�ˡ�
  �������������Ļ�ľ�ϣ����´��ʹ������������W�ѻ�ľ������ͬ�ĸ߶ȣ�ͬʱ��ϣ���߶�����ΪH��
  ���ֵĻ�ľ�����ˣ�Ҳ����˵��������µĻ�ľ��ֻ���ƶ����еĻ�ľ��
  �����԰�һ����ľ��һ���ƶ�����һ�ѻ����µ�һ�ѣ����ǲ����ƶ�������֮�䡣���磬һ���ƶ�֮��"3 2 3" ���Ա�� "2 2 4" ���� "3 2 2 1",���ǲ��ܱ��"3 1 1 3".
  ����������㣬����ĸ߶�hΪ����ʱ����Ҫ�ƶ��Ļ�ľ���٣�����ж��h�������������h�����ֵ�� 
  ���ƣ�
  �������ݵķ�Χ[1,50000]
  ˼·��
  ��ȡ+��״����
  ����ÿ������������O(1)������ʵĸ߶�h,h1��h2
  Ȼ�����ÿ���߶�����״����ά���Ͳ�ѯ���ڻ������ж��ٸ���С�ڵ�������߶ȣ�����͡�Ȼ����ڸø߶ȵ�Ҳ�Ϳ����������Ȼ��Ϳ��Եõ�����ÿ���߶������ƶ����ٴ��ˣ���һ����Сֵ���ɡ�
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=50005;
const LL INF=100000000000LL;
LL a[3*N];
int n;
LL w,h;
LL BIT[N],c[N];
int lowbit(int x){ return x&-x; }
LL _sum(int x){
	++x;
	LL s=0;
	while(x>0){
		s+=BIT[x];
		x-=lowbit(x);
	}
	return s;
}
LL _count(int x){
	++x;
	LL s=0;
	while(x>0){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
void update(int x,LL _c,LL w){
	++x;
	while(x<N){
		c[x]+=_c;
		BIT[x]+=w;
		x+=lowbit(x);
	}
}
int main(){
	while(scanf("%d%I64d%I64d",&n,&w,&h)!=EOF){
		memset(a,0,sizeof(a));
		memset(BIT,0,sizeof(BIT));
		memset(c,0,sizeof(c));
		LL sum=0;
		for(int i=0;i<n;++i){
			scanf("%I64d",&a[i+w]);
			sum+=a[i+w];
		}
		if(sum<w*h){ puts("-1"); continue; }
		int p=0,q=0;
		LL xy=0,nb=0,s=0;
		LL ans=INF,ansh=0;
		while(q<2*w+n){
			while(q-p+1<=w){
				if(a[q]>h) nb+=a[q]-h;
				else xy+=h-a[q];
				s+=a[q];
				update(a[q],1,a[q]);
				++q;
			}
			if(max(xy,nb)==ans) ansh=max(ansh,h);
			else if(max(xy,nb)<ans){ ans=max(xy,nb); ansh=h; }
			LL h1=s/w;
			LL h2=h1+1;
			if(h1>=h){
				LL sl,zs;
				if(sum>=w*h1){
					sl=_count(h1);
					zs=_sum(h1);
					LL xy1=h1*sl-zs;
					LL nb1=s-zs-h1*(w-sl);
					if(max(xy1,nb1)==ans) ansh=max(ansh,h1);
					else if(max(xy1,nb1)<ans){ ans=max(xy1,nb1); ansh=h1; }
				}
				if(sum>=w*h2){
					sl=_count(h2);
					zs=_sum(h2);
					LL xy2=h2*sl-zs;
					LL nb2=s-zs-h2*(w-sl);
					if(max(xy2,nb2)==ans) ansh=max(ansh,h2);
					else if(max(xy2,nb2)<ans){ ans=max(xy2,nb2); ansh=h2; }
				}
			}
			if(a[p]>h) nb-=a[p]-h;
			else xy-=h-a[p];
			s-=a[p];
			update(a[p],-1,-a[p]);
			++p;
		}
		printf("%I64d %I64d\n",ansh,ans);
	}
	return 0;
}
