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
    long total = 0;

    foreach(var line in inputList)
    {
        var numbers = line.Replace(":", "")
            .Split(' ', StringSplitOptions.RemoveEmptyEntries)
            .Select(x => long.Parse(x))
            .ToList();

        var expectedOutput = numbers[0];

        var n = numbers.Count - 2;
        var totalCombinations = 1 << n; // 2^n combinations
        var results = new List<int[]>();

        for (var i = 0; i < totalCombinations; i++)
        {
            var combination = new int[n];
            for (var j = 0; j < n; j++)
            {
                // Check if the j-th bit is set
                if ((i & (1 << j)) != 0)
                {
                    combination[j] = 0;
                }
                else
                {
                    combination[j] = 1;
                }
            }
            results.Add(combination);
        }

        foreach(var combination in results)
        {
            var sum = numbers[1];
            for(var i=0; i<combination.Length; i++)
            {
                sum = combination[i] == 0 ? sum + numbers[i+2] : sum * numbers[i+2];
            }
            if(sum == expectedOutput)
            {
                total += expectedOutput;
                break;
            }
        }   
    }

    Console.WriteLine(total);
}

static void Part02(IList<string> inputList)
{
    
}

var inputList = GetInputList();

Part01(inputList);
Part02(inputList);
