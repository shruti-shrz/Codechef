import javax.swing.*;
import javax.swing.text.BadLocationException;
public class Main {
	int r;
	Main(int k)
	{
		r =k;
	}
	
	public static int check(int r)
	{
		if(r==0)
			return 1;
		if(r==1)
			return 1;
		
	}
	public static void main(String[] args) {
        BufferedReader file;
        try {
            check(2);

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
	}