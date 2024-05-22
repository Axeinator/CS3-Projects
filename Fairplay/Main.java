import java.util.*;

public class Main {
  public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);

      System.out.println("Enter the text to encrypt:");
      String inputText = scanner.nextLine();

      ArrayList<String> pre = preprocess(inputText);
      char[][] matrix = buildMatrix();

      String encoded = "";
      for (String s : pre) {
          encoded += encode(s, matrix);
      }
      System.out.println("Encoded text: " + encoded);

      System.out.println("Enter the text to decrypt:");
      String encodedText = scanner.nextLine();

      ArrayList<String> post = preprocess(encodedText);
      String decoded = "";
      for (String s : post) {
          decoded += decode(s, matrix);
      }
      System.out.println("Decoded text: " + decoded);

      scanner.close();
  }
  public static ArrayList<String> preprocess(String in) {
    in = in.toUpperCase();
    String mid = "";
    for (int i = 0; i < in.length(); i++) {
      if (Character.isAlphabetic(in.charAt(i))) {
        if (in.charAt(i) == 'J') mid += "I";
        else mid += in.charAt(i);
      }
    }
    ArrayList<String> pairs = new ArrayList<String>();
    for (int i = 0; i < mid.length(); i += 2) {
      if (i + 1 < mid.length()) pairs.add(mid.substring(i, i + 2));
      else pairs.add(mid.substring(i) + "X");
    }
    return pairs;
  }
  public static char[][] buildMatrix() {
    List<String> alphabet =  Arrays.asList("ABCDEFGHIKLMNOPQRSTUVWXYZ".split(""));
    Collections.shuffle(alphabet);
    char[][] ret = new char[5][5];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < 25) {
      ret[j][k] = alphabet.get(i).charAt(0);
      i++;
      k++;
      if (k == 5) {
        k = 0;
        j++;
      }
    }
    return ret;

  }
  public static int findRow(char c, char[][] m) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (c == m[i][j]) {
          return i;
        }
      }
    }
    return -1;
  }
  public static int findCol(char c, char[][] m) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (c == m[i][j]) {
          return j;
        }
      }
    }
    return -1;
  }
  public static String encode(String in, char[][] m) {

    int c1r = findRow(in.charAt(0), m);
    int c2r = findRow(in.charAt(1), m);
    int c1c = findCol(in.charAt(0), m);
    int c2c = findCol(in.charAt(1), m);
    if (in.length() != 2) {
      System.out.println("Error: input must be two characters");
      return "";
    }
    if (in.charAt(0) == in.charAt(1)) {
      return Character.toString(in.charAt(0)) + "X";
    }
    if (c1r == c2r) {
      return Character.toString(m[c1r][(c1c + 1) % 5]) + Character.toString(m[c2r][(c2c + 1) % 5]);
    } 
    if (c1c == c2c) {
      return Character.toString(m[(c1r + 1) % 5][c1c]) + Character.toString(m[(c2r + 1) % 5][c2c]);
    }
    return Character.toString(m[c1r][c2c]) + Character.toString(m[c2r][c1c]);  
}
    public static String decode(String in, char[][] m) {

      int c1r = findRow(in.charAt(0), m);
      int c2r = findRow(in.charAt(1), m);
      int c1c = findCol(in.charAt(0), m);
      int c2c = findCol(in.charAt(1), m);
      if (in.length() != 2) {
        System.out.println("Error: input must be two characters");
        return "";
      }
      if (in.charAt(1) == 'X') {
        return Character.toString(in.charAt(0)) + Character.toString(in.charAt(0));
      }
      if (c1r == c2r) {
        return Character.toString(m[c1r][(c1c - 1 + 5) % 5]) + Character.toString(m[c2r][(c2c - 1 + 5) % 5]);
      } 
      if (c1c == c2c) {
        return Character.toString(m[(c1r - 1 + 5) % 5][c1c]) + Character.toString(m[(c2r - 1 + 5) % 5][c2c]);
      }
      return Character.toString(m[c1r][c2c]) + Character.toString(m[c2r][c1c]);  
  }
}
