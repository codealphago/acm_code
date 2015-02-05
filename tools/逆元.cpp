LL ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}

//Ҫ��a��m����
LL Inv(LL a,int m){   //����Ԫ
    LL d,x,y,t= (LL)m;
    d= ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}

