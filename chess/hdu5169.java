/*hdu 5169 Flipping coins
  ���⣺
  СA��СB����һ����Ϸ������һ��ʼÿ�����϶���һ��01�ַ��������м�СA���ϵ�ΪA����СB���ϵ�ΪB����
  ������һö���ȵ�Ӳ�ң��Լ�һ�����ַ���S����Ϸ��ʼ��ÿһ�غ϶���Ͷ����öӲ�ң�����������ϣ�����S�������һ���ַ�'1'���������һ���ַ�'0'��
  һ��ĳһ�غϽ���ʱA����Ϊ��S���Ӵ���СA��Ӯ�ˣ�ͬ�����B����Ϊ��S���Ӵ���СB��Ӯ�ˣ���һ���˻��ʤ��ʱ��Ϸ������Ϊ�˱���������ͬʱʤ�����������֤A��ΪB�ĺ�׺��BҲ��ΪA�ĺ�׺��
  ����֪A��B������£������Ϸ�ǲ��ǹ�ƽ���أ���ƽ��ζ��СA��СBӵ����ͬ��ʤ�ʣ�������ƽ˭���п���Ӯ��
  ���ƣ�
  1 <= |A|,|B| <= 100
  ˼·��
  ��Ϊ������С��ֻ��100������Penney��s game�Ľ��ۣ�����ֱ�ӱ�������Ҳ������kmp���Ż���

  kmp�Ż���ʽ���£�
  �����ģʽ����next���飬���ϵغ�ĸ�������һλƥ�䣬��¼����ƥ��ĳ��ȼ��ɡ�

  Penney��s game�Ľ��ۣ����£�
  ���� a �� b ������ n λ 01 ������� a �� b ��ȫ��ȣ���ô��һ������ 1 ���������ȣ���ô��һ������ 0 �����������Ƚ� a �ĺ��� n �C 1 λ�Լ� b ��ǰ�� n �C 1 λ�������ȣ���ô���ż�һ������ 1 ���������ȣ���ô���ż�һ������ 0 �����������Ƚ� a �ĺ� n �C 2 λ�Լ� b ��ǰ n �C 2 λ�������ݱȽϽ���������� 0 �������� 1 ��������������ȥ��ֱ�����Ƚ� a ������� 1 λ�� b ����ǰ�� 1 λ���������µ����֡������������У�������μ��� n �����֣����ջ�õ�һ�� n λ�� 01 ������������һ��������������ת����ʮ���ơ����ǰ����յĽ����Ϊ L(a, b) ���ټ������ӣ�
  L(10110, 10110) = (10010)2 = 18
  L(10110, 01011) = (00001)2 = 1
  L(01011, 01011) = (10000)2 = 16
  L(01011, 10110) = (01001)2 = 9
  ��ô�� 01 �� a �� b ��ʤ��֮�Ⱦ���
  (L(b, b) �C L(b, a)) : (L(a, a) �C L(a, b))
 */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static final int N = 105;
	static int[] next=new int[N];
	static void getNext(char[] T){
		int i,j;
		i=0;
		j=next[0]=-1;
		while(i<T.length){
			if(j==-1 || T[i]==T[j]) next[++i]=++j;
			else j=next[j];
		}
	}
	static void deal(char[] S,char[] T,char[] res){
		for(int i=0;i<S.length;++i) res[i]=0;
		int i=0,j=0;
		if(S.length>=T.length) i+=S.length-T.length;
		else j+=T.length-S.length;
		getNext(T);
		while(i<S.length){
			if(j==-1 || S[i]==T[j]){
				++i; ++j;
				if(i==S.length && j!=0){
					res[j-1]=1;
					--i;
					j=next[j-1];
				}
			}
			else j=next[j];
		}
	}
	static BigInteger toBigInt(char a[],int len){
		BigInteger ret=BigInteger.ZERO;
		for(int i=len-1;i>=0;--i)
			ret=ret.multiply(BigInteger.valueOf(2)).add(BigInteger.valueOf(a[i]));
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
			deal(A, A, aa);
			deal(B, B, bb);
			deal(A, B, ab);
			deal(B, A, ba);
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
