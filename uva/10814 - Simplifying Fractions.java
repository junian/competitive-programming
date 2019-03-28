
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BigInteger a,b,c;
        int n;
        n=scan.nextInt();
        while(n-->0)
        {
            a=scan.nextBigInteger();
            scan.next();
            b=scan.nextBigInteger();
            c=a.gcd(b);
            System.out.println(a.divide(c) + " / " + b.divide(c));
        }
    }

}
