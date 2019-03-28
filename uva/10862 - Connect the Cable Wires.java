
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        BigInteger[] f = new BigInteger[4002];
        int i;
        f[0] = new BigInteger("1");
        f[1] = new BigInteger("1");
        for(i=2;i<=4001;i++)
            f[i]=f[i-1].add(f[i-2]);
        while(true)
        {
            i=scan.nextInt();
            if(i==0)
                break;
            i=2*i-1;
            System.out.println(f[i]);
        }
    }

}
