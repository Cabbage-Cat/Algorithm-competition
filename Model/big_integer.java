import java.math.BigInteger;
import java.util.Scanner;

public class Main{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in) ; int x = sc.nextInt();
    System.out.println((int)(Math.log10(2)*x+1));
    BigInteger p = BigInteger.valueOf(x);
    BigInteger m = BigInteger.ONE;
    for (int i=0;i<500;i++) m = m.multiply(BigInteger.TEN);
    BigInteger b = BigInteger.valueOf(2);
    BigInteger res = b.modPow(p, m); res = res.subtract(BigInteger.ONE);
    String ans = res.toString();
    int l = ans.length();
    for (int i=0;i<500-l;i++)
      ans = String.valueOf(0) + ans;
    for (int i=0;i<ans.length();i++){
      if (i!=0 && i%50==0)
        System.out.print('\n');
      System.out.print(ans.charAt(i));
    }
  }
}