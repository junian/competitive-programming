public class Solution {
    public bool IsPalindrome(int x) {
        if(x < 0)
            return false;

        var reverseNumber = 0;
        var y = x;

        while(y > 0)
        {
            reverseNumber = reverseNumber * 10 + (y % 10);
            y = y / 10;
        }

        return reverseNumber == x;
    }
}
