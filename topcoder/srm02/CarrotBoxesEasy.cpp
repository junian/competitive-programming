
#include <vector>
using namespace std;

class CarrotBoxesEasy
{
public:
	int theIndex(vector <int> carrots, int K){
		int index=0,i;
		int n = K;
		while(n>0)
		{
			index=0;
			for(i=1;i<carrots.size();i++)
				if(carrots[i]>carrots[index])
					index=i;
			n--;
			carrots[index]--;
		}
		return index;
	}
};
