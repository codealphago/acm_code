//����[i, ls]��floor(a/k) == x�����������ǰ���x��ͬ���зֿ����
int sum[N];
LL ans = 0;
for (int i = 1, ls = 0; i <= min(a, b); i = ls + 1) {	//�ֿ�
	ls = min(a / (a / i), b / (b / i));
	ans += ((LL)sum[ls] - sum[i - 1]) * (a / i) * (b / i);
}
