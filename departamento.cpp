#include <iostream> 
#include <fstream>
#include <vector> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm>
#include <string>
/*#define NUM_DATA 10 this is not used*/
using namespace std;
vector<string> Departamento_nombre={"Limpieza","Ventas","Conductores","Asistentes"};
struct Departamento{
    string nombre;
    string descripcion;
    string AgenciaNombre;
    Departamento(string nombre1,string descripcion1,string AgenciaNombre1):nombre(nombre1),descripcion(descripcion1),AgenciaNombre(AgenciaNombre1){};
};

vector<Departamento> output;
vector<string> Agencia_nombre;
int main(){
    srand(time(NULL));
    ofstream salida1("departamento1.txt");
    ofstream salida2("departamento2.txt"); 
    ifstream entrada1("agencia2.txt");
    string palabra;
    while (getline(entrada1,palabra)){
        Agencia_nombre.push_back(palabra);
    }
    salida1<<"nombre,descripcion,AgenciaNombre"<<endl;
    for (int  i=0;i<Departamento_nombre.size();i++){
        cout<<"iteracion"<<i<<endl;
        string nombre="",descripcion="",AgenciaNombre="";
        nombre=Departamento_nombre[i];
        descripcion=nombre;
        for (int j=0;j<Agencia_nombre.size();j++){
            AgenciaNombre=Agencia_nombre[j];
            salida1<<nombre<<","<<descripcion<<","<<AgenciaNombre<<endl;
            salida2<<nombre<<","<<AgenciaNombre<<endl;
        }
    }

    
}