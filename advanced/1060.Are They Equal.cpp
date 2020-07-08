import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), expo1 = 0, expo2 = 0; 
		BigDecimal b1 = sc.nextBigDecimal();
		BigDecimal b2 = sc.nextBigDecimal();
		BigDecimal num = new BigDecimal("1");
		BigDecimal num2 = new BigDecimal("0.1");
		BigDecimal num3 = new BigDecimal("0");
		BigDecimal ten = new BigDecimal("10");
		while(b1.compareTo(num) > 0) {
			b1 = b1.divide(ten);
			expo1++;
		}
		while(b1.compareTo(num2) < 0 && b1.compareTo(num3) > 0) {
			b1 = b1.multiply(ten);
			expo1--;
		}
		while(b2.compareTo(num) > 0) {
			b2 = b2.divide(ten);
			expo2++;
		}
		while(b2.compareTo(num2) < 0 && b2.compareTo(num3) > 0) {
			b2 = b2.multiply(ten);
			expo2--;
		}
		String s = "";
		for(int i = 0; i < N + 2; i++) s += "0";
		String sub1 = b1.toString(), sub2 = b2.toString();
		if(!b1.toString().contains(".")) sub1 += ".";
		if(!b2.toString().contains(".")) sub2 += ".";
		sub1 = (sub1 + s).substring(0, N + 2);
		sub2 = (sub2 + s).substring(0, N + 2);
		if(expo1 == expo2 && sub1.equals(sub2)) {
			System.out.printf("YES %s*10^%d", sub1, expo1);
		}
		else {
			System.out.printf("NO %s*10^%d %s*10^%d", sub1, expo1, sub2, expo2);
		}
	}
}