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
    var total = 0;
    foreach (var line in inputList)
    {
        var sizes = line.Split('x', StringSplitOptions.RemoveEmptyEntries)
            .Select(x => int.Parse(x))
            .ToList();
        
        var areas = new List<int>
        {
            sizes[0] * sizes[1],
            sizes[0] * sizes[2],
            sizes[1] * sizes[2]
        };

        areas.Sort();

        total += areas.Sum() * 2 + areas[0];
    }
    Console.WriteLine(total);
}

static void Part02(IList<string> inputList)
{
    var total = 0;
    foreach (var line in inputList)
    {
        var sizes = line.Split('x', StringSplitOptions.RemoveEmptyEntries)
            .Select(x => int.Parse(x))
            .ToList();        

        sizes.Sort();
        
        total += (2 * (sizes[0] + sizes[1])) + (sizes[0] * sizes[1] * sizes[2]);
    }
    Console.WriteLine(total);
}

var inputList = GetInputList();

Part01(inputList);
Part02(inputList);
