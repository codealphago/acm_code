//���⣺
//��һ���ַ���str�����г���Ϊn���Ӵ�������ԭ���Ĳ�ͬ�ַ�����Ϊnc���������ö���ҳ����е��Ӵ����������ɣ�������Ҫ���أ�����:
import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		Set<String> h=new HashSet<String>();
		int i,n,nc,len;
		String s,tmp;
		n=in.nextInt();
		nc=in.nextInt();
		s=in.next();
		len=s.length();
		for(i=0;i<=len-n;++i){
			tmp=s.substring(i,i+n);
			h.add(tmp);
		}
        System.out.println(h.size());
		/*Iterator it=h.iterator();	//�������
        while(it.hasNext()){
            System.out.println(it.next());
        }*/
	}
}
