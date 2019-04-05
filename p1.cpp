#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <cstring>
#include <algorithm>
using namespace std;


class Alumno
{
public:
	char nombre[12], apPaterno[12], apMaterno[12];
  char carrera[15];
 	int ciclo;
	float mensualidad;
	int codigo;

	Alumno(char enombre[12], char eapPaterno[12], char eapMaterno[12], char ecarrera[15], int eciclo, float emensualidad , int ecodigo)
	{
		strcpy(nombre,enombre);
		strcpy(apPaterno,eapPaterno);
		strcpy(apMaterno,eapMaterno);
		strcpy(carrera,ecarrera);
		ciclo = eciclo;
		codigo = ecodigo;
		mensualidad =emensualidad;
	};

};

class Aula
{
public:
	char filename[100];
	char enombre[12], eapPaterno[12], eapMaterno[12];
        char ecarrera[15];
				int eciclo;
				float emensualidad;
				int ecodigo;
	int registro=1;
	vector<Alumno> Avector;
vector<Alumno> load(string nombre)
	{
		ifstream datos;
		datos.open(nombre);
		char info[100];
		while(datos>>enombre>>eapPaterno>>eapMaterno>>ecarrera>>eciclo>>emensualidad>>ecodigo)
		{
			Alumno *tempAlumno = new Alumno(enombre,eapPaterno,eapMaterno,ecarrera,eciclo,emensualidad,ecodigo);
			Avector.push_back(*tempAlumno);
			delete tempAlumno;
			cout<<"Registro: "<<registro<<endl<<"Nombre: "<<enombre<<endl<<"Apellido Paterno: "<<eapPaterno<<endl<<"Apellido Materno: "<<eapMaterno<<endl
			<<"Carrera: "<<ecarrera<<endl<<"Ciclo: "<<eciclo<<endl<<"Mensualidad: "<<emensualidad<<endl<<"Codigo: "<<ecodigo<<endl;
			registro++;
		}


	datos.close();
	return Avector;
	}

void add(string nombre)
{
	char alumno[12], apPaterno[12], apMaterno[12], carrera[15];
	int ciclo, codigo;
	float mensualidad;
	ofstream datos;
	datos.open(nombre, ios::app);
	cout<<"Nombre: ";
	cin>>alumno;
	cout<<endl<<"Apellido Paterno: ";
	cin>>apPaterno;
	cout<<endl<<"Apellido Materno: ";
	cin>>apMaterno;
	cout<<endl<<"Carrera: ";
	cin>>carrera;
	cout<<endl<<"Ciclo: ";
	cin>>ciclo;
	cout<<endl<<"Mensualidad: ";
	cin>>mensualidad;
	cout<<endl<<"Codigo: ";
	cin>>codigo;
	Alumno *tempAlumno = new Alumno(alumno,apPaterno,apMaterno,carrera,ciclo,mensualidad,codigo);
	Avector.push_back(*tempAlumno);
	delete tempAlumno;
	if(datos.is_open())
	{
		datos << alumno << "\t" << apPaterno <<"\t" << apMaterno << "\t" << carrera << "\t"
		<< ciclo << "\t" << mensualidad << "\t"<<codigo<<endl;
	}
	datos.close();
}

void BulkInsert(vector<Alumno> &alumnos)
{
		ofstream nuevo;
		sort(alumnos.begin(),alumnos.end());
		nuevo.open("new.txt",ios::app);
		for(vector<Alumno>::iterator it = alumnos.begin(); it != alumnos.end(); ++it)
		{
			if(nuevo.is_open())
			{
					nuevo << (*it).codigo<<" "<<(*it).nombre<<" "<<(*it).apPaterno<<" "<<(*it).apMaterno<<" "<<(*it).carrera<<" "
					<<(*it).ciclo<<" "<<(*it).mensualidad<<" "<<endl;
			}

		}

}

};

void print(vector<Alumno> alumnos)
{
	for(vector<Alumno>::iterator it = alumnos.begin(); it != alumnos.end(); ++it)
	{
		cout<<(*it).nombre<<" "<<(*it).apPaterno<<" "<<(*it).apMaterno<<" "<<(*it).carrera<<" "<<(*it).ciclo<<" "<<(*it).mensualidad<<" "<<(*it).codigo<<endl;
	}
}

bool operator<(Alumno &x, Alumno &y)
{
	if(x.codigo < y.codigo)return true;
	else{return false;}
}



int main()
{
	vector<Alumno> alumnos;
	string filename;
	filename = "datos.txt";
	Aula aula;
	alumnos = aula.load(filename);
	aula.BulkInsert(alumnos);
	print(alumnos);

	return 0;
}
