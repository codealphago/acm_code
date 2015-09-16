//��˹��Ԫ����ģ��
//ʹ��ǰע�⣺
//�����������Ϊequ,�ֱ�Ϊ0��equ-1,����Ϊvar+1,�ֱ�Ϊ0��var��ʹ��ǰ��ʼ��a��x
const int N = 25,
          INF = 0x3f3f3f3f;
int a[N][N];	//�������
int x[N];	//�⼯
int free_x[N];	//�����洢���ɱ�Ԫ
int free_num;	//���ɱ�Ԫ�ĸ���
//��equ�����̣�var����Ԫ��
//����ֵΪ-1��ʾ�޽⣬Ϊ0��Ψһ�⣬���򷵻����ɱ�Ԫ����
int gauss(int equ, int var) {
	int max_r, col, k;
	free_num = 0;
	for (k = 0, col = 0; k < equ && col < var; k++, col++) {
		max_r = k;
		for (int i = k + 1 ; i < equ; i++)
			if (abs(a[i][col]) > abs(a[max_r][col]))
				max_r = i;
		if (a[max_r][col] == 0) {
			k--;
			free_x[free_num++] = col; //���ɱ�Ԫ
			continue;
		}
		if (max_r != k) {
			for (int j = col; j < var + 1; j++)
				swap(a[k][j], a[max_r][j]);
		}
		for (int i = k + 1; i < equ; i++)
			if (a[i][col] != 0)
				for (int j = col; j < var + 1; j++)
					a[i][j] ^= a[k][j];
	}
	for (int i = k; i < equ; i++)
		if (a[i][col] != 0)
			return -1;
	if (k < var)return var - k;
	for (int i = var - 1; i >= 0; i--) {
		x[i] = a[i][var];
		for (int j = i + 1; j < var; j++)
			x[i] ^= (a[i][j] && x[j]);
	}
	return 0;
}

//�Խ���Ĵ���(������ͳ�ƴ���0�Ľ������)
void deal(int equ, int var) {
	int fn = gauss(equ, var);	//���ɱ�Ԫ����
	/*(if(fn==-1){		//�޽�
		puts("inf");
		return ;
	}*/
	if (fn == 0) {		//Ψһ��
		int ans = 0;
		for (int i = 0; i < var; ++i)	//x[]����Ψһ��
			ans += x[i];	//����ʴ�
		printf("%d\n", ans);
		return ;
	}
	else {	//���
		//ö�����ɱ�Ԫ
		int ans = INF,
		    tot = (1 << fn);
		for (int i = 0; i < tot; i++) {
			int cnt = 0;
			for (int j = 0; j < fn; j++) {
				if (i & (1 << j)) {
					x[free_x[j]] = 1;	//����ʴ�
					cnt++;
				}
				else x[free_x[j]] = 0;	//����ʴ�
			}
			for (int j = var - fn - 1; j >= 0; j--) {
				int idx;
				for (idx = j; idx < var; idx++)
					if (a[j][idx])
						break;
				x[idx] = a[j][var];	//����ʴ�
				for (int l = idx + 1; l < var; l++)
					if (a[j][l])
						x[idx] ^= x[l];	//����ʴ�
				cnt += x[idx];
			}
			//���������forͳһ����
			ans = min(ans, cnt);
		}
		printf("%d\n", ans);
	}
}
