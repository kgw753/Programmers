import java.util.HashMap;

public class p42576_2 {
    public static String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> hm = new HashMap<>();
        for (String str : participant){
            hm.put(str, hm.getOrDefault(str, 0) + 1);
        }
            
        for (String str : completion){
            hm.put(str, hm.get(str) - 1);
        }

        for (String str : hm.keySet()) {
            if (hm.get(str) != 0) {
                answer = str;
                break;
            }
        }
        return answer;
    }

    public static void main(String[] args) {
        String ans = solution(new String[] { "leo", "kiki", "eden" }, new String[] { "eden", "kiki" });
        System.out.println(ans);

        ans = solution(new String[] { "marina", "josipa", "nikola", "vinko", "filipa" },
                new String[] { "josipa", "filipa", "marina", "nikola" });
        System.out.println(ans);

        ans = solution(new String[] {"mislav", "stanko", "mislav", "ana" },
                new String[] { "stanko", "ana", "mislav"});
        System.out.println(ans);
    }
}
