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
    var visits = new Dictionary<(int, int),int>{};
    var directions = new Dictionary<char, (int, int)>
    {
        ['^'] = (-1, 0),
        ['>'] = (0, 1),
        ['v'] = (1, 0),
        ['<'] = (0, -1),
    };

    foreach (var line in inputList)
    {
        var position = (0,0);
        visits.TryAdd(position, 1);
        foreach (var c in line)
        {
            position = (position.Item1 + directions[c].Item1, position.Item2 + directions[c].Item2);
            visits.TryAdd(position, 1);
        }
    }

    Console.WriteLine(visits.Count);
}

static void Part02(IList<string> inputList)
{
    var visits = new Dictionary<(int, int),int>{};
    var directions = new Dictionary<char, (int, int)>
    {
        ['^'] = (-1, 0),
        ['>'] = (0, 1),
        ['v'] = (1, 0),
        ['<'] = (0, -1),
    };

    foreach (var line in inputList)
    {
        var turn = 0;
        var positions = new List<(int, int)>{ (0,0), (0,0) };
        visits.TryAdd(positions[0], 1);

        foreach (var c in line)
        {
            var position = positions[turn];
            positions[turn] = (position.Item1 + directions[c].Item1, position.Item2 + directions[c].Item2);
            visits.TryAdd(positions[turn], 1);

            turn = (turn + 1) % 2;
        }
    }

    Console.WriteLine(visits.Count);
}

var inputList = GetInputList();

Part01(inputList);
Part02(inputList);
