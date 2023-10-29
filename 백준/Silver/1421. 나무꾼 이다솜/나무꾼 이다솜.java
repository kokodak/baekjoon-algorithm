import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();
        int w = sc.nextInt();
        int[] arr = new int[51];
        int max = (int) -2e9;
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            arr[i] = num;
            max = Math.max(max, arr[i]);
        }
        long ans = -Long.MAX_VALUE;
        for (int i = 1; i <= max; i++) {
            long summ = 0;
            for (int j = 0; j < n; j++) {
                if (i > arr[j]) continue;
                int cnt = arr[j] / i;
                int ccnt;
                if (arr[j] % i != 0) {
                    ccnt = cnt;
                }
                else {
                    ccnt = cnt - 1;
                }
                long aaa = (long) cnt * i * w - ((long) ccnt * c);
                if (aaa >= 0) summ += aaa;
            }
            ans = Math.max(ans, summ);
        }
        System.out.println(ans);
    }
}
