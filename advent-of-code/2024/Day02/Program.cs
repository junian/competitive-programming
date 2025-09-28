static IList<string> GetInputList()
{
    var list = new List<string> { };
    var line = default(string?);
    while ((line = Console.ReadLine()) != null)
    {
        list.Add(line);
    }

    return list;
}

static void Part01(IList<string> inputList)
{
    var count = 0;
    foreach (var line in inputList)
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
}

static void Part02(IList<string> inputList)
{
    var count = 0;
    foreach (var line in inputList)
    {
        var originalNums = line
            .Split(' ', StringSplitOptions.RemoveEmptyEntries)
            .Select(x => int.Parse(x))
            .ToList();

        var numList = new List<List<int>>
        {
            originalNums
        };

        for(var i=0; i<originalNums.Count; i++)
        {
            var newNums = new List<int>();
            newNums.AddRange(originalNums);
            newNums.RemoveAt(i);
            numList.Add(newNums);
        }

        foreach(var nums in numList)
        {
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
            {
                count++;
                break;
            }
        }
    }

    Console.WriteLine(count);
}

var inputList = GetInputList();

Part01(inputList);
Part02(inputList);
