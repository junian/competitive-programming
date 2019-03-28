
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BigInteger a = new BigInteger("0");
        BigInteger c;
        while(true)
        {
            c = scan.nextBigInteger();
            if(c.toString()=="0")
                break;
            a=a.add(c);
        }
        System.out.println(a);
    }

}
