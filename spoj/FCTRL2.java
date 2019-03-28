import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author sainthackr
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
	BigInteger[] a = new BigInteger[101];
	a[0] = new BigInteger("1");
	Integer i;
	int t, n;
	for(i=1; i<=100; i++)
        {
            a[i] = a[i-1].multiply(new BigInteger(i.toString()));
        }
        t = scan.nextInt();
        while(t>0)
        {
            t--;
            n = scan.nextInt();
            System.out.println(a[n].toString());
        }
    }

}
