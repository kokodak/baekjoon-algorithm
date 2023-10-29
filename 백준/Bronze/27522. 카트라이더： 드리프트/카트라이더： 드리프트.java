import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

    static class A {
        String time;
        char team;

        public A(final String time, final char team) {
            this.time = time;
            this.team = team;
        }
    }

    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        A[] arr = new A[8];
        for (int i = 0; i < 8; i++) {
            final String time = sc.next();
            final char team = sc.next().charAt(0);
            arr[i] = new A(time, team);
        }
        Arrays.sort(arr, (a1, a2) -> a1.time.compareTo(a2.time));
        int bscore = 0;
        int rscore = 0;
        int[] score = {10, 8, 6, 5, 4, 3, 2, 1, 0};
        for (int i = 0; i < 8; i++) {
            if (arr[i].team == 'R') {
                rscore += score[i];
            }
            else {
                bscore += score[i];
            }
        }
        if (bscore > rscore) {
            System.out.println("Blue");
        }
        else {
            System.out.println("Red");
        }
    }
}
