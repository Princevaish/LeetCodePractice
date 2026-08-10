import java.util.*;

class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {

        StringBuilder sb = new StringBuilder();

        for (char c : paragraph.toCharArray()) {
            if (Character.isLetter(c)) {
                sb.append(Character.toLowerCase(c));
            } else {
                sb.append(' ');
            }
        }

        String[] words = sb.toString().split("\\s+");

        HashSet<String> bannedSet = new HashSet<>();
        for (String word : banned) {
            bannedSet.add(word);
        }

        HashMap<String, Integer> mp = new HashMap<>();

        for (String word : words) {
            if (!word.isEmpty() && !bannedSet.contains(word)) {
                mp.put(word, mp.getOrDefault(word, 0) + 1);
            }
        }

        int maxCount = 0;
        String ans = "";

        for (String key : mp.keySet()) {
            if (mp.get(key) > maxCount) {
                maxCount = mp.get(key);
                ans = key;
            }
        }

        return ans;
    }
}