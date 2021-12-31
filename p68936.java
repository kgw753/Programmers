public class p68936{
    public static int zero, one;
    public static int[][] Arr;

    public static int[] solution(int[][] arr) {
        Arr = arr;
        quadTree(0, 0, arr.length);
        return new int[]{zero, one};
    }

    public static void quadTree(int y, int x, int size){
        boolean isOne = true;
        boolean isZero = true;
        
        for(int i = y; i < y + size; i++){
            for(int j = x; j < x + size; j++){
                if(Arr[i][j] == 1) isZero = false;
                if(Arr[i][j] == 0) isOne = false;
            }
        }

        if(isOne){
            one++;
            return;
        }

        if(isZero){
            zero++;
            return;
        }

        size /= 2;
        quadTree(y, x, size);
        quadTree(y, x + size, size);
        quadTree(y + size, x, size);
        quadTree(y + size, x + size, size);
    }
}