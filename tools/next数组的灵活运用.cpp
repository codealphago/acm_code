/*1. ������next����ĳ����÷�
  ����ģʽ��T���������״γ��ֵ�λ��(��0��ʼ)
  ����ģʽ��T���������״γ��ֵĴ���
 */
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1000005;
int nxt[N];
char S[N], T[N];
int slen, tlen;
/*���ģ�� �ַ����Ǵ�0��ʼ��
  nxt�����Ǵ�1��ʼ��
 */
void get_next() {
	int j, k;
	j = 0; k = -1; nxt[0] = -1;
	while (j < tlen)
		if (k == -1 || T[j] == T[k])
			nxt[++j] = ++k;
		else
			k = nxt[k];

}
/*����ģʽ��T������S���״γ��ֵ�λ��
  ���ص�λ���Ǵ�0��ʼ�ġ�
 */
int kmp_index() {
	int i = 0, j = 0;
	while (i < slen && j < tlen) {
		if (j == -1 || S[i] == T[j]) {
			i++; j++;
		}
		else
			j = nxt[j];
	}
	if (j == tlen)
		return i - tlen;
	else
		return -1;
}
//����ģʽ��������S�г��ֵĴ���
int kmp_count() {
	int ans = 0;
	int j = 0;
	for (int i = 0; i < slen; i++) {
		while (j > 0 && S[i] != T[j])
			j = nxt[j];
		if (S[i] == T[j])
			j++;
		if (j == tlen) {
			ans++;
			j = nxt[j];
		}
	}
	return ans;
}
int main() {
	int TT;
	cin >> TT;
	while (TT--) {
		cin >> T >> S;
		slen = strlen(S);
		tlen = strlen(T);
		get_next();
		for (int i = 1; i <= tlen; ++i) {
			cout << nxt[i] << ' ';
		}
		cout << endl;
		cout << "ģʽ��T������S���״γ��ֵ�λ����: " << kmp_index() << endl;
		cout << "ģʽ��T������S�г��ֵĴ���Ϊ: " << kmp_count() << endl;
	}
	return 0;
}
/*1
  abcabcabc abc

  nxt[1~n]Ϊ��
  0 0 0 1 2 3 4 5 6
 */


/*2. ��������һ���ַ�����������ַ�������ɶ��ٸ��ظ����Ӵ����ɡ�
  �Ӵ�����=len-next[len]
  �磺
  aaaa �Ӵ�����=1
  aaab �Ӵ�����=4
  ababa �Ӵ�����=2
  aabaabaa �Ӵ�����=3
  ��һ������
 */
/*poj 2406
  ���⣺
  ����һ���ַ�����������ַ�������ɶ��ٸ��ظ����Ӵ����ɡ�
  ���ƣ�
  1 <= len <= 1e6
 */
#include<cstring>
#include<cstdio>
using namespace std;

const int N = 1000005;
int main() {
	while (scanf("%s", T) != EOF) {
		if (T[0] == '.') break;
		tlen = strlen(T);
		get_next();
		int zq = tlen - nxt[tlen];
		if (tlen % zq == 0)
			printf("%d\n", tlen / zq);
		else
			puts("1");
	}
	return 0;
}

/*3. ��һ������һ���ַ���������ͬ��ǰ׺�ͺ�׺
  �磺
  ababab
  ��ͬ��ǰ��׺Ϊ��
  ab
  abab
  ababab
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1000005;
int ans[N], cnt;
int main() {
	while (scanf("%s", T) != EOF) {
		tlen = strlen(T);
		get_next();
		cnt = 0;
		int i = tlen;
		while (i > 0) {
			ans[cnt++] = i;
			i = nxt[i];
		}
		for (int i = cnt - 1; i >= 0; --i) {
			printf("%d%c", ans[i], i == 0 ? '\n' : ' ');
		}
	}
	return 0;
}
