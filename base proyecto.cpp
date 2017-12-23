#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <process.h>
#include <windows.h>
#include <iostream.h>
#include "cPass.h"
#include <fstream.h>
#include <windows.h>

using namespace std;
void cPass(char *pass, int longitud);
int iniciado = 0,intentos = 0,primeravez=0;
char userin[20];//usuario activo
char privi[20];//nivel de usuario
int codeprivi;//nivel de usuario

class usuarios
{
public:
int nomina,privilegios;
char usuario [20], contrasena[20];
void inicializar();
void capturar();
void mostrar();
void buscar1();
void buscar2();
void modificar();
void eliminar();
}u;



int main() 
{
inicio:
int continuar = 1,opc;
cout<<"================================================================================================================"<<endl;
cout<<endl;
cout<<"           uY.    uYjSUi    Ljr     JU  uur YES    OZY       JY7     uj,   .Yu    7ui::vX..uu.   7POSi"<<endl;        
cout<<"          @@@B   ,@B@B@B@8  @B@r   B@Bi @B@ @B@B   B@M       B@BL   @B@v   B@B@   @B@B@B@:Y@@: r@@@B@B@"<<endl;
cout<<"         L@@B@P   B@:   B@S B@B@  M@@@  B@P 1@@@@. @Bu       @B@@  MB@B:  j@B@BS    i@B   r@B  @BP   U."<<endl;
cout<<"         B@  B@.  @Bi   BB@ MB@B@S@B@B  @BS uB@:@BLB@7 G@B@B M@B@BSB@B@.  @B  @B.   7B@   rB@ iB@"<<endl;
cout<<"        B@B@B@@@  B@i  :B@L @@viB@N.@@  @@P X@B  @@@BL @BMM7 @Bj:@BO @B, @B@B@@@@   1@B.  Y@B  @B@. .M;"<<endl;
cout<<"       u@BXjU2@BZ @B@B@B@Y  @BB @B :@@i @B@ @B@   @B@S       B@@ B@ :B@irB@5ujFB@B  BB@i  OB@: .@B@B@B@"<<endl;
cout<<"       :::    ,:: :::i:.    ::.  :  ::  ::. .::    ::        ::.  :  :: .:,    ::r  .::   .::    .rLi"<<endl;
cout<<endl;
cout<<" Desarrollado por: Daniel Arturo Fernandez Raygoza #13310091 y Aldo Ballesteros Mathias #13310029   Grupo: B113"<<endl;
cout<<"================================================================================================================"<<endl;
cout<<"Este programa facilitara la administracion y control de su tienda, identifiquese para iniciar sesion."<<endl<<endl;

if (iniciado==0)
{
u.inicializar();
}

do
{
cout<<endl<<"Elige una opcion del menu: "<<endl<<"1) Control de Inventarios"<<endl<<"2) Control de ventas"<<endl<<"3) Gestion de usuarios"<<endl<<"4) Cerrar sesion"<<endl<<"5) Salir"<<endl;
cin>>opc;
switch(opc)
{
     
case 1: //Inventarios
if (codeprivi==1 | codeprivi==2) 
{
                  
                  
                  
                  
                  
                  
}
else
{
cout<<endl<<"No tiene los privilegios suficientes para acceder a esta seccion del programa,consulte al administrador"<<endl;
}        
continuar = 1;    
break;      

case 2: //Ventas
if (codeprivi==1 | codeprivi==2 | codeprivi==3) 
{
                  
                  
                  
                  
                  
                  
}
else
{
cout<<endl<<"No tiene los privilegios suficientes para acceder a esta seccion del programa,consulte al administrador"<<endl;
}           
continuar = 1;    
break;   

case 3: //Usuarios
if (codeprivi==1)
{
                  
                  
                  
                  
                  
                  
}
else
{
cout<<endl<<"No tiene los privilegios suficientes para acceder a esta seccion del programa,consulte al administrador"<<endl;
}                
continuar = 1;    
break;   
           
case 4:
iniciado = 0;
system("cls");
goto inicio;
break;
           
case 5:
continuar =0;
exit(0);
break;

default:
cout<<endl<<"Opcion invalida, intente de nuevo"<<endl;
break;
}
}
while (continuar == 1);
}

////////////////////////////////

void usuarios::inicializar()
{   
fstream b("Usuarios.admma",ios::in); //tambien se puede usar ios::out
if (!b.good())
{
cout <<"\nHemos detectado que es la primera vez que usa el programa, a continuacion introduzca lo que se le pide:\n\n";
primeravez=1;
capturar();
system("cls");
main();
}
else
{
char user [20];
char contra [20];
cout<<"Introduzca su usuario: "; cin>>user;
cout<<"Ingrese la contrasena: "; cPass(contra, 20);
while(!b.eof())
{
b.read ((char*)&u,sizeof(u));
if (b.eof())
break;
if( strcmp(contra,u.contrasena) == 0 && strcmp(user,u.usuario)== 0)
{
system("color 0A");
cout<<endl<<"Contrasena correcta, el programa comenzara en breve."<<endl;
iniciado = 1;
strcpy(userin,user);
switch (u.privilegios)
{
case 1:
codeprivi=1;
strcpy(privi,"Administrador");
break;     
case 2:
codeprivi=2;
strcpy(privi,"Encargado");
break;    
case 3:
codeprivi=3;
strcpy(privi,"Vendedor");
break;      
}
cout<<"Sesion iniciada con el usuario: "<<userin<<" el cual tiene privilegios de: "<<privi<<endl;
Sleep(2000);
system("cls");
main();
}
else
{
system("color 04");
iniciado = 0;
intentos = intentos + 1;
cout<<endl<<endl<<"Contrasena incorrecta, te quedan "<<3-intentos<<" intentos."<<endl;
if(intentos >= 3)
{
cout<<endl<<"El programa se cerrara por seguridad en unos instante"<<endl;
Sleep(2500);
exit(0);
}
cout<<endl<<"Podras intentarlo de nuevo en unos momentos"<<endl;
Sleep (2500); 
system ("cls");
main();
}
}
}
cout<<endl;
b.close(); 
}


void usuarios :: capturar()
{
char contra[20];
cout<<"========================================Captura de Nuevos Usuarios=============================================="<<endl;
cout<<"Introduce el  Usuario: "; cin>>u.usuario;
cout<<"Introduce su contrasena: "; cin>>u.contrasena;
cout<<"Introduce su numero de nomina: "; cin>>u.nomina;
if (primeravez==1)
{
u.privilegios = 1;
}
else
{
cout<<"Selecciona el nivel de privilegios del usuario:"<<endl<<"1) Administrador"<<endl<<"2) Encargado"<<endl<<"3) Vendedor"<<endl;
cin>>u.privilegios;
}
cout<<"================================================================================================================"<<endl;
ofstream c("Usuarios.admma", ios::app);
c.write((char*)&u,sizeof(u));
c.close();
Sleep(2000);
}

