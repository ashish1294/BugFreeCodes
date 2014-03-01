import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		while(true)
		{
			Long a = sc.nextLong();
			if(a==-1) break;
			char[] arr = Long.toBinaryString(a).toCharArray();
			int len = arr.length/2;
			for(int i=0;i<len;i++) {char temp=arr[i];arr[i]=arr[arr.length-i-1];arr[arr.length-i-1]=temp;}
			System.out.println(Long.parseLong(new String(arr),2));
		}
		sc.close();
	}
}