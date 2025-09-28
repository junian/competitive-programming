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
    var directionList = new List<Tuple<int, int>> 
    { 
        new Tuple<int, int>(-1,  0),
        new Tuple<int, int>( 0,  1),
        new Tuple<int, int>( 1,  0),
        new Tuple<int, int>( 0, -1),
    };

    var directionIndex = 0;

    var map = new List<char[]>{};
    map.AddRange(inputList.Select(x => x.ToCharArray()));

    var currentLocation = new Tuple<int, int>(0, 0);
    var steps = 1;

    // Find initial position
    for(var i=0; i<map.Count; i++)
    {
        for(var j=0; j<map[i].Length; j++)
        {
            if(map[i][j] == '^')
            {
                currentLocation = new Tuple<int, int>(i, j);
                map[i][j] = 'x';
                break;
            }
        }
    }

    while(true)
    {
        var direction = directionList[directionIndex];
        var nextLocation = new Tuple<int, int>(
            currentLocation.Item1 + direction.Item1, 
            currentLocation.Item2 + direction.Item2);

        if(nextLocation.Item1 < 0 || nextLocation.Item1 >= map.Count || 
           nextLocation.Item2 < 0 || nextLocation.Item2 >= map[0].Length)
        {
            break;
        }

        var nextLocationChar = map[nextLocation.Item1][nextLocation.Item2];
        // Turn right 90 degrees
        if(nextLocationChar == '#')
        {
            directionIndex = (directionIndex + 1) % directionList.Count;
        }
        else
        {
            if(nextLocationChar == '.')
            {
                map[nextLocation.Item1][nextLocation.Item2] = 'x';
                steps++;
            }
            currentLocation = nextLocation;
        }
    }

    Console.WriteLine(steps);
}

static void Part02(IList<string> inputList)
{
    var directionList = new List<Tuple<int, int>> 
    { 
        new Tuple<int, int>(-1,  0),
        new Tuple<int, int>( 0,  1),
        new Tuple<int, int>( 1,  0),
        new Tuple<int, int>( 0, -1),
    };

    var originalMap = new List<char[]>{};
    originalMap.AddRange(inputList.Select(x => x.ToCharArray()));

    var initialLocation = new Tuple<int, int>(0, 0);

    // Find initial position
    for(var i=0; i<originalMap.Count; i++)
    {
        for(var j=0; j<originalMap[i].Length; j++)
        {
            if(originalMap[i][j] == '^')
            {
                initialLocation = new Tuple<int, int>(i, j);
                break;
            }
        }
    }

    var obstacles = 0;

    for(var i=0; i<originalMap.Count; i++)
    {
        for(var j=0; j<originalMap[i].Length; j++)
        {
            if(originalMap[i][j] != '.')
                continue;

            var map = new List<char[]>{};
            map.AddRange(inputList.Select(x => x.ToCharArray()));
            map[i][j] = '#';

            var directionIndex = 0;
            var currentLocation = new Tuple<int, int>(initialLocation.Item1, initialLocation.Item2);
            map[currentLocation.Item1][currentLocation.Item2] = (char)('a' + (char)directionIndex);

            while(true)
            {
                var direction = directionList[directionIndex];
                var nextLocation = new Tuple<int, int>(
                    currentLocation.Item1 + direction.Item1, 
                    currentLocation.Item2 + direction.Item2);

                if(nextLocation.Item1 < 0 || nextLocation.Item1 >= map.Count || 
                nextLocation.Item2 < 0 || nextLocation.Item2 >= map[0].Length)
                {
                    break;
                }

                var nextLocationChar = map[nextLocation.Item1][nextLocation.Item2];
                
                // Turn right 90 degrees
                if(nextLocationChar == '#')
                {
                    directionIndex = (directionIndex + 1) % directionList.Count;
                }
                else
                {
                    if(nextLocationChar == (char)('a' + directionIndex))
                    {
                        obstacles++;
                        break;
                    }
                    map[nextLocation.Item1][nextLocation.Item2] = (char)('a' + directionIndex);
                    currentLocation = nextLocation;
                }
            }
        }
    }

    Console.WriteLine(obstacles);
}

var inputList = GetInputList();

Part01(inputList);
Part02(inputList);
