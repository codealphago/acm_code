Bell��
1. ���壺
��n��Bell����ʾ����{1,2,3,...,n}�Ļ��ַ�����������B[0] = 1;

2. ��ָ�����ɺ�����
sigma(n=0~inf,B[n]/n! * x^n) = e^(e^x - 1)

3. ���ʣ�
(1) Bell����ڶ���Stiring���Ĺ�ϵ��
B[n] = sigma(k=1~n,S(n,k)) , S()��ʾS�ڶ���tiring��
�ڶ���Stirling���������ǣ�S(n,k)��ʾ��n�����廮�ֳ�k���ǿյĲ��ɱ��ģ��������Ϊ����û�б�ţ����ϵķ�������

(2) Bell������(�����������������������)
Bell�����εĹ��췽����
��һ�е�һ��Ԫ����1����a[1][1] = 1
����n>1����n�е�һ����ڵ�n-1�����һ���a[n][1] = a[n-1][n-1];
����m,n>1����n�е�m���������ߺ����Ϸ���������֮�ͣ���a[n][m] = a[n][m-1] + a[n-1][m-1];

ǰ����Bell���������£�
1
1	2
2	3	5
5	7	10	15
15	20	27	37	52
52	67	87	114	151	203

(3) Bell����ͬ�����ʣ�
(B[n] + B[n+1]) % p = B[p+n] % p , ����pΪ��������
(mB[n] + B[n+1]) % p = B[p^m + n] % p , ����pΪ��������

(4) Bell��ģ����p������Ϊ��
N[p] = (p^p - 1) / (p - 1)

4. Bell��Ԥ����
LL T[55], B[55];
void get_bell(int n, int mod) {
	B[0] = 1;
	B[1] = 1;
	T[0] = 1;
	for (int i = 2; i <= n; ++i) {
		T[i - 1] = B[i - 1];
		for (int j = i - 2; j >= 0; --j)
			T[j] = (T[j] + T[j + 1]) % mod;
		B[i] = T[0];
	}
}

5. ����ͬ���������Bell����ģֵ(ҪԤ����ģ)
//��B[n]%mod
//Ҫ��Ԥ����ǰ50��Bell������Ȼ���Ը���
//visÿ�ε���ǰ��Ҫ���
map<int, LL> vis;
LL bell_mod(int n, int mod) {
	LL ret = vis[n];
	if (ret) return ret;
	if (n <= 50) return B[n];	//��
	LL k = 0;
	LL P = 1;
	while (P < n) {
		P = P * mod;
		++k;
	}
	P /= mod;
	--k;
	return vis[n] = (k * bell_mod(n - P, mod) + bell_mod(n - P + 1, mod)) % mod;
}

