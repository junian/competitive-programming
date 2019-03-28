
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        BigInteger[] f = new BigInteger[1001];
        int i;
        f[0] = new BigInteger("1");
        f[1] = new BigInteger("2");
        for(i=2;i<=1000;i++)
            f[i]=f[i-1].add(f[i-2]);
        while(scan.hasNext())
        {
            i=scan.nextInt();
            System.out.println(f[i]);
        }
    }

}
