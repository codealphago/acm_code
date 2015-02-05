/*hdu3723
  ���⣺
  ��ǰn��Ĭ�Ƚ�����mod(10^100)
  ���ƣ�
  0 <= n <= 10000
  ˼·��
  Ĭ�Ƚ���
  1, 2, 4, 9, 21, 51, 127, 323, 835, 2188, 5798, 15511, 41835, 113634, 310572, 853467, 2356779, 6536382, 18199284, 50852019, 142547559, 400763223, 1129760415, 3192727797, 9043402501, 25669818476, 73007772802, 208023278209, 593742784829
  ʽ�ӣ�
  M[n+1] = M[n] + ( M[0]*M[n-1] + M[1]*M[n-2] + ... + M[n-1]M[0] )
		 = ( (2n+3)*M[n] + 3n*M[n-1] ) / ( n+3 )
  Ĭ�Ƚ����뿨��������
  M[n]=for(int i=0;i<=floor(n/2);++i){
			+C(n,2i)Catalan(i)	
	   }
  Ӧ�ã�
  1.һ������������Ĭ�Ƚ�������һ��Բ�ϵĸ���䣬�����˴˲��ཻ�ҵ�ȫ������������������Ϊ4ʱ��������Ϊ9
  2.��һ�������ϣ����޶�ÿ��ֻ�������ƶ�һ�񣬿������ϣ����£����ң�����ֹ�ƶ���y=0���µĵط������������߷��ƶ�n����(0,0)��(n,0)�Ŀ����γɵ�·��������
 */
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {
	static final int N = 10005;
	static final BigInteger MOD = BigInteger.valueOf(10).pow(100);
	static BigInteger[] ans = new BigInteger[N];

	static void predo() {
		ans[1] = BigInteger.ONE;
		ans[2] = BigInteger.valueOf(2);
		for (int i = 3; i < N; ++i) {
			BigInteger a = ans[i - 1].multiply(BigInteger.valueOf(2)
					.multiply(BigInteger.valueOf(i)).add(BigInteger.ONE));
			BigInteger b = ans[i - 2].multiply(BigInteger.valueOf(3).multiply(
					BigInteger.valueOf(i - 1)));
			ans[i] = a.add(b).divide(
					BigInteger.valueOf(i).add(BigInteger.valueOf(2)));
		}
	}

	public static void main(String[] args) {
		predo();
		Scanner in = new Scanner(System.in);
		int n;
		while (in.hasNext()) {
			n = in.nextInt();
			System.out.println(ans[n].mod(MOD));
		}
	}
}
