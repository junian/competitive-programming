var count = 0;

string? line;
while ((line = Console.ReadLine()) != null)
{
    var nums = line
        .Split(' ', StringSplitOptions.RemoveEmptyEntries)
        .Select(x => int.Parse(x))
        .ToList();

    var isValid = true;
    var increaseOrDecrease = 0;

    for(var i=1; i<nums.Count; i++)
    {
        if(nums[i] == nums[i-1])
        {
            isValid = false;
            break;
        }

        if(increaseOrDecrease == 0)
        {
            increaseOrDecrease = nums[i] - nums[i-1];
            increaseOrDecrease /= Math.Abs(increaseOrDecrease);
        }

        var diff = (nums[i] - nums[i-1]) * increaseOrDecrease;
        if(diff < 0 )
        {
            isValid = false;
            break;
        }

        var absDiff = Math.Abs(diff);
        if(absDiff < 1 || absDiff > 3)
        {
            isValid = false;
            break;
        }
    }

    if(isValid)
        count++;
}

Console.WriteLine(count);
