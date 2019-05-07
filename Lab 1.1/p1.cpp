#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <cstring>
using namespace std;


class Alumno
{
public:
	char nombre[12], apPaterno[12], apMaterno[12];
        char carrera[15];
 int ciclo;
float mensualidad;

	Alumno(char enombre[12], char eapPaterno[12], char eapMaterno[12], char ecarrera[15], int eciclo, float emensualidad)
	{
		strcpy(nombre,enombre);
		strcpy(apPaterno,eapPaterno);
		strcpy(apMaterno,eapMaterno);
		strcpy(carrera,ecarrera);
		ciclo = eciclo;
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
	int registro=1;
	vector<Alumno> Avector;
	void load(string nombre)
	{
		ifstream datos;
		datos.open(nombre);
		char info[100];
		while(datos>>enombre>>eapPaterno>>eapMaterno>>ecarrera>>eciclo>>emensualidad)
		{
			Alumno *tempAlumno = new Alumno(enombre,eapPaterno,eapMaterno,ecarrera,eciclo,emensualidad);
			Avector.push_back(*tempAlumno);
			delete tempAlumno;
			cout<<"Registro: "<<registro<<endl<<"Nombre: "<<enombre<<endl<<"Apellido Paterno: "<<eapPaterno<<endl<<"Apellido Materno: "<<eapMaterno<<endl
			<<"Carrera: "<<ecarrera<<endl<<"Ciclo: "<<eciclo<<endl<<"Mensualidad: "<<emensualidad<<endl;
			registro++;
		}


	datos.close();
	}

void add(string nombre)
{
	char alumno[12], apPaterno[12], apMaterno[12], carrera[15];
	int ciclo;
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
	cout<<endl;
	Alumno *tempAlumno = new Alumno(alumno,apPaterno,apMaterno,carrera,ciclo,mensualidad);
	Avector.push_back(*tempAlumno);
	delete tempAlumno;
	if(datos.is_open())
	{
		datos << alumno << "\t" << apPaterno <<"\t" << apMaterno << "\t" << carrera << "\t"
		<< ciclo << "\t" << mensualidad;
	}
}


};

int main()
{

	string filename;
	filename = "datos.txt";
	Aula aula;
	aula.load(filename);
	aula.add(filename);
	return 0;
}
