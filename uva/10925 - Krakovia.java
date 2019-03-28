import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BigInteger a,b = null,c;
        int i=0,j;
        while(true)
        {
            i++;
            j=scan.nextInt();
            a=scan.nextBigInteger();
            if(j==0 && a.compareTo(BigInteger.ZERO)==0)
                break;
            b=BigInteger.ZERO;
            while(j-->0)
            {
                c=scan.nextBigInteger();
                b=b.add(c);
            }
            System.out.println("Bill #" + i + " costs " + b + ": each friend should pay " + b.divide(a));
            System.out.println();
        }
    }

}
