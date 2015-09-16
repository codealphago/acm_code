/*���⣺
  СA��СB����һ����Ϸ������һ��ʼÿ�����϶���һ��01�ַ��������м�СA���ϵ�ΪA����СB���ϵ�ΪB����
  ������һö���ȵ�Ӳ�ң��Լ�һ�����ַ���S����Ϸ��ʼ��ÿһ�غ϶���Ͷ����öӲ�ң�����������ϣ�����S�������һ���ַ�'1'���������һ���ַ�'0'��
  һ��ĳһ�غϽ���ʱA����Ϊ��S���Ӵ���СA��Ӯ�ˣ�ͬ�����B����Ϊ��S���Ӵ���СB��Ӯ�ˣ���һ���˻��ʤ��ʱ��Ϸ������Ϊ�˱���������ͬʱʤ�����������֤A��ΪB�ĺ�׺��BҲ��ΪA�ĺ�׺��
  ����֪A��B������£������Ϸ�ǲ��ǹ�ƽ���أ���ƽ��ζ��СA��СBӵ����ͬ��ʤ�ʣ�������ƽ˭���п���Ӯ��
  ���ƣ�
  1 <= |A|,|B| <= 100000
  ˼·��
  1. ����Ҫ֪��Penney��s game�Ľ��ۣ�
  ���� a �� b ������ n λ 01 ������� a �� b ��ȫ��ȣ���ô��һ������ 1 ���������ȣ���ô��һ������ 0 �����������Ƚ� a �ĺ��� n �C 1 λ�Լ� b ��ǰ�� n �C 1 λ�������ȣ���ô���ż�һ������ 1 ���������ȣ���ô���ż�һ������ 0 �����������Ƚ� a �ĺ� n �C 2 λ�Լ� b ��ǰ n �C 2 λ�������ݱȽϽ���������� 0 �������� 1 ��������������ȥ��ֱ�����Ƚ� a ������� 1 λ�� b ����ǰ�� 1 λ���������µ����֡������������У�������μ��� n �����֣����ջ�õ�һ�� n λ�� 01 ������������һ��������������ת����ʮ���ơ����ǰ����յĽ����Ϊ L(a, b) ���ټ������ӣ�
  L(10110, 10110) = (10010)2 = 18
  L(10110, 01011) = (00001)2 = 1
  L(01011, 01011) = (10000)2 = 16
  L(01011, 10110) = (01001)2 = 9
  ��ô�� 01 �� a �� b ��ʤ��֮�Ⱦ���
  (L(b, b) �C L(b, a)) : (L(a, a) �C L(a, b))

  2. ��Ϊ�������Ƚϴ�Ҫ��kmp���Ż���
  kmp�Ż���ʽ���£�
  �����ģʽ����next���飬���ϵغ�ĸ�������һλƥ�䣬��¼����ƥ��ĳ��ȼ��ɡ�

  3. ��java�����ᳬʱ��Ҫ��c++ģ������ƴ���������
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
const int N = 100050;
LL aa[N / 50], bb[N / 50], ab[N / 50], ba[N / 50];
int next[N];
void getNext(char T[], int len) {
	int i, j;
	i = 0;
	j = next[0] = -1;
	while (i < len) {
		if (j == -1 || T[i] == T[j]) next[++i] = ++j;
		else j = next[j];
	}
}
void deal(char S[], char T[], int slen, int tlen, LL res[]) {
	for (int i = 0; i <= max(slen / 50, tlen / 50); ++i) res[i] = 0;
	int i = 0, j = 0;
	if (slen >= tlen) i += slen - tlen;
	else j += tlen - slen;
	getNext(T, tlen);
	while (i < slen) {
		if (j == -1 || S[i] == T[j]) {
			++i; ++j;
			if (i == slen && j != 0) {
				int bl = (j - 1) / 50;
				int mv = (j - 1) % 50;
				res[bl] |= (1LL) << mv;
				--i;
				j = next[j - 1];
			}
		}
		else j = next[j];
	}
}
char A[N], B[N];
void print(LL a[], int len) {
	for (int i = 0; i < len; ++i) {
		int bl = i / 50;
		int mv = i % 50;
		cout << (a[bl] & (1LL << mv)) << ' ';
	}
	cout << endl;
}
void sub(LL a[], LL b[], int alen, int blen) {
	int lim = max(alen / 50, blen / 50);
	int c = 0;
	for (int i = 0; i <= lim; ++i) {
		LL tmp = a[i] - b[i] - c;
		if (tmp < 0) { c = 1, tmp += (1LL) << 50; }
		else c = 0;
		a[i] = tmp;
	}
}
int n, m;
int cmp(LL a[], LL b[], int alen, int blen) {
	int lim = max(alen / 50, blen / 50);
	int ret = 0;
	for (int i = lim; i >= 0; --i) {
		if (a[i] > b[i]) { ret = 1; break; }
		if (a[i] < b[i]) { ret = -1; break; }
	}
	return ret;
}
void gao() {
	int fa, fb;
	sub(bb, ba, m, m);
	sub(aa, ab, n, n);
	int ans = cmp(bb, aa, m, n);
	if (ans == 0) puts("Equal");
	else if (ans == 1) puts("Hamlet");
	else puts("Laertes");
}
int main() {
	while (scanf("%d%d", &n, &m) && (n || m)) {
		scanf("%s%s", A, B);
		deal(A, A, n, n, aa);
		deal(B, B, m, m, bb);
		deal(A, B, n, m, ab);
		deal(B, A, m, n, ba);
		//print(aa,n);
		//print(ab,n);
		//print(bb,m);
		//print(ba,m);
		gao();
	}
	return 0;
}
