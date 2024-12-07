using System.Text.RegularExpressions;

var total = 0;
var list = new List<string>{};
var xmas = "XMAS";
string? line;

while ((line = Console.ReadLine()) != null)
{
    list.Add(line);
}

var horizontal = list.Count;
var vertical = list[0].Length;

for(var i=0; i<horizontal; i++)
for(var j=0; j<vertical; j++)
{
    var c = list[i][j];
    var isGood = true;
    if(c == xmas[0])
    {
        // horizontal right
        isGood = true;
        for(var a=1; a<xmas.Length; a++)
        {
            if(i+a >= horizontal || list[i+a][j] != xmas[a])
            {
                isGood = false;
                break;
            }
        }
        total += isGood ? 1 : 0;

        // horizontal left
        isGood = true;
        for(var a=1; a<xmas.Length; a++)
        {
            if(i-a < 0 || list[i-a][j] != xmas[a])
            {
                isGood = false;
                break;
            }
        }
        total += isGood ? 1 : 0;

        // vertical up 
        isGood = true;
        for(var a=1; a<xmas.Length; a++)
        {
            if(j-a < 0 || list[i][j-a] != xmas[a])
            {
                isGood = false;
                break;
            }
        }
        total += isGood ? 1 : 0;

        // vertical down 
        isGood = true;
        for(var a=1; a<xmas.Length; a++)
        {
            if(j+a >= vertical || list[i][j+a] != xmas[a])
            {
                isGood = false;
                break;
            }
        }
        total += isGood ? 1 : 0;

        // diagonal up right
        isGood = true;
        for(var a=1; a<xmas.Length; a++)
        {
            if(i+a >= horizontal || j-a < 0 || list[i+a][j-a] != xmas[a])
            {
                isGood = false;
                break;
            }
        }
        total += isGood ? 1 : 0;

        // diagonal up left
        isGood = true;
        for(var a=1; a<xmas.Length; a++)
        {
            if(i-a < 0 || j-a < 0 || list[i-a][j-a] != xmas[a])
            {
                isGood = false;
                break;
            }
        }
        total += isGood ? 1 : 0;

        // diagonal down right
        isGood = true;
        for(var a=1; a<xmas.Length; a++)
        {
            if(i+a >= horizontal || j+a >= vertical || list[i+a][j+a] != xmas[a])
            {
                isGood = false;
                break;
            }
        }
        total += isGood ? 1 : 0;

        // diagonal down left
        isGood = true;
        for(var a=1; a<xmas.Length; a++)
        {
            if(i-a < 0 || j+a >= vertical || list[i-a][j+a] != xmas[a])
            {
                isGood = false;
                break;
            }
        }
        total += isGood ? 1 : 0;
    }
}

Console.WriteLine(total);
