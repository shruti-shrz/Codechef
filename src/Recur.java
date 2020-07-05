import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Recur {
    public static boolean recurCheck(BufferedReader file)
    {
        HashMap<String, Integer> table = new HashMap<String, Integer>();
        String line;
        int count =0;
        String ch;
            try {
                while ((line = file.readLine())!=null)
                {
                    line = line.trim();
                    String[] arr = line.split("[ ,]+");
                    for(int i=0;i<arr.length;i++)
                    {

                        //System.out.println(i+" "+arr[i]);
                        arr[i] = arr[i].trim();
                        if(arr[i].length()!=0)
                        if(arr[i].charAt(arr[i].length()-1)=='*')
                        {
                           arr[i] = arr[i].substring(0,arr[i].length()-1);
                        }
                        if(arr[i].indexOf('(')!=-1)
                        {
                            arr[i] = arr[i].substring(0,arr[i].indexOf('('));
                            if(table.containsKey(arr[i]) && table.get(arr[i])==count-1)
                            {System.out.println("yuo");

                                return true;
                            }
                        }
                     if(arr[i].equals("void") || arr[i].equals("int") || arr[i].equals("float") || arr[i].equals("double") || arr[i].equals("char") || arr[i].equals("bool") || arr[i].equals("string"))
                     {
                         //System.out.println("CHECK");
                        if(arr[i+1].indexOf('(')!=-1)
                        {
                            arr[i+1] = arr[i+1].substring(0,arr[i+1].indexOf('('));
                            ch = arr[i+1];
                            table.put(arr[i+1],count);
                            System.out.println(table);
                            count++;
                        }
                     }
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }

           return false;
    }

    public static void main(String[] argv)
    {
        BufferedReader file;
        try {
            String path2 = "C:/Users/Shruti priya/Desktop/work/test.cpp";
            file = new BufferedReader(new FileReader(path2));

            boolean ch = recurCheck(file);
            if(ch == true)
                System.out.println("Yes");
            else
                System.out.println("NO");

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
