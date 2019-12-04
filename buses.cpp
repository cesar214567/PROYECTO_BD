#include <iostream> 
#include <fstream>
#include <vector> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm>
#define NUM_DATA 40
using namespace std;
vector<string> PLACAS;

string generate_placa(){
    string placa="";
    for (int j=0;j<10;j++){
        bool check=rand()%2;
        if (check){
            placa+=48+rand()%10;
        }else{
            placa+=97+rand()%24;
        }
    }
    if (PLACAS.empty()){
        return placa;
    }else{
        auto it=find(PLACAS.begin(),PLACAS.end(),placa);
        if (it==PLACAS.end()){
            return placa;
        }else{
            placa=generate_placa();
            return placa;
        }
    }
    
}

int main(){
    srand(time(NULL));
    ofstream salida1("buses1k.txt");
    ofstream salida2("buses2k.txt");
    salida1<<"Capacidad,Anho, Modelo,Placa"<<endl;
    for (int  i=0;i<NUM_DATA;i++){
        cout<<"iteracion"<<i<<endl;
        int capacidad=rand()%5+15;
        int anho=rand()%7+2007;
        string modelo="";
        string placa="";
        for (int j=0;j<rand()%15+2;j++){
            modelo+=97+rand()%24;
        }
        placa=generate_placa();
        PLACAS.push_back(placa);
        salida1<<capacidad<<","<<anho<<","<<modelo<<","<<placa<<endl;
        salida2<<placa<<endl;


    }

}