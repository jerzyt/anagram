import java.io.*;
import java.util.*;

public class anagram
	{
	public static void main(String[] args)
		{
		try
			{
			HashMap m = new HashMap();
			BufferedReader in = new BufferedReader(new FileReader("words"));
			String word = new String();

			while((word = in.readLine()) != null)
				{
				char wChars[] = word.toCharArray();
				Arrays.sort(wChars);
				String key = new String(wChars);

				if(m.containsKey(key))
					{
					ArrayList aLst = (ArrayList)m.get(key);
					aLst.add(word);
					}
				else
					{
					ArrayList aLst = new ArrayList();
					aLst.add(word);
					m.put(key, aLst);
					}
				}

			in.close();

			printAnagrams(m);
			}
		catch(FileNotFoundException e)
			{
			System.out.println(e.getMessage());
			}
		catch(IOException e)
			{
			System.out.println(e.getMessage());
			}
			
		}

	private static void printAnagrams(Map m)
		{
		Collection entries = m.entrySet();
		Iterator it = entries.iterator();

		while(it.hasNext())
			{
			Map.Entry e = (Map.Entry)it.next();
			ArrayList aLst = (ArrayList)e.getValue();
			int anagCnt = aLst.size();

			if(anagCnt > 3)
				{
				String key = (String)e.getKey();

				System.out.print(key + "\t=>\t");
				for(int i = 0; i < anagCnt; ++i)
					{
					System.out.print(" " + (String)aLst.get(i));
					}
				System.out.println();
				}
			}
		}
	}

