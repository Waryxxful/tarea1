#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


void printArray(string A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}
  






int main() {
    struct Aregistro
{   
    string nombre;
    string apellido;
    int paralelo;
    int dia;
    int mes;
    int anio;
    string rol;
    int ppm;
    float precision;
};


    struct registro
{
    int dia;
    int mes;
    int anio;
    char rol[12];
    int ppm;
    float precision;
};
    Aregistro re[1000];
    char c;
    int recorredor = 0;
    ifstream fp;
    char rol[12];
    string  nombre, apellido;
    int paralelo;
    fp.open("estudiantes.txt");
    if (!fp.is_open()){
        cerr << " el archvio no se pudo abrir " << endl;
        return 1 ;
    }
    while((c= fp.tellg()) != EOF ){ 
        fp >> rol;
        fp >> nombre;
        fp >> apellido;
        fp >> paralelo;
        re[recorredor].nombre = nombre;
        re[recorredor].apellido = apellido;
        re[recorredor].rol = rol;
        re[recorredor].paralelo = paralelo;
        recorredor = recorredor + 1;
        };

                                     //lee el binario 
   registro Re;
   int i, j, q, t, d, m, a, cont;
   string NomMax;
   ifstream in;
   in.open("registros.dat", ios::binary);
   if(!in.is_open()){
    cerr <<  "error no se pudo abrir el archivo registro.dat" << endl;
    exit(1);
   }
   in.read((char*)&i,sizeof(int));
   cout << "cantidad de registros = " << i << endl;
   cout << "ingrese cantidad de consultas" << endl;
   cin >> q;
   string* Nombres = new string[q];

   for( j = 0; j < q; j++)
   {
        cout << "ingrese consulta" << endl;
        cin >> t;
        cin >> d;
        cin >> m;
        cin >> a;
        int maximo = -1;
        float Pre = -1.0;
        string rolm;
        while(in.read((char*)&Re,sizeof(registro))){
        if (d == -1 && t == 1 && Re.anio == a) 
        {
            if (Re.ppm > maximo)
            {
            maximo = Re.ppm;
            rolm = Re.rol;
            }
        
        }
        else if (d !=-1 && t == 1)
        {
            if (Re.mes == m && Re.dia == d && Re.ppm > maximo)
            {
                maximo = Re.ppm;
                rolm = Re.rol;
            }
            
        }
        else if (d == -1 && t == 0 && Re.anio == a)
        {
            if (Re.precision > Pre) 
            {
                Pre = Re.precision;
                rolm = Re.rol;
            }
            
        }
        else if (d != -1 && t == 0 && Re.anio == a)
        {
            if (Re.mes == m && Re.dia == d && Re.precision > Pre )
            {
                Pre = Re.precision;
                rolm = Re.rol;
            }
            
        }
        
        /* se podria abrir el txt aqui y buscar directamente */
        for ( cont = 0; cont < recorredor; cont++)
        {
            if (rolm == re[cont].rol)
            {
                NomMax = re[cont].nombre + " " + re[cont].apellido;
                cout << "aqui" << endl;
                break;
            }   
        }
        Nombres[j] = NomMax;
        }
    }
    printArray(Nombres, q);
    delete [] Nombres;
    
    in.close();
return 0;
 }