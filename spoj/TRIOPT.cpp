#include <cstdio>
#include <cmath>

#define MAX 1000024

using namespace std;

double maxi[MAX], mini[MAX];
       
void catatMaksDanMin()
{
    double maxima  = -100.0, minima  = 100.0;
    double tmp;
    //genap
    for(int i=0; i<=1000000; i+=2)
    {
        tmp = cos((double) i/2.0);
        if(tmp > maxima)
            maxima = tmp;
        maxi[i+2] = maxima;
        if(tmp < minima)
            minima = tmp;
        mini[i+2] = minima;
    }
    //ganjil
    maxima  = -100.0, minima  = 100.0;
    for(int i=1; i<=1000000; i+=2)
    {
        tmp = cos((double) i/2.0);
        if(tmp > maxima)
            maxima = tmp;
        maxi[i+2] = maxima;
        if(tmp < minima)
            minima = tmp;
        mini[i+2] = minima;
    }
}

int main()
{
    catatMaksDanMin();
    int jumlahSin;
    double solution;
    int t;
    char eq[16];
    char func[16];
    int s;
    scanf("%d", &t);
    
    while(t--)
    {
        jumlahSin = 0;
        
        scanf("%s", eq);
        if(eq[0] == 's')
            jumlahSin++;
        scanf("%s", eq);
        if(eq[0] == 's')
            jumlahSin++;
        scanf("%s", eq);
        if(eq[0] == 's')
            jumlahSin++;
        
        scanf("%s", func);
        scanf("%d", &s);
        
        //jika yg diminta fungsi maksimal
        if(func[1] == 'a')
            solution = -100.0;
        //jika yg diminta fungsi minimal
        else
            solution = 100.0;
        
        for(int i=2;i<s;i++)
        {
            double tmpSolution;
            switch(jumlahSin)
            {
                case 0:
                    tmpSolution = 2.0 * cos((double)i/2.0);
                    if(tmpSolution > 0.0)
                        tmpSolution = (func[1]=='a' ? maxi[i] : mini[i]) * tmpSolution + cos(s-i);
                    else
                        tmpSolution = (func[1]=='i' ? maxi[i] : mini[i]) * tmpSolution + cos(s-i);
                    break;
                case 1:
                    tmpSolution = 2.0 * cos((double)i/2.0);
                    if(tmpSolution > 0.0)
                        tmpSolution = (func[1]=='a' ? maxi[i] : mini[i]) * tmpSolution + sin(s-i);
                    else
                        tmpSolution = (func[1]=='i' ? maxi[i] : mini[i]) * tmpSolution + sin(s-i);
                    break;
                case 2:
                    tmpSolution = 2.0 * sin((double)i/2.0);
                    if(tmpSolution > 0.0)
                        tmpSolution = (func[1]=='a' ? maxi[i] : mini[i]) * tmpSolution + cos(s-i);
                    else
                        tmpSolution = (func[1]=='i' ? maxi[i] : mini[i]) * tmpSolution + cos(s-i);
                    break;
                case 3:
                    tmpSolution = 2.0 * sin((double)i/2.0);
                    if(tmpSolution > 0.0)
                        tmpSolution = (func[1]=='a' ? maxi[i] : mini[i]) * tmpSolution + sin(s-i);
                    else
                        tmpSolution = (func[1]=='i' ? maxi[i] : mini[i]) * tmpSolution + sin(s-i);
                    break;
                default: break;    
            }
            if((func[1] == 'a' && tmpSolution > solution)
                ||
               (func[1] == 'i' && tmpSolution < solution))
                solution = tmpSolution;
        }
        printf("%.10lf\n", solution);
    }
    
    return 0;
}
