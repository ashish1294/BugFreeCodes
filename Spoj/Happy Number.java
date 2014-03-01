import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
	static Integer sumdig(Integer a)
	{
		int sum=0,dig;
		while(a>0)
		{
			dig=a%10;
			sum+=(dig*dig);
			a /= 10;
		}
		return sum;
	}
	
	static int search(ArrayList<Integer> list,Integer key)
	{
		for(int i=0;i<list.size();i++)
		{
			if(list.get(i).equals(key))
				return i;
		}
		return -1;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		while(true)
		{
			StringTokenizer st = new StringTokenizer(bf.readLine()," ");
			Integer a = Integer.parseInt(st.nextToken());
			Integer b = Integer.parseInt(st.nextToken());
			if(a==0 && b==0)
				return;
			int c=a,d=b,e=a,f=b;
			ArrayList<Integer> alist = new ArrayList<Integer>();
			ArrayList<Integer> blist = new ArrayList<Integer>();
			int ans=0;
			boolean aflag=true,bflag=true;
			while(true)
			{
				if(aflag)
				{
					int asres=search(blist,a);
					if(asres>=0)
					{
						ans=alist.size() + asres + 2;
						break;
					}
					asres=search(alist,a);
					if(asres>=0)
						aflag=false;
					alist.add(a);
					a=sumdig(a);
				}
				else if(bflag)
				{
					int bsres=search(alist,b);
					if(bsres>=0)
					{
						ans=blist.size() + bsres + 2;
						break;
					}
					bsres=search(blist,b);
					if(bsres>=0)
						bflag=false;
					blist.add(b);
					b = sumdig(b);
				}
				else break;
			}
			int ans1=ans;
			aflag=true;bflag=true;
			a=d;b=c;
			alist.clear();
			blist.clear();
			while(true && ans>0)
			{
				if(aflag)
				{
					int asres=search(blist,a);
					if(asres>=0)
					{
						ans1=alist.size() + asres + 2;
						break;
					}
					asres=search(alist,a);
					if(asres>=0)
						aflag=false;
					alist.add(a);
					a=sumdig(a);
				}
				else if(bflag)
				{
					int bsres=search(alist,b);
					if(bsres>=0)
					{
						ans1=blist.size() + bsres + 2;
						break;
					}
					bsres=search(blist,b);
					if(bsres>=0)
						bflag=false;
					blist.add(b);
					b = sumdig(b);
				}
				else break;
			}
			if(ans1<ans)
				ans=ans1;
			System.out.println(e+" "+f+" "+ans);
		}
	}
}