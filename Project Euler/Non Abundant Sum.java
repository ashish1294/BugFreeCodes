package numbertheory;

import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.Collections;

import numbertheory.AmicablePairs.PollardRho;

public class NonAbundantSum {

	static class PollardRho {
	    private final static BigInteger ZERO = new BigInteger("0");
	    private final static BigInteger ONE  = new BigInteger("1");
	    private final static BigInteger TWO  = new BigInteger("2");
	    private final static SecureRandom random = new SecureRandom();

	    public static BigInteger rho(BigInteger N) {
	        BigInteger divisor;
	        BigInteger c  = new BigInteger(N.bitLength(), random);
	        BigInteger x  = new BigInteger(N.bitLength(), random);
	        BigInteger xx = x;

	        // check divisibility by 2
	        if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;

	        do {
	            x  =  x.multiply(x).mod(N).add(c).mod(N);
	            xx = xx.multiply(xx).mod(N).add(c).mod(N);
	            xx = xx.multiply(xx).mod(N).add(c).mod(N);
	            divisor = x.subtract(xx).gcd(N);
	        } while((divisor.compareTo(ONE)) == 0);

	        return divisor;
	    }

	    public static void factor(BigInteger N) {
	        if (N.compareTo(ONE) == 0) return;
	        if (N.isProbablePrime(10)) { list.add(N.longValue()); return; }
	        BigInteger divisor = rho(N);
	        factor(divisor);
	        factor(N.divide(divisor));
	    }
	}
	public static ArrayList<Long> list = new ArrayList<Long>();
	/**
	 * @param args
	 */
	static Long sumofdivisors(Long N)
	{
		list.clear();
		PollardRho.factor(BigInteger.valueOf(N));
		Long sum = 1l;
		Collections.sort(list);
		//System.out.println(list);
		while(list.size()>0)
		{
			Long POW=1L;
			Long tempsum=1L;
			while(list.size()>1 && list.get(0).equals(list.get(1)))
			{
				POW *= list.get(0);
				tempsum += POW;
				list.remove(1);
			}
			tempsum += POW*list.get(0);
			sum = sum*tempsum;
			list.remove(0);
		}
		sum = sum-N;
		return sum;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Integer> anums = new ArrayList<Integer>();
		boolean[] arr= new boolean[28125];
		for(long i=12;i<=28123l;i++)
		{
			long sum = sumofdivisors(i);
			if(sum>i) anums.add((int) i);
		}
		for(int i=0;i<28125;i++)
			arr[i]=true;
		for(int j=0;j<anums.size();j++)
		{
			for(int k=0;k<anums.size();k++)
			{
				if(anums.get(k)+anums.get(j)<=28123)
					arr[anums.get(k)+anums.get(j)]=false;
			}
		}
		long sum =0;
		for(int i=0;i<28123;i++)
			if(arr[i])
				sum+=i;
		System.out.println(sum);
	}

}
