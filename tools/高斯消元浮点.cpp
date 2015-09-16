//��˹��Ԫ����ģ��
//ʹ��ǰע�⣺
//�����������Ϊequ,�ֱ�Ϊ0��equ-1,����Ϊvar+1,�ֱ�Ϊ0��var��ʹ��ǰ��ʼ��a��x
const int N = 215;
const double eps = 1e-12;
double a[N][N]; //���̵���ߵľ���͵�ʽ�ұߵ�ֵ
double x[N];	//���֮��x��ľ��ǽ��
int equ, var;	//��������δ֪������

void Gauss() {
	int row, col, max_r;
	int i, j;
	row = col = 0;
	while (row < equ && col < var) {
		max_r = row;
		for (i = row + 1; i < equ; i++)
			if (fabs(a[i][col]) - fabs(a[max_r][col]) > eps)
				max_r = i;

		if (max_r != row) {
			for (j = col; j <= var; j++)
				swap(a[row][j], a[max_r][j]);
		}
		if (fabs(a[row][col]) < eps) {
			col++;
			continue;
		}

		for (i = row + 1; i < equ; i++) {
			if (fabs(a[i][col]) > eps) {
				double t = a[i][col] / a[row][col];
				a[i][col] = 0.0;
				for (j = col + 1; j <= var; j++)
					a[i][j] -= a[row][j] * t;
			}
		}
		row++;
		col++;
	}
	for (i = equ - 1; i >= 0; i--) {
		if (fabs(a[i][i]) < eps) continue;
		double tmp = a[i][var];
		for (j = i + 1; j < var; j++)
			tmp -= a[i][j] * x[j];
		x[i] = tmp / a[i][i];
	}
}
