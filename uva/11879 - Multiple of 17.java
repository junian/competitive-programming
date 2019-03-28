
import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        BigInteger a,c;
        while(true){
            a=scan.nextBigInteger();
            if(a.compareTo(BigInteger.ZERO)==0)
                break;
            c=a.mod(BigInteger.valueOf(10)).multiply(BigInteger.valueOf(5));
            a=a.divide(BigInteger.valueOf(10));
            a=a.subtract(c).abs();
            if(a.mod(BigInteger.valueOf(17)).compareTo(BigInteger.ZERO)==0)
                System.out.println("1");
            else
                System.out.println("0");
        }       
    }
}