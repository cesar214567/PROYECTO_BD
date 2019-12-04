#include <iostream> 
#include <fstream>
#include <vector> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm>
#include <string>
#define NUM_DATA 5
using namespace std;
vector<string> DNI;
vector<string> output;
int main(){
    srand(time(NULL));
    ofstream salida1("capacitacion1k.txt");
    ofstream salida2("capacitacion2k.txt"); 
    ifstream entrada1("empleado2k.txt");
    string palabra="",palabra2="";
    vector<string> nombres;
    vector<string> apellidos;
    //from here 
    while (getline(entrada1,palabra)){        
        DNI.push_back(palabra);
    }
    salida1<<"Cod_capacitacion,DNI_ponente,Fecha"<<endl;
    //to here is to get all DNI from employees
    for (int i=0;i<NUM_DATA;i++){
        cout<<"iteracion "<<i<<endl;
        string Cod_capacitacion="",DNI_Ponente="",Fecha="";
        Cod_capacitacion=to_string(i);
        DNI_Ponente=DNI[rand()%DNI.size()];
        Fecha+=to_string(rand()%4+2013);
        Fecha+="-";
        Fecha+=to_string(rand()%12+1);
        Fecha+="-";
        Fecha+=to_string(rand()%29);
        salida1<<Cod_capacitacion<<","<<DNI_Ponente<<","<<Fecha<<endl;
        salida2<<Cod_capacitacion<<endl;

    }
    
    

    

    
}