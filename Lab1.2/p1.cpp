#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <limits>
#include <queue>
#include <cmath>
#include <fstream>
#include <algorithm>
#include<bits/stdc++.h>
#include <future>
#include <array>

using namespace std;

class alumno {
public:
    string nombre, apellido;
    string ciclo;
    float mensualidad;

    alumno(string nombre, string apellido, string ciclo, float mensualidad) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->ciclo = ciclo;
        this->mensualidad = mensualidad;
    }
};


void escribir(){
    string nombre;
    string apellido;
    string ciclo;
    float mensualidad;
    ofstream datos;
    int y;
    static vector<alumno> alumnosxd;

    datos.open("datos.txt");
    cin>>y;
    for(int x=0; x<y; x++) {
        cin >> nombre;
        cin >> apellido;
        cin >> ciclo;
        cin >> mensualidad;
    }
    auto *tempalumno = new alumno(nombre,apellido,ciclo,mensualidad);
    alumnosxd.push_back(*tempalumno);
    delete tempalumno;

            for(vector<alumno>::iterator it=alumnosxd.begin(); it != alumnosxd.end(); ++it){
                datos<<(*it).nombre<<sizeof((*it))<<(*it).apellido<<sizeof((*it))<<(*it).ciclo<<sizeof((*it))<<(*it).mensualidad<<sizeof((*it))<<"\n";
            }


}


void leer() {
    char buffer[100];
    string nombre;
    string apellido;
    string ciclo;
    string mensualidad;
    string line;//placebo
    ifstream datos ("datos.txt", ios::in | ios::binary);
    datos.read(buffer,100);
    for(int x = 0;x<100;x++)
    {
      cout<<buffer[x]<<endl;
    }


    /*if (datos.is_open()) {
        while (!datos.eof()) {
            getline(datos, nombre, '|');
            getline(datos, apellido, '|');
            getline(datos, ciclo, '|');
            getline(datos, mensualidad, '\n');

            float mensualidadf = stof(mensualidad);

            auto Alumno = new alumno(nombre, apellido, ciclo, mensualidadf);
            cout << Alumno->nombre << " "
                 << Alumno->apellido << " "
                 << Alumno->ciclo << " "
                 << Alumno->mensualidad << "\n";

        }
    } else cout << "no encontre el file ";


    datos.close();*/
}


int main() {

    leer();
    //escribir();


    return 0;
}
