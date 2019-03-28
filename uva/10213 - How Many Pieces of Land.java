
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        BigInteger n;
        BigInteger s=new BigInteger("-6");
        BigInteger dt=new BigInteger("23");
        BigInteger db=new BigInteger("-18");
        BigInteger de=new BigInteger("24");
        int t;
        t=scan.nextInt();
        while(t-->0){
            n = scan.nextBigInteger();
            System.out.println(n.pow(4).add(n.pow(3).multiply(s).add(n.pow(2).multiply(dt).add(n.multiply(db).add(de)))).divide(de));
        }
    }

}
