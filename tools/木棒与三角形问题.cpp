ľ�������������⣬һ�㶼����ö����ߣ����ݳ�����

1. �󳤶�Ϊl��ľ�����س�3�Σ�������������εķ�����(�ص�λ�ò�ͬ�㲻ͬ�ķ�������1 3 3��3 3 1�㲻ͬ�ķ���)��
//����һ��
LL gao(int l){
	LL ret=0;
	for(int i=1;2*i<l;++i) {
		ret+=(l-1)/2-(l/2-i);
	}
	return ret;
}

//��������
//ö����ߣ����ݳ�����
LL cal(LL a, LL remain) {
	if(a < remain) return 0;
	return remain - 1;
}

LL gao(LL l) {
	LL ret = (l - 1) * (l - 2) / 2;
	for(int i = 1; i < l; ++i) {
		ret -= 3 * cal(i, l - i);
	}
	return ret;
}

2. ����3��ľ�������ȷֱ�Ϊa, b, c���ֱ������һ������a1, b1, c1��ʹ�������ܹ���һ�������Σ���a1 + b1 + c1 == l����a1, b1, c1 >= 0�����ܹ��������εķ�����(������ͬ�㲻ͬ�ķ���)��
���ƣ�1 <= a, b, c <= 1e5; 0 <= l <= 1e5

LL cal(LL a, LL b, LL c, LL r) {
	if(a < b + c + r) return 0;
	return r + 1;
}

void gao(LL a, LL b, LL c, LL l) {
	LL ans = (l + 1) * (l + 2) / 2;
	for(int i = 0; i <= l; ++i) {
		ans -= cal(a + i, b, c, l - i);
		ans -= cal(b + i, a, c, l - i);
		ans -= cal(c + i, a, b, l - i);
	}
	cout<<ans<<endl;
}


3. ����3��ľ�������ȷֱ�Ϊa, b, c���ֱ������һ������a1, b1, c1��ʹ�������ܹ���һ�������Σ���a1 + b1 + c1 <= l����a1, b1, c1 >= 0�����ܹ��������εķ�����(������ͬ�㲻ͬ�ķ���)��
���ƣ�1 <= a, b, c <= 1e5; 0 <= l <= 1e5

LL cal(LL a, LL b, LL c, LL r) {
	if(a < b + c) return 0;
	LL tmp = min(r, a - (b + c));
	return (tmp + 1) * (tmp + 2) / 2;
}

void gao(LL a, LL b, LL c, LL l) {
	LL ans = (l + 1) * (l + 2) * (l + 3) / 6;

	for(int i = 0; i <= l; ++i) {
		ans -= cal(a + i, b, c, l - i);
		ans -= cal(b + i, a, c, l - i);
		ans -= cal(c + i, a, b, l - i);
	}
	cout<<ans<<endl;
}
