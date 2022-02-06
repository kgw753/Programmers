import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public static final int cacheHit = 1;
    public static final int cacheMiss = 5;

    public static Queue<String> cacheMemory;
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        cacheMemory = new LinkedList<>();
        if(cacheSize == 0){
            return cacheMiss * cities.length;
        }

        for(String city : cities){
            city = city.toLowerCase();

            if(cacheMemory.isEmpty()){
                answer += cacheMiss;
                cacheMemory.add(city);
                continue;
            }

            if(isInCache(city)){
                cacheMemory.remove(city);
                cacheMemory.add(city);
                answer += cacheHit;
            }
            else{
                if(cacheMemory.size() == cacheSize){
                    cacheMemory.poll();
                }
                cacheMemory.add(city);
                answer += cacheMiss;
            }
        }

        return answer;
    }

    public static boolean isInCache(String city){
        for(String data : cacheMemory){
            if(data.equals(city)){
                return true;
            }
        }
        return false;
    }
}