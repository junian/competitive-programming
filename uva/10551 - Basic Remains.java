
import java.math.BigInteger;
import java.util.Scanner;


public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        BigInteger a,b;
        int n;
        while(true){
            n=scan.nextInt();
            if(n<=0)
                break;
            a=scan.nextBigInteger(n);
            b=scan.nextBigInteger(n);
            a = a.mod(b);
            System.out.println(a.toString(n));
        }
    }
}