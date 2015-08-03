//ע�⣺S�±��0��ʼ, S[n]�����������ַ�����С��
const int N = 20005;
int n; //�����׺������ַ����ĳ���
int times; //����
int sa[N]; //"���ڵڼ�����˭"
int rank[N], tmp_rank[N]; //"���ŵڼ�"
bool cmp_sa(int i, int j) {
	if (rank[i] != rank[j])
		return rank[i] < rank[j];
	else {
		int ri = i + times <= n ? rank[i + times] : -1;
		int rj = j + times <= n ? rank[j + times] : -1;
		return ri < rj;
	}
}
void build_sa(int *S, int *sa) {
	n = strlen(S);
	for (int i = 0; i <= n; ++i) {
		sa[i] = i;
		rank[i] = S[i];
	}
	for (times = 1; times <= n; times <<= 1) {
		sort(sa, sa + n + 1, cmp_sa);
		tmp_rank[sa[0]] = 0;
		for (int i = 1; i <= n; ++i) {
			tmp_rank[sa[i]] = tmp_rank[sa[i - 1]] + cmp_sa(sa[i - 1], sa[i]);
		}
		for (int i = 0; i <= n; ++i) {
			rank[i] = tmp_rank[i];
		}
	}
}

/*�߶�����(lcp)��
  lcp[i] = longest common prefix(sa[i], sa[i+1])
  lcp��һ�����ۣ�
  ��lcp[rank[i]] = h, ��lcp[rank[i + 1]] >= h - 1

  ע�⣺
  ����Ҫ�������lcp���±���ʵ�����������˳����Եģ���sa���±���������һ����������������
 */
int lcp[N];
void build_lcp(int *S, int *sa, int *lcp) {
	int h = 0;
	for(int i = 0; i < n; ++i) {
		int j = sa[rank[i] - 1];
		if(h > 0) --h;
		for(; j + h < n && i + h < n; ++h) {
			if(S[j + h] != S[i + h]) break;
		}
		lcp[rank[i] - 1] = h;
	}
}	
