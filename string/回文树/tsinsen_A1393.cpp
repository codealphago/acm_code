/*tsinsen A1393. Palisection
  ���⣺
  ����һ������n��ֻ��Сд��ĸ��ɵ��ַ���s��
�����ǿ���s�����������һ��ĵ��Ӵ�����P��λ�ò�ͬ��������ͬ��������������ͬ��
  �ʴ�P��ѡ����������������s���й���λ�õķ������м�����
  ���ƣ�
  n <= 2 * 1e6
  ˼·��
  ������
  ���ȴ�S���Ų��빹����������������ÿ���±�Ϊ��β�Ļ��Ĵ�������Ȼ�������׺�ͣ�sum[i]��ʾ��ͷ�±���ڵ����±�i�Ļ��Ĵ�������
  Ȼ�����������Ų����ַ������������ÿ�β��������ans+=num[i]*sum[i+1]��
  �����Ų��������������õ�ansǡ��û���ص��Ĵ��Ķ�������������ֻҪ��������еĶ�������ȥans����Ǵ𰸡�
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 2 * 1e6 + 5;
const int M = 26;
const int MOD = 51123987;

struct PalTree {
	int nxt[N][M]; //��ʾ���Ϊi�Ľڵ��ʾ�Ļ��Ĵ�����������ַ�c�Ժ��ɵĻ��Ĵ��ı��
	int fail[N]; //��ʾ�ڵ�iʧ���Ժ���ת����������Ľڵ�i��ʾ�Ļ��Ĵ������׺���Ĵ�
	int cnt[N]; //��ʾ�ڵ�i��ʾ�ı��ʲ�ͬ�Ĵ��ĸ���������ʱ����Ĳ�����ȫ�ģ����count()������һ���Ժ������ȷ�ģ�
	int num[N]; //��ʾ�Խڵ�i��ʾ������Ĵ������Ҷ˵�Ϊ���Ĵ���β�Ļ��Ĵ�����
	int len[N]; //��ʾ���Ϊi�Ľڵ��ʾ�Ļ��Ĵ��ĳ��ȣ�һ���ڵ��ʾһ�����Ĵ���
	int S[N]; //��ʾ��i����ӵ��ַ���һ��ʼ��S[0] = -1������������һ���ڴ�S�в�����ֵ��ַ�����
	int last; //ָ�������һ����ĸ�����γɵ�����Ĵ���ʾ�Ľڵ�
	int n; //��ʾ��ӵ��ַ�����
	int p; //��ʾ��ӵĽڵ����

	int new_node(int x) {
		memset(nxt[p], 0, sizeof(nxt[p]));
		cnt[p] = 0;
		num[p] = 0;
		len[p] = x;
		return p++;
	}

	void init() {
		p = 0;
		new_node(0);
		new_node(-1);
		last = 0;
		n = 0;
		S[0] = -1;
		fail[0] = 1;
	}

	int get_fail(int x) {
		while(S[n - len[x] - 1] != S[n]) x = fail[x];
		return x;
	}

	int add(int x) {
		x -= 'a';
		S[++n] = x;
		int cur = get_fail(last);
		if(!nxt[cur][x]) {
			int now = new_node(len[cur] + 2);
			fail[now] = nxt[get_fail(fail[cur])][x];
			nxt[cur][x] = now;
			num[now] = num[fail[now]] + 1;
		}
		last = nxt[cur][x];
		++cnt[last];
		return num[last];
	}

	void count() {
		for(int i = p - 1; i >= 0; --i)
			cnt[fail[i]] += cnt[i];
	}

	LL pal_str_num() {
		LL ret = 0;
		for(int i = p - 1; i > 0; --i) {
			cnt[fail[i]] = (cnt[fail[i]] + cnt[i]) % MOD;
			ret = (ret + cnt[i]) % MOD;
		}
		return ret;
	}
};

PalTree pt;
char str[N];
int sum[N];

void gao(int n) {
	LL ans = 0;
	pt.init();
	sum[n] = 0;
	for(int i = n - 1; i >= 0; --i) {
		sum[i] = (sum[i + 1] + pt.add(str[i])) % MOD;
	}
	pt.init();
	for(int i = 0; i < n; ++i) {
		ans = (ans + (LL)pt.add(str[i]) * sum[i + 1]) % MOD;
	}
	LL all = pt.pal_str_num();
	ans = (((LL)all * (all - 1) / 2 % MOD - ans) % MOD + MOD) % MOD;
	cout<<ans<<endl;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		scanf("%s", str);
		gao(n);
	}
	return 0;
}

