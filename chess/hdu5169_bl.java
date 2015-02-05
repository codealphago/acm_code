/*���⣺
  СA��СB����һ����Ϸ������һ��ʼÿ�����϶���һ��01�ַ��������м�СA���ϵ�ΪA����СB���ϵ�ΪB����
  ������һö���ȵ�Ӳ�ң��Լ�һ�����ַ���S����Ϸ��ʼ��ÿһ�غ϶���Ͷ����öӲ�ң�����������ϣ�����S�������һ���ַ�'1'���������һ���ַ�'0'��
  һ��ĳһ�غϽ���ʱA����Ϊ��S���Ӵ���СA��Ӯ�ˣ�ͬ�����B����Ϊ��S���Ӵ���СB��Ӯ�ˣ���һ���˻��ʤ��ʱ��Ϸ������Ϊ�˱���������ͬʱʤ�����������֤A��ΪB�ĺ�׺��BҲ��ΪA�ĺ�׺��
  ����֪A��B������£������Ϸ�ǲ��ǹ�ƽ���أ���ƽ��ζ��СA��СBӵ����ͬ��ʤ�ʣ�������ƽ˭���п���Ӯ��
  ���ƣ�
  1 <= |A|,|B| <= 100
  ˼·��
  1. ����Ҫ֪��Penney��s game�Ľ��ۣ�
  ���� a �� b ������ n λ 01 ������� a �� b ��ȫ��ȣ���ô��һ������ 1 ���������ȣ���ô��һ������ 0 �����������Ƚ� a �ĺ��� n �C 1 λ�Լ� b ��ǰ�� n �C 1 λ�������ȣ���ô���ż�һ������ 1 ���������ȣ���ô���ż�һ������ 0 �����������Ƚ� a �ĺ� n �C 2 λ�Լ� b ��ǰ n �C 2 λ�������ݱȽϽ���������� 0 �������� 1 ��������������ȥ��ֱ�����Ƚ� a ������� 1 λ�� b ����ǰ�� 1 λ���������µ����֡������������У�������μ��� n �����֣����ջ�õ�һ�� n λ�� 01 ������������һ��������������ת����ʮ���ơ����ǰ����յĽ����Ϊ L(a, b) ���ټ������ӣ�
  L(10110, 10110) = (10010)2 = 18
  L(10110, 01011) = (00001)2 = 1
  L(01011, 01011) = (10000)2 = 16
  L(01011, 10110) = (01001)2 = 9
  ��ô�� 01 �� a �� b ��ʤ��֮�Ⱦ���
  (L(b, b) �C L(b, a)) : (L(a, a) �C L(a, b))

  2. ��Ϊ������С��ֻ��100������ֱ����java����������
 */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static final int N = 105;
    static boolean cmp(char[] a,char[] b,int len){
        if(len>b.length) return false;
        boolean ret=true;
        for(int i=0;i<len;++i){
            if(b[i]!=a[a.length-len+i]){
                ret=false;
                break;
            }
        }
        return ret;
    }
    static BigInteger toBigInt(char a[],int len){
        BigInteger ret=BigInteger.ZERO;
        for(int i=len-1;i>=0;--i)
            ret=ret.multiply(BigInteger.valueOf(2)).add(BigInteger.valueOf(a[i]-'0'));
        return ret;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str;
        char[] A=new char[N];
        char[] B=new char[N];
        char[] aa=new char[N],bb=new char[N],
        ab=new char[N],ba=new char[N];
        BigInteger AA,BB,AB,BA;
        int ans;
        int T;
        T=in.nextInt();
        while(T-->0){
            str=in.next();
            A=str.toCharArray();
            str=in.next();
            B=str.toCharArray();
            for(int i=0;i<A.length;++i){
                if(cmp(A, A, i+1)) aa[i]='1';
                else aa[i]='0';
                if(cmp(A, B, i+1)) ab[i]='1';
                else ab[i]='0';
            }
            for(int i=0;i<B.length;++i){
                if(cmp(B, B, i+1)) bb[i]='1';
                else bb[i]='0';
                if(cmp(B, A, i+1)) ba[i]='1';
                else ba[i]='0';
            }
            AA=toBigInt(aa,A.length);
            BB=toBigInt(bb,B.length);
            AB=toBigInt(ab,A.length);
            BA=toBigInt(ba,B.length);
            /*System.out.println(AA);
            System.out.println(AB);
            System.out.println(BB);
            System.out.println(BA);*/
            ans=BB.subtract(BA).compareTo(AA.subtract(AB));
            if(ans==0) System.out.println("Fair");
            else if(ans>0) System.out.println("A");
            else System.out.println("B");
        }
    }
}
/*
1
10110
01011
*/
