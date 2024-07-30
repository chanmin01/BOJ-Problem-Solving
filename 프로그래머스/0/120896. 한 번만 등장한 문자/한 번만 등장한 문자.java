import java.util.HashMap;

class Solution {
    public String solution(String s) {
        String answer = "";
        HashMap<Integer, Integer> hash = new HashMap<>();
        for (char st : s.toCharArray()) {
            hash.put(st - 'a', hash.getOrDefault(st - 'a', 0) + 1);
        }
        for (int i = 0; i < 26; i++) {
            if (hash.get(i) != null && hash.get(i) == 1) {
                answer += (char)(i + 'a');
            }
        }
        return answer;
    }
}