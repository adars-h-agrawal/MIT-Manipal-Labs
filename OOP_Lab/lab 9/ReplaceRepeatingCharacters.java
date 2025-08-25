import java.util.Scanner;

public class ReplaceRepeatingCharacters {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String input = scanner.nextLine();
        System.out.println("Enter the word to replace: ");
        String word = scanner.nextLine();

        StringBuilder result = new StringBuilder();
        char[] chars = input.toCharArray();
        boolean[] replaced = new boolean[chars.length];

        for (int i = 0; i < chars.length; i++) {
            if (i > 0 && chars[i] == chars[i - 1] && !replaced[i]) {
                result.append(word);
                replaced[i] = true;
            } else if (!replaced[i]) {
                result.append(chars[i]);
            }
        }

        System.out.println("Modified string: " + result.toString());
    }
}