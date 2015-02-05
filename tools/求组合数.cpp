//�������
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= Ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}

LL Inv(LL a,int m){   //����Ԫ
    LL d,x,y,t= (LL)m;
    d= Ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}

LL Cm(LL n, LL m, LL p){  //�����ѧ
     LL a=1, b=1;
	 if(m>n) return 0;
     while(m){
         a=(a*n)%p;
         b=(b*m)%p;
         m--;
         n--;
     }
     return (LL)a*Inv(b,p)%p;  ///��a/b��%p �ȼ��� a*��b��p������Ԫ
}
