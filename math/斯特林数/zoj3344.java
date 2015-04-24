/*zoj 3344 Card Game
  ���⣺
  ��n��д������(���ַ�ΧΪ1~n,�һ�����ͬ)�Ŀ�Ƭ����˳��Ȼ��ŵ����Ϊ1~n�ĺ����ÿ�ֽ��еĶ������£��ȴ�ʣ��ı����С�ĺ�����ȡ����Ƭ���迨Ƭд��k�������k�����ӻ�û�б��򿪹���������򿪵�k�����ӣ�ȡ����Ƭ...ֱ��û�к��ӿ��Ա��򿪡�ȡ�����һ�����ӵ�Ϊʤ���ߡ�
  EZ��֪������m��֮����Ӯ����Ϸ�ĸ��ʡ�
  ���ƣ�
  1 <= n <= 50; 1 <= k <= n
  ˼·��
  ��һ��˹��������EZֻ���ڷֲ�ķ���λ�����ҷ���С��m��ʱ�����ʤ���ġ�
  n=50��Ҫ��java������
 */
import java.math.BigInteger;
import java.security.GuardedObject;
import java.util.*;
public class Main{
	static BigInteger[][] sti=new BigInteger[55][55];
	static void get_sti(int n){
		for(int i=1;i<=n;++i){
			sti[i][0]=BigInteger.ZERO;
			sti[i][i]=BigInteger.ONE;
		}
		for(int i=2;i<=n;++i){
			for(int j=1;j<i;++j){
				sti[i][j]=BigInteger.valueOf(i-1).multiply(sti[i-1][j]).add(sti[i-1][j-1]);
			}
		}
	}
	static void print(int n){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=i;++j){
				System.out.print(sti[i][j]+" ");
			}
			System.out.println("");
		}
	}
	static void gao(int n,int k){
		BigInteger fz,fm,d;
		fz=fm=BigInteger.ZERO;
		for(int i=1;i<=n;++i){
			if(i%2==1 && i<=k)
				fz=fz.add(sti[n][i]);
			fm=fm.add(sti[n][i]);
		}
		d=fz.gcd(fm);
		System.out.println(fz.divide(d)+"/"+fm.divide(d));
	}
	public static void main(String args[]){
		get_sti(50);
		Scanner in=new Scanner(System.in);
		int n,k;
		while(in.hasNext()){
			n=in.nextInt();
			k=in.nextInt();
			gao(n,k);
		}
	}
}
