/*mu[d]ΪĪ����˹�������������£�
  (1)��d=1,��mu[d]=1;
  (2)��d=P1*P2*P3*...*Pk,PiΪ���������,��ômu[d]=(-1)^k;
  (3)�������mu[d]=0;

  mu[d]�����ʣ�
  1. ��������������n�У�
  (1)sigma(d|n,mu[d])=1,��n=1ʱ;
  (2)sigma(d|n,mu[d])=0,��n>1ʱ;

  2.��������������n�У�
  sigma(d|n,mu[d]/d)=phi(n)/n,����phi(n)Ϊŷ������

  Ī����˹���ݹ�ʽ������д����
  1. F(n)=sigma(d|n,f(d)) -> f(n)=sigma(d|n,mu[d]*F(n/d))
  2. F(n)=sigma(n|d,f(d)) -> f(n)=sigma(n|d,mu[d/n]*F(d))

  д�����Ƚϳ��á�
 */

//���ö���Ԥ����
const int N=1e5+5;
int mu[N];
//O(nlog(n))
void getMu(){
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
}

//����ɸ��Ԥ����
const int N=1e5+5;
int mu[N],pri[N],pcnt;
bool vis[N];
void getMu(){
	memset(vis,0,sizeof(vis));
	mu[1]=1;
	pcnt=0;
	for(int i=2;i<N;++i){
		if(!vis[i]){
			pri[pcnt++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<pcnt && i*pri[j]<N;++j){
			vis[i*pri[j]]=1;
			if(i%pri[j]) mu[i*pri[j]]=-mu[i];
			else{
				mu[i*pri[j]]=0;
				break;
			}
		}
	}
}

