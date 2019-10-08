import java.math.BigInteger;
import java.util.Scanner;

public class Main{
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    BigInteger a,b;
    while (in.hasNext()){
      a = in.nextBigInteger(); b = in.nextBigInteger();
      BigInteger c = a.add(b);
      System.out.println(c);
    }
  }
}