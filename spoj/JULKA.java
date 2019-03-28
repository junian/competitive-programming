
import java.math.BigInteger;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sainthackr
 */
public class JULKA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        int i;
        BigInteger two = new BigInteger("2");
        BigInteger a;
        BigInteger b;
        BigInteger x;
        for(i=0;i<10;i++)
        {
            a=scan.nextBigInteger();
            b=scan.nextBigInteger();
            x=a.add(b).divide(two);
            System.out.println(x);
            System.out.println(a.subtract(x));
        }
    }

}
