#include <stdio.h>
#include <list>

#define MAX 3502

using namespace std;

int prime[MAX];

void generatePrimeNumbers();

int main(){
    int pos;
    int num = 0;
    int ind = 0;
    list<int> org;
    list<int>::iterator iter;
    list<int>::iterator temp;
    generatePrimeNumbers();
    
    while(true){
        scanf("%d", &num);
        
        if(num == 0) 
            break;
            
        org.clear();
        
        for(int i=1; i<=num; i++){
            org.push_back(i);
        }
        
        ind = 0;
        
        while(org.size()>1){
            if(prime[ind]>org.size())
                pos = prime[ind] % org.size();
            else
                pos = prime[ind];
        
            iter = org.begin();
            
            for(int i=0; i<pos-1; i++)
                iter++;
            
            temp = iter;
            
            iter++;
            
            if(iter == org.end()){
                iter = org.begin();
            }
              
            org.erase(temp);
            
            while(org.begin()!=iter){
                int t = *org.begin();    
                org.pop_front();
                org.push_back(t);
                    
            }
            
            ind++; 
        }
        
        printf("%d\n", *org.begin());
    }
    
    return 0;
}

void generatePrimeNumbers(){
    int x = 0;
    char notPrime[32621];
    
    for(int i=0; i<32621; i++)
        notPrime[i] = 0;
        
    notPrime[0] = 1;
    notPrime[1] = 1;
    
    for(int i = 2; i < 32621; i++){

        if(notPrime[i] == 0){
          prime[x] = i;  
          x++;
          if(x==3501) 
            return;
          
          for(int j = 2*i; j < 32621; j += i) notPrime[j] = 1;
        }
    }
}
