import java.util.*;
import java.util.Collections;
class Tools{
	public static void main(String[] args){
		//�������
		/*Scanner in=new Scanner(System.in);
		String str1;
		str1=in.next();
		in.nextLine();	//Ϊ�˷���ʹ��nextLine()
		System.out.print(str1+"\n");
		
		String str2;
		str2=in.nextLine();
		System.out.print(str2+"\n");
		
		int num1;
		num1=in.nextInt();
		in.nextLine();
		System.out.print(num1+"\n");
		System.out.printf("%d\n",num1);
		
		double num2;
		num2=in.nextDouble();
		in.nextLine();
		System.out.print(num2+"\n");
		System.out.printf("%.2f\n",num2);*/
		
		//�ַ���
		/*String str1="Hello world!";
		//��ȡ�ַ���
		String str2=str1.substring(0,3);	//0<=i<3
		System.out.print(str2+"\n");
		//�ַ���ƴ��
		str2=str1+"yes";
		System.out.print(str2+"\n");
		//�滻�ַ���
		str2=str1.replace("Hel","hehe");
		System.out.print(str2+"\n");
		//������λ�滻��'k'
		str2=str1.substring(0,3)+"k"+str1.substring(4,str1.length());
		System.out.print(str2+"\n");
		//ȥ����β�ո�
		str2="   hehe   ".trim();
		System.out.print(str2+"\n");
		//ת��ΪСд
		str2="ASASFSD".toLowerCase();
		System.out.print(str2+"\n");
		//ת��Ϊ��д
		str2=str2.toUpperCase();
		System.out.print(str2+"\n");
		//��ȡһ���ַ�
		char ch=str1.charAt(0);
		System.out.print(ch+"\n");
		//bytes
		byte[] b=str1.getBytes();
		System.out.print(b+"\n");
		for(int i=0;i<b.length;++i){
			System.out.print(b[i]+" ");
		}
		System.out.print("\n");
		//�ַ���ת�ַ�����
		char[] str3=str1.toCharArray();
		System.out.print(str3.toString()+"\n");
		for(int i=0;i<str3.length;++i){
			System.out.print(str3[i]+" ");
		}
		System.out.print("\n");
		//�ַ����ȽϺ���
		if(!str1.equals("111")){
			System.out.print("��һ��\n");
		}
		if(str1.compareTo("AAA")>0){
			System.out.print("��***��\n");	//<0 ==0
		}
		//�Ƿ����ض��ַ���ʼ  
        if(str1.startsWith("Hello")){
        	System.out.print("��Hello��ͷ\n");  
        }
        //�Ƿ����ض��ַ���β  
        if(str1.endsWith("world!")){
        	System.out.print("��world!��β\n");  
        }
		//�����ַ�������λ��
        int pos=str1.indexOf("wor");
        System.out.print(pos+"\n");	//ֻ����ֵĵ�һ��λ��
        //����ַ����Ƿ�Ϊ�� null�� ""
        str2="";
        if(str2.isEmpty()){
        	System.out.print("��\n");
        }*/
		
		//����
		//��������
		Scanner in=new Scanner(System.in);
		Integer[] a=new Integer[10];
		for(int i=0;i<a.length;++i){
			a[i]=in.nextInt();
		}
		Arrays.sort(a);	//ֻ��Object��Ч
		for(int i=0;i<a.length;++i){
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		Arrays.sort(a,Collections.reverseOrder());
		for(int i=0;i<a.length;++i){
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		//�ṹ������
		Scanner in=new Scanner(System.in);
		Data[] a=new Data[10];
		for(int i=0;i<a.length;++i){
			a[i]=new Data();
			a[i].a=in.nextInt();
			a[i].b=i;
		}
		Comparator<Data> cmp=new Comparator<Data>(){	//����һ
			public int compare(Data a,Data b){
				return a.a-b.a;
			}
		};
		Arrays.sort(a,cmp);	//ֻ��Object��Ч
		for(int i=0;i<a.length;++i){
			System.out.print(a[i].a+" ");
		}
		System.out.print("\n");
		//����������
		Double[] a={1.1,1.2,2.4,1.9,10.1,5.5,4.4};
		Arrays.sort(a);
		for(int i=0;i<a.length;++i){
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		Arrays.sort(a,Collections.reverseOrder());
		for(int i=0;i<a.length;++i){
			System.out.print(a[i]+" ");
		}
		System.out.print("\n");
		
		//����С����
		/*List tmp,list=new ArrayList();
		Integer[] a={1,2,3,4,5};
		for(int i=0; i<a.length;++i)
			list.add(new Integer(a[i]));
		System.out.print(Collections.min(list)+"\n");
		System.out.print(Collections.max(list)+"\n");
		//Collections.copy(tmp,list);*/
		
		//����
		/*Queue<Integer> q=new LinkedList<Integer>();
		for(int i=0;i<10;++i){
			q.offer(i);	//���
		}
		System.out.println(q.peek()); //��ͷ
		while(!q.isEmpty()){
			System.out.println(q.poll());	//����
		}*/
		
		//���ȶ���
		/*PriorityQueue<Integer> pq=new PriorityQueue<Integer>();
		pq.add(5);
		pq.add(4);
		pq.add(8);
		pq.add(10);
		while(!pq.isEmpty()){
			System.out.println(pq.poll());
		}*/
		Comparator<Integer> cmp=new Comparator<Integer>(){	//����һ
			public int compare(Integer a,Integer b){
				return b-a;
			}
		};
		PriorityQueue<Integer> pq=new PriorityQueue<Integer>(10000000,cmp);
		pq.add(5);
		pq.add(4);
		pq.add(8);
		pq.add(10);
		while(!pq.isEmpty()){
			System.out.println(pq.poll());
		}
	}
}
class Data{
	int a,b;
}
/*class Mycomparator implements Comparator{	//������
	public int compare(Object o1,Object o2){
		Data a=(Data)o1;
		Data b=(Data)o2;
		return	a.a-b.a;//����
		//a<b return -1;
		//a==b return 0;
		//a>b return 1;
	}
}*/
