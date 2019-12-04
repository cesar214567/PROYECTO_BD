#include <iostream> 
#include <fstream>
#include <vector> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm>
#include <string>
#define NUM_DATA 1000000
using namespace std;
vector<string> Cliente_DNI,IDRUTA,Agencia_Nombre,Bus_Placa;
vector<string> output;

int main(){
    srand(time(NULL));
    ofstream salida1("Ticket1000k.txt");
    ofstream salida2("Ticket2000k.txt"); 

    ifstream entrada1("cliente2000k.txt");
    ifstream entrada2("ruta2000k.txt");
    ifstream entrada3("agencia2.txt");
    ifstream entrada4("buses2000k.txt");
    string palabra="";
    //from here 
    while (getline(entrada1,palabra)){        
        Cliente_DNI.push_back(palabra);
    }
    while (getline(entrada2,palabra)){        
        IDRUTA.push_back(palabra);
    }

    while (getline(entrada3,palabra)){        
        Agencia_Nombre.push_back(palabra);
    }
    while (getline(entrada4,palabra)){        
        Bus_Placa.push_back(palabra);
    }
    
    salida1<<"Num_Ticket,ClienteDNI,id_ruta,AgenciaNombre,BusPlaca,Fecha_viaje"<<endl;
    //to here is to get all DNI from employees
    for (int i=0;i<NUM_DATA;i++){
        string Num_Ticket="",ClienteDNI="",id_ruta="",AgenciaNombre="",BusPlaca="",Fecha_viaje="";
        cout<<"iteracion "<<i<<endl;
        Num_Ticket=to_string(i);
        ClienteDNI=Cliente_DNI[rand()%Cliente_DNI.size()];
        id_ruta=IDRUTA[rand()%IDRUTA.size()];
        AgenciaNombre=Agencia_Nombre[rand()%Agencia_Nombre.size()];
        BusPlaca=Bus_Placa[rand()%Bus_Placa.size()];
        Fecha_viaje+=to_string(2018);
        Fecha_viaje+="-";
        Fecha_viaje+=to_string(rand()%12+1);
        Fecha_viaje+="-";
        Fecha_viaje+=to_string(rand()%28+1);
        salida1<<Num_Ticket<<","<<ClienteDNI<<","<<id_ruta<<","<<AgenciaNombre<<","<<BusPlaca<<","<<Fecha_viaje<<endl;
        salida2<<Num_Ticket<<","<<ClienteDNI<<endl;

    }
    
    

    

    
}