public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var dict = new Dictionary<int, int>();

        for(var i=0; i<nums.Length; i++) {
            var a = nums[i];
            var b = target - a;

            if(dict.ContainsKey(b))
                return new int[]{dict[b], i};
            
            if(!dict.ContainsKey(a))
                dict.Add(a, i);
        }

        return new int[]{0,1};
    }
}
