
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

class Solution {
    public static Map<String, List<int[]>> mp;  // List< pair< playCount, index > >
    public static Map<String, Integer> total;
    public static int size;
    public int[] solution(String[] genres, int[] plays) {
        mp = new HashMap<>();
        total = new HashMap<>();
        size = genres.length;

        List<int[]> v;
        for(int i = 0; i < size; i++){
            v = mp.getOrDefault(genres[i], new ArrayList<>());
            v.add(new int[]{plays[i], i});
            mp.put(genres[i], v);
            total.put(genres[i], total.getOrDefault(genres[i], 0) + plays[i]);
        }
        List<Integer> res = new ArrayList<>();

        List<Entry<String, Integer>> entries
                        = new ArrayList<>(total.entrySet());

        Collections.sort(entries, new Comparator<Entry<String, Integer>>(){
            @Override
            public int compare(Entry<String, Integer> e1, Entry<String, Integer> e2){
                return e2.getValue() - e1.getValue();
            }
        });
        
        for(Entry<String, Integer> e : entries){
            v = mp.get(e.getKey());
            Collections.sort(v, new Comparator<int[]>(){
                @Override
                public int compare(int[] a1, int[] a2){
                    return a2[0] - a1[0];
                }
            });

            for(int i = 0; i < v.size() && i < 2; i++){
                res.add(v.get(i)[1]);
            }
        }

        int[] ret = new int[res.size()];
        for(int i = 0; i < res.size(); i++){
            ret[i] = res.get(i);
        }

        return ret;
    }
}