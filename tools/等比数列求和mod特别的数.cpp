//�ȱ��������mod�ر����
//����a=0�����
LL dbsum(LL a,LL b,LL mod){
	if(b==0)
		return 1;
	if(b&1)
		return (a_b_MOD_c(a,(b+1)/2,mod)+1)*dbsum(a,b/2,mod)%mod;
	else
		return ((a_b_MOD_c(a,b/2,mod)+1)*dbsum(a,(b-1)/2,mod)%mod + a_b_MOD_c(a,b,mod))%mod;
}

