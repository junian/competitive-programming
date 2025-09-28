public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var result = new int[2];
        
        for(var i=0; i<nums.Length-1; i++) {
            for(var j=i+1; j<nums.Length; j++) {
                var a = nums[i];
                var b = nums[j];
                var c = a + b;
                if(c == target)
                    return new int[]{i,j};
            }
        }
        
        return result;
    }
}
