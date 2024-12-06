// See https://aka.ms/new-console-template for more information
var listA = new List<int> { };
var listB = new List<int> { };
var sum = 0;

string? line;
while ((line = Console.ReadLine()) != null)
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
