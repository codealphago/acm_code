/*����Ŀ���⡿
   ����һ����(n<=100000)����m(m<=100000)��������
   1.ADD.������[l,r]����������d��
   2.REVERSE.��תһ������[l,r]��
   3.REVOLVE.��һ������[l,r]ת��k�Σ�ÿת��һ�����ұߵ�����������ߣ���
   4.INSERT.��ĳ��λ��x�����һ������
   5.DELETE.ɾ��ĳ��λ��x�ϵ�����
   6.MIN.������[l,r]����Сֵ��

��������
   �������漰�Ĳ���ʮ��ǿ���߶���ֻ����ɲ���1��6��Treapֻ����ɲ���4��5��ֻ����չ��splay�ܽ���������⡣
   ����������ģ���⣬����д���û��ʲô��ע����ˡ������������������ע�ͣ��ó������к���poj������̵ģ����е���չ��ģ��Ƚϼ�࣬��ҿ���ѧϰһ�£���*/

//1.��չ�����ͣ�
struct tree {
   int par , ch[2] , dir; //���ס����Һ��ӡ��ýڵ����丸�׵���ڵ�(0)�����ҽڵ�(1)��
   int data , size , mins , mark; //���֡�������С�����������ֵ���Сֵ���������е�����Ҫ����mark��
   bool rev; //�����Ƿ񱻷�ת��
};
tree node[maxn];

//2.���Ӳ�����
void link( int par , int t , int dir ) { //�ѽڵ�par��dir������Ϊt��
   node[par].ch[dir] = t;
   node[t].par = par; //tҲҪά���丸�׵���Ϣ��
   node[t].dir = dir;
}

//3.������ά����
void release( int t ) {
   if ( node[t].rev ) { //�����������Ҫ��ת��
       swap( node[t].ch[0] , node[t].ch[1] ); //�������Ҷ��ӣ�������Ҳ�Ǳ���ģ���
       link( t , node[t].ch[0] , 0 );
       link( t , node[t].ch[1] , 1 );
       node[t].rev = false; //ȡ��t�ı�ǡ�
       if ( node[t].ch[0] != 0 ) node[node[t].ch[0]].rev ^= true; //���ݱ�ǡ�
       if ( node[t].ch[0] != 1 ) node[node[t].ch[1]].rev ^= true;
   }
   if ( node[t].mark != 0 ) { //����������������ϵ�һ������
       node[t].data += node[t].mark; //�õ�����ּ����������
       node[t].mins += node[t].mark; //����������СֵҲ�����������
       if ( node[t].ch[0] != 0 ) node[node[t].ch[0]].mark += node[t].mark;
       if ( node[t].ch[0] != 1 ) node[node[t].ch[1]].mark += node[t].mark;
       node[t].mark = 0; //ȡ��t�ı�ǡ�
   }
}

void update( int t ) { //ά��t����Ϣ��
   if ( node[t].ch[0] != 0 ) release( node[t].ch[0] ); //�ͷŶ��ӵı��ʹ����Ϣ��ȷ��
   if ( node[t].ch[1] != 0 ) release( node[t].ch[1] );
   node[t].size = node[node[t].ch[0]].size + node[node[t].ch[1]].size + 1; //ά��������С��
   node[t].mins = min( node[t].data , min( node[node[t].ch[0]].mins , node[node[t].ch[1]].mins ) ); //ά������������Сֵ��
}

//4.��չ������
void rotate( int t ) { //��ת�������ѽڵ�t������ת��
   int par = node[t].par;
   release( par ); //���ݱ�ǡ�
   release( t );
   int dir = node[t].dir; //Ū�常�׵ķ���
   link( node[par].par , t , node[par].dir ); //��ת��
   link( par , node[t].ch[!dir] , dir );
   link( t , par , !dir );
   update( par ); //ά����Ϣ��
}

void splay( int anc , int t ) { //��չ�ڵ�tʹ�丸��Ϊanc����ʹtΪ��ʱanc=0����
   release( t ); //���ݱ�ǡ�
   while ( node[t].par != anc ) {
       int par = node[t].par;
       if ( node[par].par != anc ) { //�ж���ת��ʽ��
           if ( node[t].dir == node[par].dir ) rotate( par );
               else rotate( t );
       }
       rotate( t );
   }
   update( t ); //ά����Ϣ��
}

//5.Ѱ�ҵ�k��λ�õĽڵ㣺
int rank( int t , int k ) { //Ѱ����tΪ�������е�k��λ�õĽڵ㡣
   while ( true ) {
       release( t ); //�ǵ�Ҫ���ݱ�ǣ���Ϊ������ʹ���Ҷ��ӻ�����
       int tmp = node[node[t].ch[0]].size + 1;
       if ( k == tmp ) break; //�ҵ��ˡ�
       if ( k < tmp ) t = node[t].ch[0]; //�жϸõ����Ŀ�������
           else {
               k -= tmp;
               t = node[t].ch[1];
           }
   }
   return t;
}

