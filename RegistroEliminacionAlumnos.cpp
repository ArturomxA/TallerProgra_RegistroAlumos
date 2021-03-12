#include<iostream>
#include <fstream>
using namespace std ;


int main(){
     int clave , opcion ,Bclave;
     char nombre[30] ,Nnombre[30];
     ifstream Leer;
     ofstream Guardar;
     ofstream Temp;
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
		break;
			   } /*Cierre del case 3*/
			  case 4:{
          	 Leer.open("Fichero.txt");
          	 Temp.open("Temp.txt");
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
          	 		cout<<"Eliminado"<<endl;
          	 		
          	 		
				   }/*Ciere del condicional*/
				   else{
				   	Temp<<nombre<<" "<<clave<<endl;
				   }
				   Leer>>nombre;
			}/*Cierre while para terminar de leer-econtrar*/
			if(encontrado==false)
			{
				cout<<"Clave no encontrada"<<endl;
			}/*segundo if fuera del while*/
		Leer.close();
		Temp.close();
		remove("Fichero.txt");
		rename("Temp.txt", "Fichero.txt");
		break;
			   } /*Cierre del case 4*/
			   case 5:{
          	 Leer.open("Fichero.txt");
          	 Temp.open("Temp.txt");
          	 Leer>>nombre;
          	 bool encontrado=false;
          	 cout<<"Ingrese clave a modificar"<<endl;
          	 cin>>Bclave;
          	 while(!Leer.eof()){
          	 	Leer>>clave;
          	 	if(clave==Bclave)
          	 	{
          	 		encontrado=true;
          	 		cout<<"Nombre..."<<nombre<<endl;
          	 		cout<<"Clave..."<<clave<<endl;
          	 		cout<<endl;
          	 		cout<<"Ingrese nuevo nombre:"<<endl;
          	 		cin>>Nnombre;
          	 		Temp<<Nnombre<<" "<<clave<<endl;
          	 		
				   }/*Ciere del condicional*/
				   else{
				   	Temp<<nombre<<" "<<clave<<endl;
				   }
				   Leer>>nombre;
			}/*Cierre while para terminar de leer-econtrar*/
			if(encontrado==false)
			{
				cout<<"Clave no encontrada"<<endl;
			}/*segundo if fuera del while*/
		Leer.close();
		Temp.close();
		remove("Fichero.txt");
		rename("Temp.txt", "Fichero.txt");
		break;
			   } /*Cierre del case 5*/
		 
         }/*Cierre del switch*/
     
     }/*Cierre del ciclo while*/
     
}


