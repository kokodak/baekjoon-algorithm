import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        final String s = sc.nextLine();
        if (s.length() == 0) {
            System.out.println(0);
            return;
        }
        int idx = 0;
        int wcnt = 0;
        int ocnt = 0;
        int lcnt = 0;
        int fcnt = 0;
        boolean ok = false;
        for (int i = 0; i < s.length(); i++) {
            if (idx == 0) {
                if (s.charAt(i) == 'w') wcnt++;
                else {
                    idx++;
                    i--;
                }
            }
            else if (idx == 1) {
                if (s.charAt(i) == 'o') ocnt++;
                else {
                    if (ocnt != wcnt) {
                        ok = false;
                        break;
                    }
                    else {
                        idx++;
                        i--;
                        ocnt = 0;
                    }
                }
            }
            else if (idx == 2) {
                if (s.charAt(i) == 'l') lcnt++;
                else {
                    if (lcnt != wcnt) {
                        ok = false;
                        break;
                    }
                    else {
                        idx++;
                        i--;
                        lcnt = 0;
                    }
                }
            }
            else {
                if (s.charAt(i) == 'f') fcnt++;
                if (i == s.length() - 1 && s.charAt(i) == 'f') {
                    if (fcnt == wcnt) {
                        ok = true;
                        break;
                    }
                    else {
                        ok = false;
                        break;
                    }
                }
                else {
                    if (s.charAt(i) != 'f') {
                        if (fcnt != wcnt) {
                            ok = false;
                            break;
                        }
                        else {
                            idx = 0;
                            i--;
                            fcnt = 0;
                            wcnt = 0;
                        }
                    }
                }
            }
        }
        if (ok) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }
}
