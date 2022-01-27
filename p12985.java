class Solution{
    public static int depth;
        public static int _L, _R;
        public int solution(int n, int a, int b){
            int mxDepth = 1;
            while(n != Math.pow(2, mxDepth)){
                mxDepth++;
            }
            
            _L = Math.min(a, b);
            _R = Math.max(a, b);
    
            treeGoDown(1, n, 0);
    
            return mxDepth - depth;
        }
    
        public static void treeGoDown(int mn, int mx, int d){
            int mid = (mn + mx) / 2;
            if(_L <= mid && _R > mid){
                depth = d;
                return;
            }
            else if(_L <= mid && _R <= mid){
                treeGoDown(mn, mid, d + 1);
            }
            else{
                treeGoDown(mid + 1, mx, d + 1);
            }
        }
    }