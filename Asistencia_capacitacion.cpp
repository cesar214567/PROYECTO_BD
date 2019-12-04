#include <iostream> 
#include <fstream>
#include <vector> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm>
#include <string>
#define NUM_DATA 50
using namespace std;
vector<string> DNI;
vector<string> Cod_Capacitaciones;
vector<string> output;
struct asistencia{
    string DNI;
    string Cod_Capacitaciones;
    asistencia(string DNI1,string Cod_Capacitaciones1):DNI(DNI1),Cod_Capacitaciones(Cod_Capacitaciones1){};
};
vector <asistencia> checkers;

int main(){
    srand(time(NULL));
    ofstream salida1("Asistencia_capacitacion1k.txt");
    ofstream salida2("Asistencia_capacitacion2k.txt"); 
    ifstream entrada1("capacitacion2k.txt");
    ifstream entrada2("empleado2k.txt");
    string palabra="";
    //from here 
    while (getline(entrada1,palabra)){        
        Cod_Capacitaciones.push_back(palabra);
    }
    while (getline(entrada2,palabra)){        
        DNI.push_back(palabra);
    }
    salida1<<"DNI_ponente,Cod_capacitacion"<<endl;
    //to here is to get all DNI from employees
    for (int i=0;i<NUM_DATA;i++){
        cout<<"iteracion "<<i<<endl;
        string Cod_capacitacion="",DNI_Empleado="";
        Cod_capacitacion=Cod_Capacitaciones[rand()%Cod_Capacitaciones.size()];
        DNI_Empleado=DNI[rand()%DNI.size()];
        bool check=false;
        for (auto it:checkers){
            if (it.Cod_Capacitaciones==Cod_capacitacion && it.DNI==DNI_Empleado){
                i--;
                check=true;
                break;
            }
        }
        if (!check){
            salida1<<DNI_Empleado<<","<<Cod_capacitacion<<endl;
            salida2<<DNI_Empleado<<","<<Cod_capacitacion<<endl;
            checkers.push_back(asistencia(DNI_Empleado,Cod_capacitacion));
        }
        

    }
    
    

    

    
}