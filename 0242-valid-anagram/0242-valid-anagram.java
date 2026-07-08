class Solution {
    public boolean isAnagram(String s, String t) {

        if (s.length() != t.length())
            return false;

        HashMap<Character, Integer> mp = new HashMap<>();

        for (char c : s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        for (char c : t.toCharArray()) {
            if (!mp.containsKey(c))
                return false;

            mp.put(c, mp.get(c) - 1);
        }

        for (int value : mp.values()) {
            if (value != 0)
                return false;
        }

        return true;
    }
}