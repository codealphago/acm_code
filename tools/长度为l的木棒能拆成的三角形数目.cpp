//�󳤶�Ϊl��ľ�����س�3�Σ�������������εķ�������
LL gao(int l){
	LL ret=0;
	for(int i=1;2*i<l;++i){
		ret+=(l-1)/2-(l/2-i);
	}
	return ret;
}

