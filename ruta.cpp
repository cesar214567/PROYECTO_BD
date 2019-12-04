#include <iostream> 
#include <fstream>
#include <vector> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm>
#include <string>
#define NUM_DATA 35    /*550 is the max*/
using namespace std;
vector<string> departamentos={"Amazonas","Ancash","Apurimac","Arequipa","Ayacucho","Cajamarca","Callao","Cusco","Huancavelica","Huanuco","Ica","Junin","La Libertad","Lambayeque","Lima","Loreto","Madre De Dios","Moquegua","Pasco","Piura","Puno","San Martin","Tacna","Tumbes","Ucayali"};
struct ruta{
    string id_ruta;
    string Destino;
    string Llegada;
    ruta(string id_ruta1,string Destino1,string Llegada1):id_ruta(id_ruta1),Destino(Destino1),Llegada(Llegada1){};
};

vector<ruta> output;
int main(){
    cout<<departamentos.size()<<endl;
    srand(time(NULL));
    ofstream salida1("ruta1k.txt");
    ofstream salida2("ruta2k.txt");
    salida1<<"id_ruta,Destino,Llegada"<<endl;
    for (int  i=0;i<NUM_DATA;i++){
        cout<<"iteracion"<<i<<endl;
        string id_ruta="",Destino="",Llegada="";
        Destino=departamentos[rand()%departamentos.size()];
        Llegada=departamentos[rand()%departamentos.size()];
        for(int j=0;j<3;j++){
            id_ruta+=Destino[j];
        }
        id_ruta+="-";
        for(int j=0;j<3;j++){
            id_ruta+=Llegada[j];
        }

        if (Destino==Llegada){
            i--;
            continue;
        }else{
            bool check=false;
            for (auto it:output){
                if (it.id_ruta==id_ruta){
                    check=true;
                    break;
                }
            }
            cout<<"LLEGO ACA2"<<endl;
            cout<<Destino<<" "<<Llegada<<endl;
            if (!check){
                output.emplace_back(ruta(id_ruta,Destino,Llegada));
                cout<<"LLEGO ACA"<<endl;
                continue;
            }else{
                i--;
                continue;
            }
        }
    }
    for (auto it:output){
    salida1<<it.id_ruta<<","<<it.Destino<<","<<it.Llegada<<endl;
    salida2<<it.id_ruta<<endl;
    
    }
    
}