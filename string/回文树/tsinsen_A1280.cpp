/*======================================================
# Author: whai
#
# Last modified: 2015-10-05 15:37
#
# Filename: tsinsen_A1280.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;
const int M = 26;

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
		S[n] = -1;
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
		return len[last];
	}

	void count() {
		for(int i = p - 1; i >= 0; --i)
			cnt[fail[i]] += cnt[i];
	}
};

PalTree pt;
int len[N];
char str[N];

void gao(char str[]) {
	int ans = 0;
	int n = strlen(str);
	pt.init();

	for(int i = n - 1; i >= 0; --i) {
		len[i] = pt.add(str[i]);
	}
	pt.init();
	for(int i = 0; i < n - 1; ++i) {
		ans = max(ans, pt.add(str[i]) + len[i + 1]);
	}
	printf("%d\n", ans);
}

int main() {
	while(scanf("%s", str) != EOF) {
		gao(str);
	}
	return 0;
}

