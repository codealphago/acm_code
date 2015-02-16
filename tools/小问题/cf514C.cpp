/*codeforces 514C Watto and Mechanism
  ���⣺
  ����һ������n�����ʵ��ֵ䣬����m������ѯ���ʣ�������������ҽ���һ���ַ�����ͬ������¿������ֵ����ҵ��������YES���������NO
  ���ƣ�
  0 <= n,m <= 3*10^5; ���ַ����Ȳ�����6*10^5
  ˼·��
  �ֶα�����
  �Բ�ѯ���ʳ���Ϊ500�ֶΣ�
  ��ѯ���ʳ���<500�򣺲���set��ѯ�����Ӷ�Ϊ600*500*500=1.5*10^8
  ��ѯ���ʳ���>500�򣺱�����ѯ�����Ӷ�Ϊ600*600*500=1.8*10^8
  �ڸ��Ӷ��ڿ���ʵ�֡�
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<tr1/unordered_set>
#include<ctime>
using namespace std;
using namespace std::tr1;
unordered_set<string> _set;
unordered_set<string>::iterator it;
int main(){
	double st=clock(),en;
	ios_base::sync_with_stdio(false);
	int n,m;
	string str;
	cin>>n>>m;
	int maxl=0;
	for(int i=0;i<n;++i){
		cin>>str;
		_set.insert(str);
	}
	for(int i=0;i<m;++i){
		cin>>str;
		bool flag=false;
		if(str.length()>500){
			for(it=_set.begin();it!=_set.end();++it){
				if(it->length()==str.length()){
					int cnt=0;
					for(int i=0;i<str.length();++i){
						if((*it)[i]!=str[i]){
							++cnt;
							if(cnt>1) break;
						}
					}
					if(cnt==1){ flag=true; break; }
				}
			}
		}
		else
			for(int j=0;j<str.length();++j){
				char bl=str[j];
				for(int k=0;k<3;++k){
					if(k==bl-'a') continue;
					str[j]=k+'a';
					if(_set.find(str)!=_set.end()){
						flag=true;
						break;
					}
				}
				str[j]=bl;
				if(flag) break;
			}
		if(flag) puts("YES");
		else puts("NO");
	}
	en=clock();
	cerr<<(en-st)/CLOCKS_PER_SEC<<endl;
	return 0;
}
