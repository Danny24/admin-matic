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
#include <time.h>


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

class inventario
{
public:
int exist;
float precio;
char folio[20], nombre[20]; 
void capturar_i();
void mostrar_i();
void buscar_ip();
void buscar_if();
void modificar_ipr();//modificar precio
void modificar_ie();//modificar existencia
void modificar_it();//modificar todo
void eliminar_i();
}x;

int main() 
{
inicio:
int continuar = 1,opc;
cout<<"======================================================================"<<endl;
cout<<endl;
cout<<"   B@       @@                           @@    B@                     "<<endl;        
cout<<"  .@B.      B@            B1             @B7   @B             Bu      "<<endl;
cout<<"  @B@B      @B                           B@B  @B@        F@1          "<<endl;
cout<<"  Bi7@  j@BBB@ MB@B@BMB@, BS @BMB@1      @B@7.@@B 7@ON@E @B@7 @U @B@B@"<<endl;
cout<<" i@  Br GB  @@ O@  B@ 7B: @q B@ .@S @B@8 B@7@@FO@ .q  @B i@i  @5 @@   "<<endl;
cout<<" BBBB@@ 5@  B@ OB  @B ;@. BP @B  @2 :ii: @B B@ BB Y@r,B@ iB:  @1 @B   "<<endl;
cout<<";B5  0@ rBu,@B 0@  BB iB. @2 B@  B1      @@ ,j B@ j@, @M ,@Z  @Y B@:O@"<<endl;
cout<<endl;
cout<<" Desarrollado por:"<<endl; 
cout<<"   *Daniel Arturo Fernandez Raygoza #13310091"<<endl;
cout<<"   *Aldo Ballesteros Mathias        #13310029"<<endl;
cout<<"    Grupo: B113  Ingenieria Mecatronica-CETI"<<endl;
cout<<"======================================================================"<<endl;
cout<<"Este programa facilitara la administracion y control de su tienda,"<<endl; 
cout<<"Identifiquese para iniciar sesion y poder usar el programa."<<endl<<endl;

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
int opcion, cont=1;
system("cls");
do
{
cout<<"Seleccione una opcion:\n1)Capturar Inventario\n2)Mostrar Inventario\n3)Buscar\n4)Modificar\n5)Eliminar\n6)Regresar a menu principal\n";
cin>>opcion;
switch(opcion)
{
case 1:
system("cls");
x.capturar_i();
cont=1;
break;

case 2:
system("cls");
x.mostrar_i();
cont=1;
break;

case 3:
int op,b;
system("cls");
do
{
cout<<"Buscar por:\n1)Producto\n2)Folio\n3)Regresar a menu\n";
cin>>op;
switch(op)
{
case 1:
system("cls");
x.buscar_ip();
b=1;
break;

case 2:
system("cls");
x.buscar_if();
b=1;
break;

case 3:
system("cls");
b=0;
break;

default:
cout<<endl<<"Opcion invalida, intente de nuevo."<<endl<<endl;
break;
}
}while(b==1);
cont=1;
break;

case 4:
int o,n;
system("cls");
do
{
cout<<"Modificar:\n1)Precio\n2)Existencias\n3)Todo\n4)Regresar a menu\n";
cin>>o;
switch(o)
{
case 1:
system("cls");
x.modificar_ipr();
n=1;
break;

case 2:
system("cls");
x.modificar_ie();
n=1;
break;

case 3:
system("cls");
x.modificar_it();
n=1;
break;

case 4:
system("cls");
n=0;
break;

default:
cout<<endl<<"Opcion invalida, intente de nuevo."<<endl<<endl;
break;
}
}while(n==1);
cont=1;
break;

case 5:
system("cls");
x.eliminar_i();
cont=1;
break;

case 6:
system("cls");       
cont=0;
goto inicio; 
break;

default:
cout<<endl<<"Opcion invalida, intente de nuevo."<<endl<<endl;
break;
}
}while(cont==1);
}
else
{
cout<<endl<<"No tiene privilegios para acceder a esta seccion del programa."<<endl;
}        
continuar = 1;    
break;      

