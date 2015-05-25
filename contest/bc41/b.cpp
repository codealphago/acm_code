/*hdu 5229 ZCC loves strings
  ���⣺
  CC��N���ַ����������ں�Miss G.����N���ַ�����һ��С��Ϸ��ZCC�����N�����еȸ������ѡ�����ַ�������������ͬһ������Ȼ��ZCC��Miss G.����������Miss G.�����Ȳ����ġ���ÿ���У������߿���ѡ�����A�����B��
  ����A������������ѡ��һ����ǰ�ǿյĴ���Ȼ�����������ĩβɾȥһ���ַ���
  ����B: ����ǰ��������ȫ��ͬ�ҷǿգ������ʹ�������������ʱ������������ա�
  ���ܲ������������������Ϸ��
  ZCC��Ҫ֪���������Ϸ�ĸ����Ƕ���(Ҳ����Miss G.��ʤ�ĸ���)��
  ���ƣ�
  2 <= N <= 20000; �ַ����ܳ��Ȳ�����200000
  ˼·��
  ��ʵ���ĺܼ򵥣������������ַ����Ƿ���ͬ�������ͬ��Miss G.Ӯ�����������ַ������Ⱥ͵���ż������Miss G.Ӯ��ż��Miss G.�䡣
  ��Ϊ�����ڲ���B�����˵�һ�����ں����Ĳ����������û�л���ִ�С�
 */
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define LL __int64
const int N=20000;
string s[N];
map<string,int> mp;
int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	int n;
	while(T--){
		LL ji=0;
		LL ou=0;
		mp.clear();
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>s[i];
			++mp[s[i]];
			if(s[i].length()%2==0) ++ou;
			else ++ji;
		}
		sort(s,s+n);
		int cnt=unique(s,s+n)-s;
		LL fz=0,fm;
		for(int i=0;i<cnt;++i){
			LL tmp=mp[s[i]];
			fz+=tmp*(tmp-1)/2;
		}
		fz+=ji*ou;
		//cout<<fz<<endl;
		fm=(LL)n*(n-1)/2;
		LL d=__gcd(fz,fm);
		fz/=d;
		fm/=d;
		cout<<fz<<"/"<<fm<<endl;
	}
	return 0;
}
