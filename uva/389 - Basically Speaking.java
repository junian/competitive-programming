
//import java.math.BigInteger;
import java.util.Scanner;


public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        //BigInteger a;
        Integer a;
        String s;
        int c,d;
        while(scan.hasNext()){
            s=scan.next();
            c=scan.nextInt();
            d=scan.nextInt();
            a=Integer.parseInt(s, c);
            //a=new BigInteger(s, c);
            s=Integer.toString(a, d);
            if(s.length()>7)
                System.out.printf("%7s\n", "ERROR");
            else
                System.out.printf("%7s\n", s.toUpperCase());
        }
    }
}