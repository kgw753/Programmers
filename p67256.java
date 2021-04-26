public class p67256 {
    public static String solution(int[] numbers, String hand) {
        StringBuilder sb = new StringBuilder();
        int l = 10;
        int r = 12;

        int lLen = 0;
        int rLen = 0;

        for(int i = 0; i < numbers.length; i++){
            if(numbers[i] == 0) numbers[i] = 11;

            if(numbers[i] % 3 == 1){
                sb.append("L");
                l = numbers[i];
            }
            else if(numbers[i] % 3 == 0){
                sb.append("R");
                r = numbers[i];
            }
            else{
                int rTmp = Math.abs(r - numbers[i]);
                int lTmp = Math.abs(l - numbers[i]);
                rLen = (rTmp / 3) + (rTmp % 3);
                lLen = (lTmp / 3) + (lTmp % 3);
                if(rLen < lLen || (lLen == rLen && hand.equals("right"))){
                    sb.append("R");
                    r = numbers[i];
                }
                else{
                    sb.append("L");
                    l = numbers[i];
                }
            }
        }
        return sb.toString();
    }

    public static void main(String[] args){
        System.out.println(solution(new int[]{1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right"));
        System.out.println(solution(new int[]{7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2}, "left"));
        System.out.println(solution(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, "right"));
    }
}
