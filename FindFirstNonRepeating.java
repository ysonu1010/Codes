public class FindFirstNonRepeating {
    public static void main(String[] args) {
        /**
         * Given a string s, find the first non-repeating character in it
         * and return its index. If it does not exist, return -1.
         * - findFirstNonRepeating method gives the required index
         */
        StringBuilder s = new StringBuilder("abccdderjgggfaffb");
        System.out.println(findFirstNonRepeating(s));
    }

    private static int findFirstNonRepeating(StringBuilder s) {
        int[] alphabets = new int[26];
        for (int i = 0; i < s.length(); i++) {
            int alpha = s.charAt(i);
            alphabets[alpha - 97] = alphabets[alpha - 97] + 1;
        }
        for (int i = 0; i < s.length(); i++) {
            int alpha = s.charAt(i);
            if (alphabets[alpha - 97] == 1) {
                return i;
            }
        }
        return -1;
    }
}
