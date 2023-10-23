import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

  static int atoi(String str) {
    return Integer.parseInt(str);
  }
  static boolean[] visit;
  static int[] visited;
  static String s;
  static char[] select;
  static char[] A;
  static Set<String> answer = new HashSet<>();
  static int length;
  static int answer2;

  static char[] arr;

  public static void main(String[] args) throws IOException {
    input();
    pro();
  }

  static void pro() {
    dfs(0);
    System.out.println(answer2);
  }

  static void dfs(int idx) {
    if (idx == length) {
      answer2++;
      return;
    }

    for (int i = 0; i < 30; i++) {
      if (visited[i] == 0) continue;
      if (arr[idx] == (char)('a' + i)) continue;

      visited[i]--;
      arr[idx + 1] = (char)('a' + i);
      dfs(idx + 1);
      arr[idx + 1] = 'Z';
      visited[i]++;
    }
  }

  static void input() throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    s = br.readLine();

    A = new char[s.length()];
    visit = new boolean[s.length()];
    visited = new int[30];
    arr = new char[11];
    for (int i = 0; i < 11; i++) arr[i] = 'Z';
    length = s.length();

    for (int i = 0; i < s.length(); i++) {
      A[i] = s.charAt(i);
      visited[A[i] - 'a']++;
    }
  }
}