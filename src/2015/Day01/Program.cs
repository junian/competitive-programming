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
    var level = 0;
    foreach (var line in inputList)
    {
        level = line.Select(x => x == '(' ? 1 : -1).Sum(); 
    }
    Console.WriteLine(level);
}

static void Part02(IList<string> inputList)
{
    var level = 0;
    foreach (var line in inputList)
    {
        for(var i=0; i<line.Length; i++)
        {
            level += line[i] == '(' ? 1 : -1;
            if (level == -1)
            {
                Console.WriteLine(i + 1);
                return;
            }
        }
    }
    // Console.WriteLine(level);
}

var inputList = GetInputList();

Part01(inputList);
Part02(inputList);
