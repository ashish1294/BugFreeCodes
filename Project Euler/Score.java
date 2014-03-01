import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

class comp implements Comparator<String>
{
	@Override
	public int compare(String arg0, String arg1) {
		// TODO Auto-generated method stub
		return arg0.compareTo(arg1);
	}	
}
public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine(),",");
		ArrayList<String> names = new ArrayList<String>();
		while(st.hasMoreTokens())
		{
			String temp = st.nextToken();
			temp = temp.substring(1, temp.length()-1);
			names.add(temp);
		}
		System.out.println("Size =" + names.size());
		Collections.sort(names,new comp());
		long score=0;
		for(int i=0;i<names.size();i++)
		{
			int sc=names.get(i).length();
			for(int j=0;j<names.get(i).length();j++)
			{
				sc += (int)(names.get(i).charAt(j) -'A');
			}
			score += sc*(i+1);
		}
		System.out.println(score);
	}

}
