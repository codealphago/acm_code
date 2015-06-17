import java.util.*;

public class PowerfulSpell
{
   public static void main(String[] arg) throws java.io.IOException
   {
      // �ǩ`�����åȤ򣱂��i���z��Ǥ� solve() ����ӳ�����`��
      for(Scanner sc = new Scanner(System.in) ;;)
      {
         int N = sc.nextInt();
         int A = sc.nextInt();
         int S = sc.nextInt();
         int G = sc.nextInt();
         if( N==0 && A==0 && S==0 && G==0 )
            break;

         Arrow[] arr = new Arrow[A];
         for(int i=0; i<A; ++i)
            arr[i] = new Arrow(sc);

         System.out.println( solve(N,S,G,arr) );
      }
   }

   // ʸӡ�ǩ`��
   static class Arrow
   {
      final int    x;
      final int    y;
      final String lab;

      Arrow(Scanner sc) throws java.io.IOException
      {
         x   = sc.nextInt();
         y   = sc.nextInt();
         lab = sc.next();
      }
   }

   // �����`�Ȥ���νU·����ǩ`��
   // �ɤ����������Ф���������spell���ȡ���ɤι���ˤ��뤫��lastNode��
   static class Path implements Comparable<Path>
   {
      final String spell;
      final int lastNode;
      Path(String s, int n) { spell=s; lastNode=n; }

      // �Ǖ�혤��礤�ۤ������������U·
      public int compareTo( Path rhs ) {
         int c = spell.compareTo(rhs.spell);
         return c!=0 ? c : lastNode-rhs.lastNode;
      }
   }

   // ����
   static String solve(int N, int S, int G, Arrow[] arr)
   {
      // �Ȥꤢ���������`����Ť��ʤ�������Ԥ��z��ǤϤ����ʤ��Τǡ�
      // �ޤ�ȫ����ˤĤ��ơ����`��ޤ��Ф��뤫�ɤ����{�٤Ƥ���
      //
      // �����ϡ�������̽��(BFS)�Ǥ������̽��(DFS)�Ǥ⡢
      // �ʤ�Ǥ⤪�äߤη����Ǥ�����˼���ޤ���

      boolean[][] reachable = new boolean[N][N];

      for(Arrow a : arr)
         reachable[a.x][a.y] = true;
      for(int k=0; k<N; ++k)
      {
         reachable[k][k] = true;
         for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
               reachable[i][j] |= reachable[i][k] & reachable[k][j];
      }

      // ���⤽�⥹���`�Ȥ��饴�`����Ф��ʤ����Ϥ� "NO"

      if( !reachable[S][G] )
         return "NO";

      // �Ф�����Ϥϡ�
      // �����`�Ȥ���ʼ��ơ����Ǖ�혤��礤혤ˡ��U·�����Ф�ȫ̽�����Ƥ����ޤ���

      TreeSet<Path> q = new TreeSet<Path>(); // ̽�����a
      q.add( new Path("",S) ); // �������`�� S �ˤ��ޤ���״�B����̽���_ʼ

      for(;;)
      {
         Path p = q.pollFirst(); // ���a�Τʤ�����һ���礤�Τ�ȡ�����

         if( p.lastNode == G ) // ���`��ˤĤ���
            return p.spell;

         if( p.spell.length() >= N*6 ) // ��`�פ��Ƥ�
            return "NO";

         for(Arrow a : arr) // �������⣺��ι��㤫��һ�ĥѥ��ӤФ�����Τ���a������
            if( p.lastNode==a.x && reachable[a.y][G] )
               q.add( new Path(p.spell+a.lab, a.y) );
          // �����ϡ�"�Ǖ�혤���С��ʸӡ�ȡ��������^�ǤȤ�����" ����
          // �����ʮ�֤ʤ�Ǥ��������`�ɕ������浹�ʤΤ�ȫ����ꡭ
      }
   }
}
