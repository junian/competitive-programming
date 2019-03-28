#include <iostream>

using namespace std;

void printLCD(int s, char kar[9]) ;
void cetak_horizon(int s, char c) ;

int main() {
    int s = 0;
    char kar[9] = "";
    int x = 0;
    
    while(true) {
        cin>>s>>kar;
        
        if(s == 0 && kar[0] == '0' && kar[1] == '\0')
            break;
            
        printLCD(s, kar);
        
        cout<<endl<<endl;
    }
    
    return 0;
}

void printLCD(int s, char kar[9]) {
    int i, j;
    
    for(i=0; kar[i]!='\0'; i++) {
        cout<<" ";
        if(kar[i] == '4' || kar[i] == '1') {
            cetak_horizon(s, ' ');
        } 
        else {
            cetak_horizon(s, '-');
        }
        
        cout<<" ";
        if(kar[i+1]!='\0')
            cout<<" ";
    }
    
    cout<<endl;
    
    for(i=0; i<s; i++) {
        for(j=0; kar[j]!='\0'; j++) {
            if(kar[j] == '1' || kar[j] == '2' || kar[j] == '3' || kar[j] == '7') {
                cout<<" ";
            } 
            else {
                cout<<"|";
            }
            
            cetak_horizon(s, ' ');
            
            if(kar[j] == '5' || kar[j] == '6') {
                cout<<" ";
            } 
            else {
                cout<<"|";
            }
            
            if(kar[j+1]!='\0')
                cout<<" ";
        }
        cout<<endl;
    }
    
    for(i=0; kar[i]!='\0'; i++) {
        cout<<" ";
        if(kar[i] == '0' || kar[i] == '1' || kar[i] == '7') {
            cetak_horizon(s, ' ');
        } 
        else {
            cetak_horizon(s, '-');
        }
        
        cout<<" ";
        if(kar[i+1]!='\0')
            cout<<" ";
    }
    
    cout<<endl;
    
    for(i=0; i<s; i++) {
        for(j=0; kar[j]!='\0'; j++) {
            if(kar[j] == '2' || kar[j] == '6' || kar[j] == '8' || kar[j] == '0') {
                cout<<"|";
            } 
            else {
                cout<<" ";
            }
            
            cetak_horizon(s, ' ');
            
            if(kar[j] == '2') {
                cout<<" ";
            } 
            else {
                cout<<"|";
            }
            
            if(kar[j+1]!='\0')
                cout<<" ";
        }
        cout<<endl;
    }
    
    for(i=0; kar[i]!='\0'; i++) {
        cout<<" ";
        if(kar[i] == '1' || kar[i] == '4' || kar[i] == '7') {
            cetak_horizon(s, ' ');
        } 
        else {
            cetak_horizon(s, '-');
        }
        
        cout<<" ";
        if(kar[i+1]!='\0')
            cout<<" ";
    }
}

void cetak_horizon(int s, char c) {
    for(int i=0; i<s; i++) {
        cout<<c;
    }
}
