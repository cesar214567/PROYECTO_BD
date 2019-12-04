#include <iostream> 
#include <fstream>
#include <vector> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm>
#include <string>
/*#define NUM_DATA 500 in this case does not matter because the code works for the number of tickets*/
using namespace std;
vector<pair<string,string>> Tickets;
vector<string> output;

int main(){
    srand(time(NULL));
    ofstream salida1("factura1000k.txt");
    ofstream salida2("factura2000k.txt"); 

    ifstream entrada1("Ticket2000k.txt");
    string palabra="",palabra2="",wtf;
    //from here 
    while (getline(entrada1,palabra,',')){  
        getline(entrada1,palabra2);
        Tickets.push_back(make_pair(palabra,palabra2));
    }
    Tickets.pop_back();
    salida1<<"Num_Ticket, Fecha, Hora, Subtotal, Total, ClienteDNI,RUC"<<endl;
    //to here is to get all DNI from employees
    for (int i=1;i<=Tickets.size();i+=2){
        string Num_Ticket="", Fecha="", Hora="", Subtotal="", Total="", ClienteDNI="",RUC="";
        cout<<"iteracion "<<i<<endl;
        Num_Ticket=Tickets[i].first;
        Fecha+=to_string(rand()%7+2011);
        Fecha+="-";
        Fecha+=to_string(rand()%12+1);
        Fecha+="-";
        Fecha+=to_string(rand()%29);
        //now time
        Hora=Hora+to_string(rand()%24+1)+":"+to_string(rand()%60)+":"+to_string(rand()%60);
        double temporal=rand()%300+100;
        Subtotal=to_string(temporal);
        Total=to_string(temporal*1.18);
        ClienteDNI=Tickets[i].second;
        for (int j=0;j<11;j++){
            RUC+=to_string(rand()%9+1);
        }
        salida1<<Num_Ticket<<","<<Fecha<<","<<Hora<<","<<Subtotal<<","<<Total<<","<<ClienteDNI<<","<<RUC<<endl;
        salida2<<Num_Ticket<<endl;

    }
    cout<<Tickets.size()<<endl;
    
    

    

    
}