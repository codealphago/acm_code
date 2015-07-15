/*zoj 3829 Known Notation
  ˼·��
  ̰�ģ�
  ֻ���������ֲ�����
  1. ��ǰ���������
  2. �������һ�����ֺͷ���
  ģ��һ�¼��ɡ�
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1005;
char str[N];
void gao(char str[]){
	int len=strlen(str);
	int cnt_c=0,cnt_d=0;
	int st=0;
	for(int i=0;i<len;++i){
		if(str[i]=='*') ++cnt_c;
		else ++cnt_d;
	}

	int ans=0;
	if(cnt_c+1>cnt_d){
		st+=cnt_c+1-cnt_d;
		ans+=cnt_c+1-cnt_d;
	}
	//cout<<ans<<endl;
	int p=len-1;
	for(int i=0;i<len;++i){
		if(str[i]=='*'){
			if(st>=2)
				--st;
			else{
				while(p>=0 && str[p]=='*'){
					--p;
				}
				swap(str[i],str[p]);
				++st;
				++ans;
			}
		}
		else{
			++st;
		}
	}
	cout<<ans<<endl;
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		gao(str);
	}
	return 0;
}
