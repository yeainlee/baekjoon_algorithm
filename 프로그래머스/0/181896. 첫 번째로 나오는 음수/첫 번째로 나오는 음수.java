class Solution {
    public int solution(int[] num_list) {
        int ans = 0;
        while(true){
            if(ans == num_list.length){
                ans = -1;
                break;
            }
            if(num_list[ans] < 0) break;
            ans++;
        }
        return ans;
    }
}