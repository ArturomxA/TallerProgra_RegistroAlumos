#include<iostream>
#include <fstream>
using namespace std ;


int main(){
     int clave , opcion ,Bclave;
     char nombre[100];
     ifstream Leer;
     ofstream Guardar;
     ofstream temporal;
     Guardar.open("Fichero.txt" ,ios::app);
     while(true){

         cout<<"1.- Guardar"<<endl;
         cout<<"2.- Leer"<<endl;
         cout<<"3.- Buscar"<<endl;
         cout<<"4.- Eliminar"<<endl;
         cout<<"5.- Ingrese opcion"<<endl;
         cin>>opcion;
         switch (opcion)
         {
          case 1: {
              cout<<"Ingrese un nombre"<<endl;
              cin>>nombre;

              
              cout<<"Ingresa tu clave"<<endl;
              cin>>clave;
              Guardar<<nombre<<" "<<clave<<endl;
              break;
             }/*Cierre del case1*/
          case 2:{
              Leer.open("Fichero.txt");
              Leer>>nombre;
              while (!Leer.eof())/*final del fichero hasta que devuelva un valor*/  
              {
                  Leer>>clave;
                  cout<<"Nombre:  "<<nombre<<endl;
                  cout<<"Clave:  "<<clave<<endl;
                  cout<<endl;
                  Leer>>nombre;
                 
              }/*Fin de while en final*/
              Leer.close();
               break;

          }/*Cierre del case2*/ 
          case 3:{
          	 Leer.open("Fichero.txt");
          	 Leer>>nombre;
          	 bool encontrado=false;
          	 cout<<"Ingrese clave a buscar"<<endl;
          	 cin>>Bclave;
          	 while(!Leer.eof()){
          	 	Leer>>clave;
          	 	if(clave==Bclave)
          	 	{
          	 		encontrado=true;
          	 		cout<<"Nombre..."<<nombre<<endl;
          	 		cout<<"Clave..."<<clave<<endl;
          	 		cout<<endl;
          	 		
				   }/*Ciere del condicional*/
				   Leer>>nombre;
			}/*Cierre while para terminar de leer-econtrar*/
			if(encontrado==false)
			{
				cout<<"Clave no encontrada"<<endl;
			}/*segundo if fuera del while*/
		Leer.close();
		
			   } /*Cierre del case 3*/
			   case 4:{
          	 Leer.open("Fichero.txt");
            temporal.open("Temporal.txt");
          	 Leer>>nombre;
          	 bool encontrado=false;
          	 cout<<"Ingrese clave a eliminar"<<endl;
          	 cin>>Bclave;
          	 while(!Leer.eof()){
          	 	Leer>>clave;
          	 	if(clave==Bclave)
          	 	{
          	 		encontrado=true;
          	 		cout<<"Nombre..."<<nombre<<endl;
          	 		cout<<"Clave..."<<clave<<endl;
          	 		cout<<endl;
          	 		cout<<"Alumno elimnado"<<endl;
          	 		
				   }/*Ciere del condicional*/
				   else{
				   	Guardar<<nombre<<" "<<clave<<endl;
				   }/*Cierre del else*/
				   Leer>>nombre;
			}/*Cierre while para terminar de leer-econtrar*/
			if(encontrado==false)
			{
				cout<<"Clave no encontrada"<<endl;
			}/*segundo if fuera del while*/
		Leer.close();
		temporal.close();
		remove("Fichero.txt");
		rename("Temp.txt" , "Fichero.txt");
		
			   } /*Cierre del case 4*/
			
		 
         }/*Cierre del switch*/
     
     }/*Cierre del ciclo while*/
     
	 }


