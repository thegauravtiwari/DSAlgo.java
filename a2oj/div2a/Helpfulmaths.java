package a2oj.div2a;
import java.util.*;
import java.io.*;
public class Helpfulmaths {

	public static void main(String[] args) {
		InputReader s=new InputReader(System.in);
		PrintWriter w=new PrintWriter(System.out);
		
		String str=s.readString();
		int count1=0,count2=0,count3=0;
		for(int i=0;i<str.length();i+=2)
		{
			char ch=str.charAt(i);
			if(ch=='1')
			{
				count1++;
			}
			else if(ch=='2')
			{
				count2++;
			}
			else
				count3++;
		}
		StringBuilder ans=new StringBuilder("");
		if(count1!=0)
		{
			ans.append(1);
			count1--;
		}
		else if(count2!=0)
		{
			ans.append(2);
			count2--;
		}
		else if(count3!=0)
		{
			ans.append(3);
			count3--;
		}
		
		for(int i=0;i<count1;i++)
		{
			ans.append('+');
			ans.append(1);
		}
		
		for(int i=0;i<count2;i++)
		{
			ans.append('+');
			ans.append(2);
		}
		
		for(int i=0;i<count3;i++)
		{
			ans.append('+');
			ans.append(3);
		}
		w.println(ans.toString());
		w.close();
	}
	static class InputReader {

		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public double nextDouble() //read double
		{
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			double res = 0;
			boolean dec = false;
			int count = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				if (dec)
					count--;
				res *= 10;
				res += c - '0';
				c = snext();
				if (c == '.') {
					if (!dec) {
						dec = true;
						c = snext();
					} else {
						throw new InputMismatchException();
					}
				}
			} while (!isSpaceChar(c));
			res *= Math.pow(10, count);
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public String nextLine() { //considers space in same string
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}
