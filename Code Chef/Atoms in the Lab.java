http://www.codechef.com/CDCRFT14/problems/ATOM
//Author - Ashish Kedia, NITK Surathkal
//@ashish1294
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
	static BigDecimal one=BigDecimal.ONE;
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(bf.readLine());
		//int T = sc.nextInt();
		for(int kk=0;kk<T;kk++)
		{
			StringTokenizer st = new StringTokenizer(bf.readLine());
			Long n = Long.parseLong(st.nextToken());
			BigInteger k1 = new BigInteger(st.nextToken());
			Long m = Long.parseLong(st.nextToken());
			Long xx= m/n;
			BigInteger com=BigInteger.valueOf(xx);
			int tt=0;
			while(k1.pow(tt).compareTo(com)<1)
				tt++;
			if(tt>0)
			{
				tt--;
			}
			System.out.println(tt);
		}
	}	
}
