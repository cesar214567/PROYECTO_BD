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



int main(){
    srand(time(NULL));
    ofstream salida1("cliente1k.txt");
    ofstream salida2("cliente2k.txt");
    ifstream entrada1("adjusted-name-combinations-list.csv");
    ifstream entrada2("babynames-clean.csv");
    string palabra;
    vector<string> nombres;
    while (getline(entrada2,palabra)){        
        nombres.push_back(palabra);
    }
    vector<string> apellidos;
    while (getline(entrada1,palabra,',')){
        getline(entrada1,palabra,',');
        getline(entrada1,palabra,',');
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
        /*auto it= find(apellidos.begin(),apellidos.end(),palabra);
        if (it==apellidos.end());
            apellidos.push_back(palabra);*/
        getline(entrada1,palabra,',');
        getline(entrada1,palabra,',');
        getline(entrada1,palabra,',');
        
    }
    apellidos.pop_back();
    for (auto it:apellidos){
        cout<<it<<endl;
    }
    cout<<apellidos.size()<<endl;
    if (apellidos[0]==apellidos[1]){
        cout<<"WTF"<<endl;
    }
    salida1<<"DNI,nombre, Apellido_Materno,Apellido_Paterno,Fecha_Nac,teléfono,sexo"<<endl;
    for (int  i=0;i<NUM_DATA;i++){
        cout<<"iteracion"<<i<<endl;
        string wtf="";
        string dni="",nombre="",Ape_materno="",Ape_paterno="",fecha="",telefono="",sexo="";
        dni=to_string(70000000+i);
        wtf=nombres[rand()%nombres.size()];
        for (int j=0;j<wtf.length()-1;j++){
            nombre+=wtf[j];
        }
        wtf=apellidos[rand()%apellidos.size()];
        for (int j=1;j<wtf.length()-1;j++){
            Ape_materno+=wtf[j];
        }
        wtf=apellidos[rand()%apellidos.size()];
        for (int j=1;j<wtf.length()-1;j++){
            Ape_paterno+=wtf[j];
        }
        fecha+=to_string(rand()%30+1970);
        fecha+="-";
        fecha+=to_string(rand()%12+1);
        fecha+="-";
        fecha+=to_string(rand()%29);
        for(int i=0;i<8;i++){
            telefono+=to_string(rand()%9+1);
        }
        int random=rand()%2;
        if (random){
            sexo="F";
        }else{
            sexo="M";
        }


        salida1<<dni<<","<<nombre<<","<<Ape_materno<<","<<Ape_paterno<<","<<fecha<<","<<telefono<<","<<sexo<<endl;
        salida2<<dni<<endl;


    }

}