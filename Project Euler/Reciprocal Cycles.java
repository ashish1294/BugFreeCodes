public class ReciprocalCycles {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int max=0,maxin=0;
		for(int d=999;d>=7;d--)
		{
			ArrayList<Integer> rems = new ArrayList<Integer>();
			rems.clear();
			int r =1;
			int length=0;
			boolean flag=true;
			while(flag)
			{
				for(int j=0;j<rems.size();j++)
				{
					if(rems.get(j).equals(r))
					{
						flag=false;
						length=rems.size()-j;
						break;
					}
				}
				if(flag)
				{
					rems.add(r);
					r = (r*10)%d;
				}
			}
			if(length>max) {max=length;maxin=d;}
			if(length==d-1) break;
		}
		System.out.println("Max Lenght is for d="+maxin+" with lenght="+max);
	}

}
