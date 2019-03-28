
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        BigInteger a;
        BigInteger t = new BigInteger("2");
        while(scan.hasNext())
        {
            a = scan.nextBigInteger();
            if(a.compareTo(BigInteger.valueOf(1))==0)
                System.out.println(1);
            else
                System.out.println(a.multiply(t).subtract(t));
        }
    }

}
