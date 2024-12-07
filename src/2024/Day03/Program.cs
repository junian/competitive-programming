using System.Text.RegularExpressions;

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
    var pattern = @"mul\((\d+),(\d+)\)";
    var regex = new Regex(pattern);
    
    foreach(var line in inputList)
    {
        var matches = regex.Matches(line);
        foreach (Match match in matches)
        {
            if (int.TryParse(match.Groups[1].Value, out int number1) && 
                int.TryParse(match.Groups[2].Value, out int number2))
            {
                total += (number1 * number2);
            }
        }
    }

    Console.WriteLine(total);
}

var inputList = GetInputList();

Part01(inputList);