case 2: //Ventas
if (codeprivi==1 | codeprivi==2 | codeprivi==3) 
{
                  
                  
                  
                  
                  
                  
}
else
{
cout<<endl<<"No tiene privilegios para acceder a esta seccion del programa."<<endl;
}           
continuar = 1;    
break;   



case 3: //Usuarios
if (codeprivi==1)
{
int opc,c;
system ("cls");
do
{
cout<<"Elige una opcion del menu:"<<endl<<"1) Agregar Usuario"<<endl<<"2) Mostrar usuarios"<<endl<<"3) Buscar Usuario"<<endl<<"4) Modificar Usuario"<<endl<<"5) Elimianar Usuario"<<endl<<"6) Regresar al menu principal"<<endl; 
cin>>opc;

switch(opc)
{
case 1:
system ("cls");
u.capturar();
c = 1;
break;

case 2:
system ("cls");
u.mostrar();
c = 1;
break;

case 3:

c = 1;
break;

case 4:

c = 1;
break;
      
case 5:

c = 1;
break; 
      
case 6:
system ("cls");
c = 0;
goto inicio;
break;    

default:
cout<<endl<<"Opcion invalida, intente de nuevo"<<endl<<endl;
break;        
                  
}                 
}                  
while (c == 1);                  
}
else
{
cout<<endl<<"No tiene privilegios para acceder a esta seccion del programa."<<endl;
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
fstream f("Usuarios.admma", ios::in); //tambien se puede usar ios::out
if (!f.good())
{
cout <<"\nHemos detectado que es la primera vez que usa el programa,"<<endl;
cout<<"a continuacion introduzca lo que se le pide para registrarse:\n\n"<<endl;
primeravez=1;
capturar();
system("cls");
primeravez=0;
main();
}
else
{
char user [20];
char contra [20];
cout<<"Introduzca su usuario: "; cin>>user;
cout<<"Ingrese la contrasena: "; cPass(contra,20);
while(!f.eof())
{              
f.read ((char *)&u,sizeof(u));
if (f.eof())
break;
if( strcmp(contra,u.contrasena) == 0 && strcmp(user,u.usuario) == 0)
{
system("color 0A");
cout<<endl<<"Contrasena correcta, el programa comenzara en breve."<<endl;
iniciado = 1;
intentos = 0;
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
cout<<"Sesion iniciada con el usuario: "<<userin<<endl;
cout<<"El cual tiene privilegios de: "<<privi<<endl;
Sleep(2000);
system("cls");
main();
}
}
}
cout<<endl;
f.close(); 
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


void usuarios :: capturar()
{
char contra[20];
cout<<"========================Captura de Nuevos Usuarios===================="<<endl;
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
cout<<endl<<"Usuario registrado correctamente"<<endl;
cout<<"======================================================================"<<endl;
ofstream c("Usuarios.admma", ios::app);
c.write((char*)&u,sizeof(u));
c.close();
//Sleep(2000);
//system("cls");
}

void usuarios :: mostrar()
{
cout<<"=========================Mostrar los Usuarios========================="<<endl;
fstream b("Usuarios.admma",ios::in); //tambien se puede usar ios::out
if (!b.good())
cout <<"\nERROR: El archivo de Empleados no existe. \n";
else
while(!b.eof())
{
b.read ((char*)&u,sizeof(u));
if (b.eof())
break;
cout<<endl;
cout<<"El nombre de usuario es: "<<u.usuario<<endl;
cout<<"La contrasena es: "<<u.contrasena<<endl;
cout<<"El numero de nomina es: "<<u.nomina<<endl;
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
cout<<"Los privilegios son de: "<<privi<<endl<<endl;;
cout<<"----------------------------------------------------------------------";
}
cout<<endl;
b.close();
cout<<"======================================================================"<<endl<<endl;
}










////////////////////////////////////////

void inventario::capturar_i()
{
cout<<"==========================Captura de Inventario======================="<<endl;
cout<<"Folio: "; cin>>x.folio;
cout<<"Producto: "; cin>>x.nombre;
cout<<"Precio: "; cin>>x.precio;
cout<<"Existencias: "; cin>>x.exist;
ofstream b("Inventario.admma", ios::app);
b.write((char*)&x,sizeof(x));
b.close();
cout<<endl<<"Elemento agregado correctamente al inventario"<<endl;
cout<<"======================================================================"<<endl<<endl;
}

void inventario::mostrar_i()
{
fstream e("Inventario.admma",ios::in|ios::out);
if(!e.good())
{
cout<<endl<<"No hay inventario"<<endl;
}
else
{
cout<<"===========================Mostrar Inventario========================="<<endl;
cout<<endl<<"   Folio           Producto           Precio      Existencias"<<endl;
while(!e.eof())
{
e.read((char*)&x,sizeof(x));
if(e.eof())
break;
cout<<"     "<<x.folio<<"             "<<x.nombre<<"               "<<x.precio<<"        "<<x.exist<<endl;
}
}
cout<<endl<<"======================================================================"<<endl<<endl;
e.close();
}

void inventario::buscar_ip()
{
cout<<"===================Busqueda en inventario por producto================"<<endl;
int band=0;
char buscar[20];
cout<<endl<<"Producto a buscar: "; cin>>buscar;
fstream d("Inventario.admma", ios::in|ios::out);
if(!d.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl<<endl;
}
else
{
while(!d.eof())
{
d.read((char*)&x,sizeof(x));
if(d.eof())
break;
if(strcmp(buscar,x.nombre)==0)
{
cout<<endl<<"Folio: "<<x.folio<<endl;
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Existencias: "<<x.exist<<endl<<endl;
band=1;
}
}
if(band==0)
cout<<endl<<"Producto no encontrado"<<endl<<endl;
}
d.close();
cout<<"======================================================================"<<endl;
}

void inventario::buscar_if()
{
cout<<"====================Busqueda en inventario por folio=================="<<endl; 
int band=0;
char buscar[20];
cout<<endl<<"Folio a buscar: "; cin>>buscar;
fstream f("Inventario.admma", ios::in|ios::out);
if(!f.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl<<endl;
}
else
{
while(!f.eof())
{
f.read((char*)&x,sizeof(x));
if(f.eof())
break;
if(strcmp(buscar,x.folio)==0)
{
cout<<endl<<"Folio: "<<x.folio<<endl;
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Existencias: "<<x.exist<<endl<<endl;
band=1;
}
}
if(band==0)
cout<<endl<<"Folio no encontrado"<<endl<<endl;
}
f.close();
cout<<"======================================================================"<<endl;
}

void inventario::modificar_ipr()
{
cout<<"====================Modificar Precios en Inventario==================="; 
int res;
int pos=0;
int band=0;
char buscar[20];
int opc;
fstream g("Inventario.admma", ios::in|ios::out);
cout<<endl<<"Buscar por:"<<endl<<"1)Producto"<<endl<<"2)Folio"<<endl;
cin>>opc;
switch(opc)
{
case 1:
cout<<endl<<"Producto a buscar: "; cin>>buscar;
if(!g.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl<<endl;
}
else
{
while(!g.eof())
{
g.read((char*)&x,sizeof(x));
if(g.eof())
break;
pos=pos+sizeof(x);
if(strcmp(buscar,x.nombre)==0)
{
cout<<endl<<"Folio: "<<x.folio<<endl;
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"Modificar precio?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
{
cout<<endl<<"Precio: "; cin>>x.precio;
g.seekp(pos-sizeof(x),ios::beg);
g.write((char*)&x,sizeof(x)); 
cout<<endl<<"Modificado Correctamente."<<endl<<endl;
band =1;
}
else
{
cout<<endl<<"Modificacion Cancelada."<<endl<<endl;
band=1;
}
}
}
}
if(band==0)
cout<<endl<<"Producto no encontrado."<<endl<<endl;
break;

case 2:
cout<<endl<<"Folio a buscar: "; cin>>buscar;
if(!g.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl<<endl;
}
else
{
while(!g.eof())
{
g.read((char*)&x,sizeof(x));
if(g.eof())
break;
pos=pos+sizeof(x);
if(strcmp(buscar,x.folio)==0)
{
cout<<endl<<"Folio: "<<x.folio<<endl;
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"Modificar precio?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
{
cout<<endl<<"Precio: "; cin>>x.precio;
g.seekp(pos-sizeof(x),ios::beg);
g.write((char*)&x,sizeof(x)); 
cout<<endl<<"Modificado Correctamente."<<endl<<endl;
band=1;
}
else
{
cout<<endl<<"Modificacion Cancelada."<<endl<<endl;
band=1;
}
}
}
}
if(band==0)
cout<<endl<<"Folio no encontrado."<<endl<<endl;
break;

default:
cout<<endl<<"Opcion invalida, intente de nuevo."<<endl<<endl;
break;
}
g.close();
cout<<"======================================================================"<<endl;
}

void inventario::modificar_ie()
{
int res;
int pos=0;
int band=0;
char buscar[20];
int opc;
fstream j("Inventario.admma", ios::in|ios::out);
cout<<endl<<"Buscar por:"<<endl<<"1)Producto"<<endl<<"2)Folio"<<endl;
cin>>opc;
switch(opc)
{
case 1:
cout<<endl<<"Producto a buscar: "; cin>>buscar;
if(!j.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl;
}
else
{
while(!j.eof())
{
j.read((char*)&x,sizeof(x));
if(j.eof())
break;
pos=pos+sizeof(x);
if(strcmp(buscar,x.nombre)==0)
{
cout<<endl<<"Folio: "<<x.folio<<endl;
cout<<endl<<"Producto: "<<x.nombre<<endl;
cout<<endl<<"Precio: "<<x.precio<<endl;
cout<<endl<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"¿Modificar existencia?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
{
cout<<endl<<"Existencia: "<<endl;
cin>>x.exist;
j.seekp(pos-sizeof(x),ios::beg);
j.write((char*)&x,sizeof(x)); 
}
else
break;
band=1;
}
}
}
if(band==0)
cout<<endl<<"Producto no encontrado"<<endl;
break;

case 2:
cout<<endl<<"Folio a buscar: "; cin>>buscar;
if(!j.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl;
}
else
{
while(!j.eof())
{
j.read((char*)&x,sizeof(x));
if(j.eof())
break;
pos=pos+sizeof(x);
if(strcmp(buscar,x.folio)==0)
{
cout<<endl<<"Folio: "<<x.folio<<endl;
cout<<endl<<"Producto: "<<x.nombre<<endl;
cout<<endl<<"Precio: "<<x.precio<<endl;
cout<<endl<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"¿Modificar existencia?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
{
cout<<endl<<"Existencia: "<<endl;
cin>>x.exist;
j.seekp(pos-sizeof(x),ios::beg);
j.write((char*)&x,sizeof(x)); 
}
else
break;
band=1;
}
}
}
if(band==0)
cout<<endl<<"Folio no encontrado"<<endl;
break;

default:
cout<<endl<<"Opcion invalida, intente de nuevo"<<endl;
break;
}
j.close();
}

void inventario::modificar_it()
{
int res;
int pos=0;
int band=0;
char buscar[20];
int opc;
fstream h("Inventario.admma", ios::in|ios::out);
cout<<endl<<"Buscar por:"<<endl<<"1)Producto"<<endl<<"2)Folio"<<endl;
cin>>opc;
switch(opc)
{
case 1:
cout<<endl<<"Producto a buscar: "; cin>>buscar;
if(!h.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl;
}
else
{
while(!h.eof())
{
h.read((char*)&x,sizeof(x));
if(h.eof())
break;
pos=pos+sizeof(x);
if(strcmp(buscar,x.nombre)==0)
{
cout<<endl<<"Folio: "<<x.folio<<endl;
cout<<endl<<"Producto: "<<x.nombre<<endl;
cout<<endl<<"Precio: "<<x.precio<<endl;
cout<<endl<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"¿Modificar todo?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
{
cout<<endl<<"Folio: "<<endl;
cin>>x.folio;
cout<<endl<<"Producto: "<<endl;
cin>>x.nombre;
cout<<endl<<"Precio: "<<endl;
cin>>x.precio;
cout<<endl<<"Existencia: "<<endl;
cin>>x.exist;
h.seekp(pos-sizeof(x),ios::beg);
h.write((char*)&x,sizeof(x)); 
}
else
break;
band=1;
}
}
}
if(band==0)
cout<<endl<<"Producto no encontrado"<<endl;
h.close();
break;

case 2:
cout<<endl<<"Folio a buscar: "; cin>>buscar;
if(!h.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl;
}
else
{
while(!h.eof())
{
h.read((char*)&x,sizeof(x));
if(h.eof())
break;
pos=pos+sizeof(x);
if(strcmp(buscar,x.folio)==0)
{
cout<<endl<<"Folio: "<<x.folio<<endl;
cout<<endl<<"Producto: "<<x.nombre<<endl;
cout<<endl<<"Precio: "<<x.precio<<endl;
cout<<endl<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"¿Modificar todo?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
{
cout<<endl<<"Folio: "<<endl;
cin>>x.folio;
cout<<endl<<"Producto: "<<endl;
cin>>x.nombre;
cout<<endl<<"Precio: "<<endl;
cin>>x.precio;
cout<<endl<<"Existencia:"<<endl;
cin>>x.exist;
h.seekp(pos-sizeof(x),ios::beg);
h.write((char*)&x,sizeof(x)); 
}
else
break;
band=1;
}
}
}
if(band==0)
cout<<endl<<"Folio no encontrado"<<endl;
break;

default:
cout<<endl<<"Opcion invalida, intente de nuevo"<<endl;
break;
}
h.close();
}

void inventario::eliminar_i()
{
char buscar[20];
int band=0;
int res;
int opc;
fstream k("Inventario.admma",ios::in|ios::out);
ofstream a("auxiliar.admma",ios::app);
cout<<endl<<"Buscar por:"<<endl<<"1)Producto"<<endl<<"2)Folio"<<endl;
cin>>opc;
switch(opc)
{
case 1:
cout<<endl<<"Producto a buscar: "; cin>>buscar;
if(!k.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl;
}
else
{
while(!k.eof())
{
k.read((char*)&x,sizeof(x));
if(k.eof())
break;
if(strcmp(buscar,x.nombre)==0)
{
band=1;
cout<<endl<<"Folio: "<<x.folio<<endl;
cout<<endl<<"Producto: "<<x.nombre<<endl;
cout<<endl<<"Precio: "<<x.precio<<endl;
cout<<endl<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"¿Eliminar?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
cout<<"eliminando\n";
else
a.write((char*)&x,sizeof(x));
}
else
a.write((char*)&x,sizeof(x));
}
k.close();
a.close();
remove("Inventario.admma");
rename("auxiliar.admma","Inventario.admma");
}
if(band==0)
cout<<endl<<"Producto no encontrado"<<endl;
break;

case 2:
cout<<endl<<"Folio a buscar: "; cin>>buscar;
if(!k.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl;
}
else
{
while(!k.eof())
{
k.read((char*)&x,sizeof(x));
if(k.eof())
break;
if(strcmp(buscar,x.folio)==0)
{
band=1;
cout<<endl<<"Folio: "<<x.folio<<endl;
cout<<endl<<"Producto: "<<x.nombre<<endl;
cout<<endl<<"Precio: "<<x.precio<<endl;
cout<<endl<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"¿Eliminar?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
cout<<"eliminando\n";
else
a.write((char*)&x,sizeof(x));
}
else
a.write((char*)&x,sizeof(x));
}
k.close();
a.close();
remove("Inventario.admma");
rename("auxiliar.admma","Inventario.admma");
}
if(band==0)
cout<<endl<<"Folio no encontrado"<<endl;
break;
}
}          
           