//6.������(l,r)��Ԫ�ؼ�����һ�������ϣ�ע���ǿ����䣩��
int draw( int l , int r ) {
   splay( 0 , 1 );
   int root = rank( 1 , l ) , t = rank( 1 , r );
   splay( 0 , root ); //�ѵ�lλԪ����ת�������ǳ�root��
   splay( root , t ); //�ѵ�rλԪ����תΪroot���Ҷ��ӣ��ǳ�t��
   return t; //����t����ʱ����(l,r)��Ԫ�ؼ�������node[t].ch[0]Ϊ���������ϡ�
}

//7.����splay������⣺
void solve() {
   tot = 2; //����������ڵ㣬��1һ���ڵ�һ��λֵ����2һ���ڵڶ���λ�á����������Ҫ��draw������������[l,r]����Ҫ�õ���l-1�͵�r+1���鹹����1��2ʹ��l=1��r=nʱdraw�����������С�
   node[1].size = node[2].size = 1;
   node[0].mins = node[1].mins = node[2].mins = Inf; //��ʵ������ĵ��data��mins�������޴�
   node[0].data = node[1].data = node[2].data = Inf;
   
   scanf( "%d" , &n ); //����ʱ�����Ǵ����ϵ����������������splayһ��Ҷ����ά����Ϣ��
   for ( int i = 1 ; i <= n ; i++ ) {
       node[++tot].size = 1;
       scanf( "%d" , &node[tot].data );
       if ( i == 1 ) link( 1 , tot , 1 );
           else link( tot - 1 , tot , 1 );
   }
   link( tot , 2 , 1 );
   splay( 0 , 2 );
   
   scanf( "%d" , &m );
   for ( int i = 1 ; i <= m ; i++ ) {
       string str; cin >> str;
       if ( str == "ADD" ) {
           int l , r , d; scanf( "%d%d%d" , &l , &r , &d );
           int t = node[draw( l , r + 2 )].ch[0]; //��ȡ������[l,r]�����ڵ�1�Ĵ���������ߣ�ʹ�ø�����Ӧ����һλ���[l+1,r+1]=(l,r+2)����ͬ�����͡�
           node[t].mark += d; //������������ֶ�����d��
           splay( 0 , t ); //����Ϣ�ı���ĵ���չһ��һά������������Ϣ����ͬ�����͡�
       } else
       if ( str == "REVERSE" ) {
           int l , r; scanf( "%d%d" , &l , &r );
           int t = node[draw( l , r + 2 )].ch[0];
           node[t].rev ^= true; //����ͬADD������ֻ�������޸ĵ���Ϣ��ͬ��
           splay( 0 , t );
       } else
       if ( str == "REVOLVE" ) {
           int l , r , k; scanf( "%d%d%d" , &l , &r , &k );
           int w = r - l + 1;
           k = ( k % w + w ) % w; //k�����䳤��ȡģ��
           if ( k == 0 ) continue; //k=0����ûת�����������൱�ڰѸ�������ұ�k�����Ƶ��������
           int t = draw( r - k + 1 , r + 2 ) , nt = node[t].ch[0];
           link( t , 0 , 0 ); //�е��ұ�k��������ntΪ������������
           splay( 0 , t );
           t = draw( l , l + 1 );
           link( t , nt , 0 ); //����k���������������ߡ�
           splay( 0 , nt );
       } else`	
       if ( str == "INSERT" ) {
           node[++tot].size = 1;
           int x; scanf( "%d%d" , &x , &node[tot].data );
           int t = draw( x + 1 , x + 2 ); //��ʱ���Ǹ�����ǰ�Ľڵ㣬t��������Ľڵ㡣
           link( t , tot , 0 ); //����������־Ͳ��������м䣬��Ϊt������ӡ�
           splay( 0 , tot );
       } else
       if ( str == "DELETE" ) {
           int x; scanf( "%d" , &x );
           int t = draw( x , x + 2 );
           link( t , 0 , 0 ); //�ж�����ڵ㡣
           splay( 0 , t );
       } else
       if ( str == "MIN" ) {
           int l , r; scanf( "%d%d" , &l , &r );
           int t = node[draw( l , r + 2 )].ch[0];
           printf( "%d\n" , node[t].mins ); //����ͬADD�������������ǻ�ȡ��Сֵ����Ϣ��
       }
   }
}

