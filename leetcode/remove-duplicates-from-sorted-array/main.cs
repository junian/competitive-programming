public class Solution {
    public int RemoveDuplicates(int[] nums) {
        var currentNumber = int.MinValue;
        var index = 0;

        foreach(var num in nums){
            if(num > currentNumber)
            {
                currentNumber = num;
                nums[index++] = currentNumber;
            }
        }

        return index;
    }
}
