#include <iostream> 
#include <fstream>
#include <vector> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm>
#include <string>
#define NUM_DATA 100
using namespace std;
vector<string> DNI;
string generate_DNI(){
    string dni="";
    for (int j=0;j<8;j++){
        /*bool check=rand()%2;
        if (check){*/
            dni+=48+rand()%10;
        /*}else{
            dni+=97+rand()%24;
        }*/
    }
    if (DNI.empty()){
        return dni;
    }else{
        auto it=find(DNI.begin(),DNI.end(),dni);
        if (it==DNI.end()){
            return dni;
        }else{
            dni=generate_DNI();
            return dni;
        }
    }
    
}
vector<string> output;
vector<pair<string,string>> Departamento_nombre_Agencia_nombre;
int main(){
    srand(time(NULL));
    ofstream salida1("empleado1k.txt");
    ofstream salida2("empleado2k.txt"); 
    ifstream entrada1("departamento2.txt");
    ifstream entrada2("adjusted-name-combinations-list.csv");
    ifstream entrada3("babynames-clean.csv");
    string palabra="",palabra2="";
    vector<string> nombres;
    vector<string> apellidos;
    //from here 
    while (getline(entrada3,palabra)){        
        nombres.push_back(palabra);
    }
    while (getline(entrada2,palabra,',')){
        getline(entrada2,palabra,',');
        getline(entrada2,palabra,',');
        bool assert=false;
        for (int i=0;i<apellidos.size();i++){
            if (apellidos[i]==palabra){
                assert=true;
                break;
            }
        }
        if (!assert){
            apellidos.push_back(palabra);
        }
        getline(entrada2,palabra,',');
        getline(entrada2,palabra,',');
        getline(entrada2,palabra,',');
    }
    apellidos.pop_back();
    //to here is to get all names and last names
    while (getline(entrada1,palabra,',')){
        getline(entrada1,palabra2);
        Departamento_nombre_Agencia_nombre.emplace_back(palabra,palabra2);
    }
    cout<<Departamento_nombre_Agencia_nombre.size()<<endl;
    salida1<<"DNI_Empleado,DNI_Administrador,Nombre,Apellido_Materno,Apellido_Paterno,Fecha_Nac,Direccion,DepartamentoNombre,AgenciaNombre"<<endl;
    for (int i=0;i<NUM_DATA;i++){
        cout<<"iteracion "<<i<<endl;
        string DNI_EMPLEADO="",DNI_ADMINISTRADOR="",NOMBRE="",APE_MATERNO="",APE_PATERNO="",Fecha_Nac="",DIRECCION="",DepartamentoNombre="",AgenciaNombre="";
        DNI_EMPLEADO=generate_DNI();
        string wtf;
        //from here -------------------------------------
        wtf=nombres[rand()%nombres.size()];
        for (int j=0;j<wtf.length()-1;j++){
            NOMBRE+=wtf[j];
        }
        wtf=apellidos[rand()%apellidos.size()];
        for (int j=1;j<wtf.length()-1;j++){
            APE_MATERNO+=wtf[j];
        }
        wtf=apellidos[rand()%apellidos.size()];
        for (int j=1;j<wtf.length()-1;j++){
            APE_PATERNO+=wtf[j];
        }
        Fecha_Nac+=to_string(rand()%30+1970);
        Fecha_Nac+="-";
        Fecha_Nac+=to_string(rand()%12+1);
        Fecha_Nac+="-";
        Fecha_Nac+=to_string(rand()%29);
        // to here is to generate the names and lastnames randomly
        DIRECCION+="-12.";
        DIRECCION=DIRECCION+to_string(rand()%10)+to_string(rand()%10)+"/";
        DIRECCION+="-77.";
        DIRECCION=DIRECCION+to_string(rand()%10)+to_string(rand()%10);
        auto it=Departamento_nombre_Agencia_nombre[rand()%Departamento_nombre_Agencia_nombre.size()];
        DepartamentoNombre=it.first;
        AgenciaNombre=it.second;
        if(i>5){
            DNI_ADMINISTRADOR=DNI[rand()%4];
        }
        salida1<<DNI_EMPLEADO<<","<<DNI_ADMINISTRADOR<<","<<NOMBRE<<","<<APE_MATERNO<<","<<APE_PATERNO<<","<<Fecha_Nac<<","<<DIRECCION<<","<<DepartamentoNombre<<","<<AgenciaNombre<<endl;
        salida2<<DNI_EMPLEADO<<endl;
        DNI.push_back(DNI_EMPLEADO);

    }
    
    

    

    
}