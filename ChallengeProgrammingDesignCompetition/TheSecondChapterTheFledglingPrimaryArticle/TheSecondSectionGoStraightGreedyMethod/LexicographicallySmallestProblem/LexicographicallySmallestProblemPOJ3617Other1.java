//我想说的话，程序写得太漂亮了，太棒了，我猜你肯定在美国的一所中学或者大学学习程序！把程序写的如此规范，令我叹服！
/*
   Poj 3617  #95
Date: 12/13/2014
4144K	1829MS
 */

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n = cin.nextInt();
		char a[] = new char[n+1];
		for (int i = 1; i <= n; i++) {
			a[i] = cin.next().charAt(0);
		}
		int head = 1, tail = n;
		for (int i = 1; i <= n; i++) {
			if (a[head] < a[tail]) {
				System.out.print(a[head]);
				head ++;
			}
			else if (a[head] > a[tail]) {
				System.out.print(a[tail]);
				tail --;
			}
			else if (head == tail) {
				System.out.print(a[head]);
			}
			else {
				boolean chk = true;
				for (int j = 1; j <= (n-i-1)/2; j++) {
					//对需要两个ｂｒｅａｋ！
					if (a[head+j] < a[tail-j]) {
						chk = true;
						break;
					}
					else if (a[head+j] > a[tail-j]) {
						chk = false;
						break;
					}
				}
				if (chk) {
					System.out.print(a[head]);
					head ++;
				}
				else {
					System.out.print(a[tail]);
					tail --;
				}
			}
			if (i % 80 == 0) {
				System.out.printf("\n");
			}
		}
	}
}


