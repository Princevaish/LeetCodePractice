class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder ans = new StringBuilder();
        int p = 0;

        for (char c : s.toCharArray()) {
            if (c == '(') {
                p++;
                if (p > 1) {
                    ans.append('(');
                }
            } else {
                p--;
                if (p > 0) {
                    ans.append(')');
                }
            }
        }

        return ans.toString();
    }
}