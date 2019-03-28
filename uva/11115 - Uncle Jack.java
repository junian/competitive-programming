
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        int x,y;
        while(true)
        {
            x=scan.nextInt();
            y=scan.nextInt();
            if(x<=0 && y<=0)
                break;
            System.out.println(BigInteger.valueOf(x).pow(y));
        }
    }

}
