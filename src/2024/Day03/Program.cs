using System.Text.RegularExpressions;

var total = 0;
var pattern = @"mul\((\d+),(\d+)\)";
var regex = new Regex(pattern);
string? line;
while ((line = Console.ReadLine()) != null)
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
