import java.util.*;

public class ShiftZeroes {
public static void main (String[] args) {
    /**
     * Please run this file code to see the output in console.
     * Uses 2 pointer approach which swipes inorder to shift 0s to the end of array
     */
    int[] nums = new int[]{1,0,2,2,0,2,3,4,5,0,0,4,5,5,0,0,0};

    int slow = 0;
    int fast = 1;
    while(fast < nums.length){
        if(nums[slow] == 0){
            while(fast < nums.length && nums[fast] == 0) {
                fast++;
            }
            if(fast < nums.length) {
                int s_x = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = s_x;
            }
        } else {
            slow++;
            fast++;
        }
    }
    System.out.println(Arrays.toString(nums));
}
}
