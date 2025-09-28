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
    var listA = new List<int> { };
    var listB = new List<int> { };
    var sum = 0;

    foreach (var line in inputList)
    {
        var nums = line.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        listA.Add(int.Parse(nums[0]));
        listB.Add(int.Parse(nums[1]));
    }

    listA.Sort();
    listB.Sort();

    for(var i=0; i<listA.Count; i++)
    {
        sum += Math.Abs(listA[i] - listB[i]);
    }

    Console.WriteLine(sum);
}

static void Part02(IList<string> inputList)
{
    var listA = new List<int> { };
    var listB = new List<int> { };
    var dict = new Dictionary<int, int> { };
    var sum = 0;

    foreach (var line in inputList)
    {
        var nums = line.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        listA.Add(int.Parse(nums[0]));
        listB.Add(int.Parse(nums[1]));
    }

    for(var i=0; i<listB.Count; i++)
    {
        var num = listB[i];
        dict.TryAdd(num, 0);
        dict[num]++;
    }

    for(var i=0; i<listA.Count; i++)
    {
        var num = listA[i];
        if(dict.TryGetValue(num, out int value))
            sum += num * value;
    }

    Console.WriteLine(sum);
}

var inputList = GetInputList();

Part01(inputList);
Part02(inputList);
