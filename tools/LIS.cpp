int	min_v[N]; //�洢����i+1��len�������������Ԫ�ص���Сֵ
int LIS(int a[], int size) {
	int len = 1;
	min_v[0] = a[0];
	for (int i = 1; i < size; ++i) {
		if (a[i] > min_v[len - 1]) { // ">" => ">="
			min_v[len++] = a[i];
		} else {
			int pos = upper_bound(min_v, min_v + len, a[i] - 1) - min_v;
			//int pos = upper_bound(min_v, min_v + len, a[i]) - min_v;
			min_v[pos] = a[i];
		}
	}
	return len;
}
