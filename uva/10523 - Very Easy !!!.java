
import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        BigInteger a,t;
        int i,n;
        while(scan.hasNext()){
            n=scan.nextInt();
            a=scan.nextBigInteger();
            t=BigInteger.ZERO;
            for(i=1;i<=n;i++)
                t=t.add(a.pow(i).multiply(BigInteger.valueOf(i)));
            System.out.println(t);
        }
    }
}