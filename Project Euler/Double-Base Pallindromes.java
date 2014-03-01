
//http://projecteuler.net/problem=36
public class Main {
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		Integer i;
		long sum=0;
		for(i=1;i<1000000;i++)
		{
			if(ispal(Integer.toString(i)) && ispal(Integer.toBinaryString(i)))
			{
				System.out.println("Palin = "+i);
				sum+=i;
			}
		}
		System.out.println("Sum of all Double Base Pallindromes :"+sum);
	}
	static boolean ispal(String s)
	{
		int len=s.length();
		int l=len/2;
		for(int i=0;i<=l;i++)
		{
			if(s.charAt(i)!=s.charAt(len-1-i)) return false;
		}
		return true;
	}
}
