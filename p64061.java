import java.util.LinkedList;
import java.util.Scanner;

public class p64061 {
    public static int solution(int[][] board, int[] moves) {
        LinkedList<Integer> basket = new LinkedList<>();
        int answer = 0;
        for(int i = 0; i < moves.length; i++){
            int now = moves[i] - 1;
            int j;
            for(j = 0; j < board.length && board[j][now] == 0 ; j++);
            if(j == board.length) continue;
            if(!basket.isEmpty() && basket.getLast() == board[j][now]){
                basket.removeLast();
                answer += 2;
            }
            else{
                basket.add(board[j][now]);
            }

            board[j][now] = 0;
        }
        return answer;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] arr = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                arr[i][j] = sc.nextInt();
            }
        }

        int[] moves = new int[8];
        for(int i = 0; i < 8; i++){
            moves[i] = sc.nextInt();
        }

        System.out.println(solution(arr, moves));
        
    }
}