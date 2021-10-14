#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <process.h>
#include <windows.h>
#include <iostream.h>
#include "cPass.h"
#include <fstream.h>
#include <windows.h>
#include <time.h>

void gotoxy(int x, int y) //permite posicionar el cursor en la ventana del programa
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}



using namespace std;
void cPass(char *pass, int longitud);
int iniciado = 0,intentos = 0,primeravez=0;
char userin[20];//usuario activo
char privi[20];//nivel de usuario
int codeprivi;//nivel de usuario
int totalarticulosg;
float preciototalg;

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

class ventas:inventario
{
public:
int numventa;
int totalarticulos;
float subtotal;
float preciototal;
char fechayhora[50]; 
int exist;
float precio;
char folio[20], nombre[20];     
char userin1[20];
char privi1[20]; 
void vender();
void agregarporfolio();
void agregarpornombre();
void eliminar();
void modicant();
void terminarventa();
void mostrarhist();
void buscarventa();
void buscarventa_u();
void eliminarhist();
void cancelarventa();
}v;

int main() 
{
inicio:
system("color 01");
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
Sleep (2000);
system ("cls");
goto inicio;
}        
continuar = 1;    
break;      

case 2: //Ventas
if (codeprivi==1 | codeprivi==2 | codeprivi==3) 
{
int opc2,q;
system ("cls");
do
{
cout<<"Elige una opcion del menu:"<<endl<<"1) Hacer Venta"<<endl<<"2) Cancelar Venta"<<endl<<"3) Consultar Historial de Ventas"<<endl<<"4) Buscar en el Historial de Ventas"<<endl<<"5) Borrar todo el Historial de Ventas"<<endl<<"6) Regresar al menu principal"<<endl; 
cin>>opc2;

switch(opc2)
{
case 1:
system ("cls");
v.vender();
q = 1;
break;

case 2:
if( codeprivi != 3)
{ 
system ("cls");
v.cancelarventa();
}
else
{
cout<<endl<<"No tiene privilegios para acceder a esta seccion del programa."<<endl;
Sleep (2000);
system ("cls");
}
q = 1;
break;

case 3:
system ("cls");
v.mostrarhist();
q = 1;
break;

case 4:
int g, m4;
system("cls");
do
{
cout<<"Selecciona el criterio de busqueda:"<<endl<<"1) Usuario que hizo la Venta"<<endl<<"2) Numero de Venta"<<endl<<"3) Regresar"<<endl;
cin>>m4;
switch (m4)
{
       
case 1:
system ("cls");
v.buscarventa_u();
g = 1;
break;

case 2:
system ("cls");
v.buscarventa();  
g = 1;
break;

case 3:
//SAlir del submenu
system ("cls");
g = 0;
break;

default:
cout<<endl<<"Opcion invalida, intente de nuevo."<<endl<<endl;
g = 1;
break;
}
cout<<endl;
}
while (g==1);
system("cls");
q = 1;
break;

      
case 5:
if (codeprivi == 1)
{
system ("cls");
v.eliminarhist();
}
else
{
cout<<endl<<"No tiene privilegios para acceder a esta seccion del programa."<<endl;
Sleep (2000);
system ("cls");
}
q = 1;
break; 
      
case 6:
system ("cls");
q = 0;
goto inicio;
break;    

default:
cout<<endl<<"Opcion invalida, intente de nuevo"<<endl<<endl;
break;        
                  
}                 
}                  
while (q == 1);                                                    
}
else
{
cout<<endl<<"No tiene privilegios para acceder a esta seccion del programa."<<endl;
Sleep (2000);
system ("cls");
goto inicio;
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
cout<<"Elige una opcion del menu:"<<endl<<"1) Agregar Usuario"<<endl<<"2) Mostrar usuarios"<<endl<<"3) Buscar Usuario"<<endl<<"4) Modificar Usuario"<<endl<<"5) Eliminar Usuario"<<endl<<"6) Regresar al menu principal"<<endl; 
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
int f, m2;
system ("cls");
do
{
cout<<"Selecciona el criterio de busqueda:"<<endl<<"1)Nombre"<<endl<<"2)Nomina"<<endl<<"3)Regresar"<<endl;
cin>>m2;
switch (m2)
{
       
case 1:
u.buscar1();
f = 1;
break;

case 2:
u.buscar2();       
f = 1;
break;

case 3:
//SAlir del submenu
system ("cls");
f = 0;
break;

default:
cout<<"Opcion invalida, intente de nuevo."<<endl<<endl;
f = 1;
break;
}
}
while (f==1);
system ("cls");
c = 1;
break;

case 4:
system ("cls");
u.modificar();
c = 1;
break;
      
case 5:
system ("cls");
u.eliminar();
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
Sleep (2000);
system ("cls");
goto inicio;
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
Sleep(3000);
system("cls");
f.close();
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
Sleep(3000);
exit(0);
}
cout<<endl<<"Podras intentarlo de nuevo en unos momentos"<<endl;
Sleep (3000); 
system ("cls");
f.close();
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
Sleep(2500);
system("cls");
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
cout<<"Los privilegios son de: "<<privi<<endl<<endl;
cout<<"----------------------------------------------------------------------";
}
cout<<endl;
b.close();
cout<<"======================================================================"<<endl<<endl;
}



void usuarios::buscar1()
{
system ("cls");
cout<<"====================Busqueda de Usuarios por Nombre==================="<<endl;    
char busca [20];
int z = 0;
cout<<endl<<"Introduce el usuario que deseas buscar: "; cin>>busca;
fstream a("Usuarios.admma", ios::in);
if  (!a.good())
cout <<"\nERROR: El archivo de Usuarios no existe. \n";
else
while (!a.eof())
{
a.read((char *)&u,sizeof(u));
if (a.eof())
break;
if (strcmp (busca,u.usuario)==0)
{
z = 1;
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
cout<<"Los privilegios son de: "<<privi<<endl;
}
}
a.close();
if (z == 0)
{
cout<<endl;
cout<<"No se encontro ningun dato"<<endl;
}
cout<<endl<<"======================================================================"<<endl;
}

void usuarios::buscar2()
{
system ("cls");
cout<<"====================Busqueda de Usuarios por Nomina==================="<<endl;    
int busca;
int z = 0;
cout<<endl<<"Introduce la nomina que deseas buscar: "; cin>>busca;
fstream a("Usuarios.admma", ios::in);
if  (!a.good())
cout <<"\nERROR: El archivo de Usuarios no existe. \n";
else
while (!a.eof())
{
a.read((char *)&u,sizeof(u));
if (a.eof())
break;
if(busca == u.nomina)
{
z = 1;
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
cout<<"Los privilegios son de: "<<privi<<endl<<endl;
}
}
a.close();
if (z == 0)
{
cout<<endl;
cout<<"No se encontro ningun dato"<<endl;
}     
cout<<endl<<"======================================================================"<<endl; 
}

void usuarios::modificar()
{
cout<<"========================Modificacion de Usuarios======================"<<endl<<endl;    
int busca,p,m4,posi = 0,s=0;
int z = 0;
cout<<"Introduce la nomina que deseas buscar: "; cin>>busca;
fstream f("Usuarios.admma", ios::in|ios::out);
if  (!f.good())
cout <<"\nERROR: El archivo de Usuarios no existe. \n";
else
while (!f.eof())
{
f.read((char *)&u,sizeof(u));
if (f.eof())
break;
posi = posi + sizeof(u);
if(busca == u.nomina)
{
z = 1;
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
cout<<"Los privilegios son de: "<<privi<<endl<<endl;
cout<<endl<<"Es el usuario que desea modificar? [1=si/2=no]  ";  cin>>p;
if (p==1)
{
cout<<endl<<"Que deseas modificar?"<<endl<<"1)Todo"<<endl<<"2)Contrasena"<<endl<<"3)Privilegios"<<endl<<"4)Nombre de usuario"<<endl<<"5)Cancelar"<<endl;
cin>>m4;
cout<<endl<<endl;
switch (m4)
{     
case 1:
f.seekp(posi - sizeof(u),ios::beg);
cout<<"Nuevo usuario: "; cin>>u.usuario;
cout<<"Nueva contrasena: "; cin>>u.contrasena;
cout<<"Nueva nomina: "; cin>>u.nomina;
cout<<"Selecciona el nivel de privilegios del usuario:"<<endl<<"1) Administrador"<<endl<<"2) Encargado"<<endl<<"3) Vendedor"<<endl;
cin>>u.privilegios;
f.write((char *)&u,sizeof(u));
break;

case 2:
f.seekp(posi - sizeof(u),ios::beg);
cout<<"Nueva contrasena: "; cin>>u.contrasena;
f.write((char *)&x,sizeof(x));
break;

case 3:
f.seekp(posi - sizeof(u),ios::beg);
cout<<"Selecciona el nivel de privilegios del usuario:"<<endl<<"1) Administrador"<<endl<<"2) Encargado"<<endl<<"3) Vendedor"<<endl;
cin>>u.privilegios;
f.write((char *)&u,sizeof(u));

break;

case 4:
f.seekp(posi - sizeof(u),ios::beg);
cout<<"Nuevo nombre de usuario: "; cin>>u.usuario;
f.write((char *)&u,sizeof(u));


break;

case 5:
//SAlir del submenu
system ("cls");
s=1;
break;

default:
cout<<"Opcion invalida, intente de nuevo."<<endl<<endl;
break;
}  
if (s==0)
{
cout<<endl<<"Datos reemplazados correctamente:"<<endl;
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
cout<<"Los privilegios son de: "<<privi<<endl<<endl;
}
}
else
{
cout<<endl<<"Intentalo de nuevo..."<<endl<<endl;
} 
} 
}
if (z == 0)
{
cout<<endl;
cout<<"No se encontro ningun dato"<<endl;
}
f.close();  
cout<<endl<<"======================================================================"<<endl;    
}


void usuarios::eliminar()
{
cout<<"=========================Eliminacion de Usuarios======================"<<endl<<endl;  
int busca,p,m4;
int z = 0;
cout<<"Introduce la nomina que deseas buscar: "; cin>>busca;
fstream a("Usuarios.admma", ios::in);
if  (!a.good())
cout <<"\nERROR: El archivo de Usuarios no existe. \n";
else
while (!a.eof())
{
a.read((char *)&u,sizeof(u));
if (a.eof())
break;
if(busca == u.nomina)
{
z = 1;
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
cout<<"Los privilegios son de: "<<privi<<endl<<endl;
}
}
a.close();
if (z == 0)
{
cout<<endl;
cout<<"No se encontro ningun dato"<<endl;
}  
else
{
cout<<endl<<"Es el usuario que desea eliminar? [1=si/2=no]  ";  cin>>p;
{
if (p==1)
{
cout<<endl<<"Eliminacion en progreso...";
fstream h("Usuarios.admma", ios::in);
if  (!h.good())
{
cout <<"\nERROR: El archivo de Usuarios no existe. \n";
}
else
{
while (!h.eof())
{
h.read((char *)&u,sizeof(u));
if (h.eof())
break;
if(busca != u.nomina)
{
ofstream e("respaldo.admma", ios::app);
e.write((char *)&u,sizeof(u));  
e.close();     
}
}
h.close();
cout<<"Completado."<<endl<<endl;
remove("Usuarios.admma");
rename("respaldo.admma", "Usuarios.admma");
}
}
else
{
cout<<endl<<"Intentalo de nuevo..."<<endl<<endl;
} 
}       
}
cout<<endl<<"======================================================================"<<endl; 
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
int r = 5;
while(!e.eof())
{
e.read((char*)&x,sizeof(x));
if(e.eof())
break;
r = r + 1;
gotoxy(4,r);
cout<<x.folio;
gotoxy(20,r);
cout<<x.nombre;
gotoxy(39,r);
cout<<"$"<<x.precio;
gotoxy(55,r);
cout<<x.exist;
//cout<<"     "<<x.folio<<"             "<<x.nombre<<"               "<<x.precio<<"        "<<x.exist<<endl;
}
}
cout<<endl<<endl<<"======================================================================"<<endl<<endl;
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
cout<<"==================Modificar Existencia en Inventario==================";
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
cout<<endl<<"No existe archivo de inventario."<<endl<<endl;
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
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"Modificar existencia?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
{
cout<<endl<<"Existencia: "; cin>>x.exist;
j.seekp(pos-sizeof(x),ios::beg);
j.write((char*)&x,sizeof(x)); 
cout<<endl<<"Modificado Correctamente."<<endl<<endl;
band = 1;
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
{
cout<<endl<<"Producto no encontrado"<<endl<<endl;
}
break;

case 2:
cout<<endl<<"Folio a buscar: "; cin>>buscar;
if(!j.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl<<endl;
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
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"Modificar existencia?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
{
cout<<endl<<"Existencia: "; cin>>x.exist;
j.seekp(pos-sizeof(x),ios::beg);
j.write((char*)&x,sizeof(x)); 
cout<<endl<<"Modificado Correctamente."<<endl<<endl;
band = 1;
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
{
cout<<endl<<"Folio no encontrado"<<endl<<endl;
}
break;

default:
cout<<endl<<"Opcion invalida, intente de nuevo"<<endl<<endl;
break;
}
j.close();
cout<<"======================================================================"<<endl;
}

void inventario::modificar_it()
{
cout<<"==================Modificar Existencia en Inventario==================";
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
cout<<endl<<"No existe archivo de inventario."<<endl<<endl;
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
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"Modificar todo?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
{
cout<<endl<<"Folio: "; cin>>x.folio;
cout<<"Producto: "; cin>>x.nombre;
cout<<"Precio: "; cin>>x.precio;
cout<<"Existencia: "; cin>>x.exist;
h.seekp(pos-sizeof(x),ios::beg);
h.write((char*)&x,sizeof(x)); 
cout<<endl<<"Modificado Correctamente."<<endl<<endl;
band = 1;
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
{
cout<<endl<<"Producto no encontrado"<<endl<<endl;
}
h.close();
break;

case 2:
cout<<endl<<"Folio a buscar: "; cin>>buscar;
if(!h.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl<<endl;
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
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"Modificar todo?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
{
cout<<endl<<"Folio: "; cin>>x.folio;
cout<<"Producto: "; cin>>x.nombre;
cout<<"Precio: "; cin>>x.precio;
cout<<"Existencia: "; cin>>x.exist;
h.seekp(pos-sizeof(x),ios::beg);
h.write((char*)&x,sizeof(x)); 
cout<<endl<<"Modificado Correctamente."<<endl<<endl;
band = 1;
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
{
cout<<endl<<"Folio no encontrado"<<endl<<endl;
}
break;

default:
cout<<endl<<"Opcion invalida, intente de nuevo"<<endl<<endl;
break;
}
h.close();
cout<<"======================================================================"<<endl;
}

void inventario::eliminar_i()
{
cout<<"===================Eliminar Producto en Inventario===================="<<endl;
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
cout<<endl<<"No existe archivo de inventario."<<endl<<endl;
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
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"Eliminar?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
cout<<endl<<"Eliminando...\n";
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
cout<<endl<<"Producto no encontrado."<<endl;
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
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Existencias: "<<x.exist<<endl;
cout<<endl<<"Eliminar?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
cout<<endl<<"Eliminando...\n";
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
cout<<endl<<"======================================================================"<<endl<<endl;
Sleep (2000);
system ("cls");
}          
           
//////////////////////////////////////////////////////////////////////////////////////////////

void ventas::vender()
{
system("cls");
int cont,opc;
time_t tiempo = time(0);
struct tm *tlocal = localtime(&tiempo);
//cout<<"El carrito esta vacio, para comenzar a editarlo selecciona una opcion en el menu."<<endl<<endl;
do
{
fstream e("temporal.admma",ios::in|ios::out);
if(!e.good())
{
cout<<"===========================Mostrar Carrito============================"<<endl<<endl;
cout<<endl<<"No hay nada en el carrito todavia."<<endl<<endl;
v.preciototal = 0;
v.totalarticulos = 0;
v.subtotal = 0;
}
else
{
cout<<"===========================Mostrar Carrito============================"<<endl;
cout<<endl<<"  Folio         Producto          Precio      Cantidad      Subtotal"<<endl;
int r = 5;
v.preciototal = 0;
v.totalarticulos = 0;
v.subtotal = 0;
while(!e.eof())
{
e.read((char*)&x,sizeof(x));
if(e.eof())
break;
r = r + 1;
gotoxy(3,r);
cout<<x.folio;
gotoxy(17,r);
cout<<x.nombre;
gotoxy(35,r);
cout<<"$"<<x.precio;
gotoxy(50,r);
cout<<x.exist;
gotoxy(63,r);
v.subtotal = x.exist * x.precio;
cout<<"$"<<v.subtotal;
v.preciototal = v.preciototal + v.subtotal;
v.totalarticulos = v.totalarticulos + x.exist;
}
}
cout<<endl<<endl<<"----------------------------------------------------------------------"<<endl;
cout<<"       Total de articulos: "<<v.totalarticulos<<"      Precio total: $"<<v.preciototal<<endl;
totalarticulosg = v.totalarticulos;
preciototalg = v.preciototal;
cout<<endl<<"======================================================================"<<endl<<endl;
e.close();  
          
cout<<"Que deseas hacer?"<<endl<<"1) Agregar producto por folio"<<endl<<"2) Agregar producto por nombre"<<endl<<"3) Quitar un articulo"<<endl<<"4) Modificar cantidad de un articulo"<<endl<<"5) Terminar y registrar venta"<<endl<<"6) Cancelar venta y regresar al menu anterior"<<endl<<"7) Guardar el carrito y regresar al menu anterior"<<endl;
cin>>opc;

switch (opc)
{
case 1: //agregar por folio
system("cls");   
v.agregarporfolio();
cont = 1;
break;

case 2:
system("cls");
v.agregarpornombre();
cont = 1;
break;

case 3:
system("cls");
v.eliminar();
cont = 1;
break;

case 4:
system("cls");
v.modicant();
cont = 1;
break;     

case 5:
strftime(v.fechayhora,50,"%d/%m/%Y   %I:%M:%S  %p",tlocal);
cont = 0;
v.terminarventa();
remove ("temporal.admma");
system ("PAUSE");
system("cls");
break;

case 6:  
remove ("temporal.admma");  
cont = 0;
system("cls");
break;

case 7:
cont = 0;    
system("cls");
break;

default:
cout<<endl<<"Opcion invalida, intentalo de nuevo"<<endl<<endl;
cont = 1;
break;

}
}
while(cont==1);
}

void ventas::agregarporfolio()
{
cout<<"==========================Agregar por folio==========================="<<endl<<endl;
int band=0;
int o;
int cant;
char buscar[20];
fstream f("Inventario.admma", ios::in|ios::out);
cout<<endl<<"Folio a buscar: "; cin>>buscar;
if(!f.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl<<endl;
Sleep(2500);
system ("cls");
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

cout<<"Es el producto que deseas agregar?"<<endl<<"1) Si"<<endl<<"2) No"<<endl;
cin>>o;
if(o==1)
{
cout<<endl<<"Cuantos articulos deseas agregar al carrito: "; cin>>cant;
if (x.exist < cant)
{
cout<<endl<<"No se pudo agregar al carrito, ya que no hay existencias suficientes."<<endl;
Sleep (2000);
}
else
{
x.exist = cant;
ofstream c("temporal.admma", ios::app);
c.write((char*)&x,sizeof(x));
c.close();
}
system ("cls");
}
else
{
system("cls");
}


}
}
if(band==0)
{
cout<<endl<<"Folio no encontrado."<<endl<<endl;
Sleep(2500);
system ("cls");
}
}
f.close();
}


void ventas::agregarpornombre()
{
cout<<"=========================Agregar por Nombre==========================="<<endl<<endl;
int band=0;
int o;
int cant;
char buscar[20];
fstream f("Inventario.admma", ios::in|ios::out);
cout<<endl<<"Producto a buscar: "; cin>>buscar;
if(!f.good())
{
cout<<endl<<"No existe archivo de inventario."<<endl<<endl;
Sleep(2500);
system ("cls");
}
else
{
while(!f.eof())
{
f.read((char*)&x,sizeof(x));
if(f.eof())
break;
if(strcmp(buscar,x.nombre)==0)
{

cout<<endl<<"Folio: "<<x.folio<<endl;
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Existencias: "<<x.exist<<endl<<endl;
band=1;

cout<<"Es el producto que deseas agregar?"<<endl<<"1) Si"<<endl<<"2) No"<<endl;
cin>>o;
if(o==1)
{
cout<<endl<<"Cuantos articulos deseas agregar al carrito: "; cin>>cant;
if (x.exist < cant)
{
cout<<endl<<"No se pudo agregar al carrito, ya que no hay existencias suficientes."<<endl;
Sleep (2000);
}
else
{
x.exist = cant;
ofstream c("temporal.admma", ios::app);
c.write((char*)&x,sizeof(x));
c.close();
}
system ("cls");
}
else
{
system("cls");
}


}
}
if(band==0)
{
cout<<endl<<"Folio no encontrado."<<endl<<endl;
Sleep(2500);
system ("cls");
}
}
f.close();
}

void ventas::eliminar()
{
cout<<"========================Eliminar un Articulo=========================="<<endl<<endl;
char buscar[20];
int band=0;
int res;
int opc;
fstream k("temporal.admma",ios::in|ios::out);
ofstream a("auxiliar.admma",ios::app);
cout<<"Buscar por:"<<endl<<"1)Producto"<<endl<<"2)Folio"<<endl;
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
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Cantidad: "<<x.exist<<endl;
cout<<endl<<endl<<"Eliminar?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
cout<<endl<<"Eliminando...\n";
else
a.write((char*)&x,sizeof(x));
}
else
a.write((char*)&x,sizeof(x));
}
k.close();
a.close();
remove("temporal.admma");
rename("auxiliar.admma","temporal.admma");
}
if(band==0)
cout<<endl<<"Producto no encontrado."<<endl;
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
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Cantidad: "<<x.exist<<endl;
cout<<endl<<"Eliminar?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
cout<<endl<<endl<<"Eliminando...\n";
else
a.write((char*)&x,sizeof(x));
}
else
a.write((char*)&x,sizeof(x));
}
k.close();
a.close();
remove("temporal.admma");
rename("auxiliar.admma","temporal.admma");
}
if(band==0)
cout<<endl<<"Folio no encontrado."<<endl<<endl;
break;
}
cout<<endl<<"======================================================================"<<endl<<endl;
Sleep (2000);
system ("cls");
}          

void ventas::modicant()
{
cout<<"====================Modificar Cantidad en Carrito=====================";
int res,disponibles;
int pos=0;
int band=0;
char buscar[20];
int opc;
fstream j("temporal.admma", ios::in|ios::out);
fstream q("Inventario.admma", ios::in|ios::out);
cout<<endl<<"Buscar por:"<<endl<<"1)Producto"<<endl<<"2)Folio"<<endl;
cin>>opc;
switch(opc)
{
case 1:
cout<<endl<<"Producto a buscar: "; cin>>buscar;
///
if(!q.good())
{
cout<<endl<<"No hay inventario."<<endl<<endl;
}
else
{    
while(!q.eof())
{
q.read((char*)&x,sizeof(x));
if(q.eof())
break;
if(strcmp(buscar,x.nombre)==0)
{
disponibles = x.exist;
}
}
}
///
if(!j.good())
{
cout<<endl<<"El carrito esta vacio."<<endl<<endl;
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
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Cantidad: "<<x.exist<<endl;
band = 1;
cout<<endl<<"Modificar cantidad?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
{
cout<<endl<<"Cantidad: "; cin>>x.exist;
if(x.exist<=disponibles)
{
j.seekp(pos-sizeof(x),ios::beg);
j.write((char*)&x,sizeof(x)); 
cout<<endl<<"Modificado Correctamente."<<endl<<endl;
band = 1;
}
else
{
cout<<endl<<"No tienes articulos suficientes en stock."<<endl<<endl;
}
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
{
cout<<endl<<"Producto no encontrado"<<endl<<endl;
}
break;

case 2:
cout<<endl<<"Folio a buscar: "; cin>>buscar;
//
if(!q.good())
{
cout<<endl<<"No hay inventario."<<endl<<endl;
}
else
{    
while(!q.eof())
{
q.read((char*)&x,sizeof(x));
if(q.eof())
break;
if(strcmp(buscar,x.folio)==0)
{
disponibles = x.exist;
}
}
}
//
if(!j.good())
{
cout<<endl<<"El carrito esta vacio."<<endl<<endl;
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
cout<<"Producto: "<<x.nombre<<endl;
cout<<"Precio: "<<x.precio<<endl;
cout<<"Cantidad: "<<x.exist<<endl;
band = 1;
cout<<endl<<"Modificar cantidad?"<<endl<<"1)Si"<<endl<<"2)No"<<endl;
cin>>res;
if(res==1)
{
cout<<endl<<"Cantidad: "; cin>>x.exist;
if(x.exist<=disponibles)
{
j.seekp(pos-sizeof(x),ios::beg);
j.write((char*)&x,sizeof(x)); 
cout<<endl<<"Modificado Correctamente."<<endl<<endl;
band = 1;
}
else
{
cout<<endl<<"No tienes articulos suficientes en stock."<<endl<<endl;    
}
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
{
cout<<endl<<"Folio no encontrado"<<endl<<endl;
}
break;

default:
cout<<endl<<"Opcion invalida, intente de nuevo"<<endl<<endl;
break;
}
j.close();
q.close();
cout<<"======================================================================"<<endl;
Sleep (2500);
system ("cls");
}


void ventas::terminarventa()
{
int res,disponibles;
int pos=0;
int band=0;
char buscar[20];
int opc;
fstream q("temporal.admma", ios::in|ios::out);
if(!q.good())
{
cout<<endl<<"No hay carrito."<<endl<<endl;
}
else
{    
while(!q.eof())
{
q.read((char*)&x,sizeof(x));
if(q.eof())
break;
disponibles = x.exist;
strcpy (buscar, x.folio);
pos = 0;
fstream j("Inventario.admma", ios::in|ios::out);
if(!j.good())
{
cout<<endl<<"El carrito esta vacio."<<endl<<endl;
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
x.exist = x.exist - disponibles;
j.seekp(pos-sizeof(x),ios::beg);
j.write((char*)&x,sizeof(x)); 
j.close();
}
}
}
}
}
q.close();
////////////////////  Aqui comineza escritura del historial
time_t tiempo = time(0);
struct tm *tlocal = localtime(&tiempo);



fstream e("Historial.admma",ios::in|ios::out);
if(!e.good())
{
v.numventa = 0;
}
else
{
while(!e.eof())
{
e.read((char*)&v,sizeof(v));
if(e.eof())
break;
v.numventa = v.numventa;
}
}
e.close();

strcpy(v.userin1,userin);
strcpy(v.privi1,privi);
v.numventa = v.numventa + 1;
v.totalarticulos = totalarticulosg;
v.preciototal = preciototalg;
strftime(v.fechayhora,50,"%d/%m/%Y   %I:%M:%S  %p",tlocal);
ofstream b("Historial.admma", ios::app);
b.write((char*)&v,sizeof(v));
b.close();

cout<<endl<<"Venta concretada con exito. ";
cout<<endl<<"Fecha y hora de la venta: "<<v.fechayhora<<endl<<endl;


fstream z("temporal.admma", ios::in|ios::out);
if(!z.good())
{
cout<<endl<<"No hay carrito."<<endl<<endl;
}
else
{    
while(!z.eof())
{
z.read((char*)&x,sizeof(x));
if(z.eof())
break;
strcpy (v.nombre, x.nombre);
v.exist = x.exist;
strcpy (v.folio, x.folio);
v.precio = x.precio;
ofstream y("Historiadeta.admma", ios::app);
y.write((char*)&v,sizeof(v));
y.close();
}
}
z.close();   
}


void ventas :: mostrarhist()
{
system ("cls");
int r = 0,buscar;
cout<<"=====================Mostrar Historial de Ventas======================"<<endl;
fstream p("Historial.admma",ios::in|ios::out);
if(!p.good())
{
cout<<endl<<endl<<"No hay un historial de ventas."<<endl<<endl;
}
else
{
while(!p.eof())
{
p.read((char*)&v,sizeof(v));
buscar = v.numventa;
if(p.eof())
break;
cout<<endl<<"Numero de venta: "<<v.numventa<<" hecha por: "<<v.userin1<<" con privilegios de: "<<v.privi1<<endl;
cout<<"Se vendieron: "<<v.totalarticulos<<" articulos por el monto total de: $"<<v.preciototal<<endl;
cout<<"Esta venta se realizo el: "<<v.fechayhora<<endl<<endl;
cout<<"Informacion detallada de esta venta:"<<endl;
cout<<endl<<"  Folio         Producto          Precio      Cantidad      Subtotal"<<endl;
r = r+11;
//
fstream e("Historiadeta.admma",ios::in|ios::out);
if(!e.good())
{
cout<<endl<<endl<<"No hay un historial de ventas detallado."<<endl<<endl;
}
else
{
while(!e.eof())
{
e.read((char*)&v,sizeof(v));
if(e.eof())
break;
if (buscar == v.numventa)
{
r = r + 1;
gotoxy(3,r);
cout<<v.folio;
gotoxy(17,r);
cout<<v.nombre;
gotoxy(35,r);
cout<<"$"<<v.precio;
gotoxy(50,r);
cout<<v.exist;
gotoxy(63,r);
v.subtotal = v.exist * v.precio;
cout<<"$"<<v.subtotal;
}
}
}
//
cout<<endl<<"----------------------------------------------------------------------"<<endl;
}
}
p.close();
cout<<"======================================================================"<<endl<<endl;
}

///////////////////////////////////////////

void ventas::buscarventa()
{
system ("cls");
int r=2, buscar, band=0, pos=0, res;
cout<<"=============================Buscar Venta============================="<<endl;
cout<<endl<<"Numero de venta a buscar: "; cin>>buscar;
fstream n("Historial.admma",ios::in|ios::out);
if(!n.good())
{
cout<<endl<<endl<<"No hay un historial de ventas."<<endl<<endl;
}
else
{
while(!n.eof())
{
n.read((char*)&v,sizeof(v));
if(n.eof())
break;
//pos=pos+sizeof(v);
if (buscar == v.numventa)
{
cout<<endl<<"Numero de venta: "<<v.numventa<<" hecha por: "<<v.userin1<<" con privilegios de: "<<v.privi1<<endl;
cout<<"Se vendieron: "<<v.totalarticulos<<" articulos por el monto total de: $"<<v.preciototal<<endl;
cout<<"Esta venta se realizo el: "<<v.fechayhora<<endl<<endl;
cout<<"Informacion detallada de esta venta:"<<endl;
cout<<endl<<"  Folio         Producto          Precio      Cantidad      Subtotal"<<endl;
r = r+11;
band=1;
fstream m("Historiadeta.admma",ios::in|ios::out);
if(!m.good())
{
//cout<<endl<<endl<<"No hay un historial de ventas detallado."<<endl<<endl;
}
else
{
while(!m.eof())
{
m.read((char*)&v,sizeof(v));
if(m.eof())
break;
//pos=pos+sizeof(v);
if (buscar == v.numventa)
{
r = r + 1;
gotoxy(3,r);
cout<<v.folio;
gotoxy(17,r);
cout<<v.nombre;
gotoxy(35,r);
cout<<"$"<<v.precio;
gotoxy(50,r);
cout<<v.exist;
gotoxy(63,r);
v.subtotal = v.exist * v.precio;
cout<<"$"<<v.subtotal;
band=1;
}
}
m.close();
}
}
}
}
if(band==0)
{
cout<<endl<<"Numero de venta no encontrado."<<endl;
}
n.close();
cout<<endl<<endl<<"======================================================================"<<endl;
}



void ventas::buscarventa_u()
{
system("cls");
int r=2, pos=0, res,busca,band=0;
char buscar[20];
cout<<"=============================Buscar Venta============================="<<endl;
cout<<endl<<"Usuario a buscar: "; cin>>buscar;
fstream n("Historial.admma",ios::in|ios::out);
if(!n.good())
{
cout<<endl<<endl<<"No hay un historial de ventas."<<endl<<endl;
}
else
{
while(!n.eof())
{
n.read((char*)&v,sizeof(v));
if(n.eof())
break;
if (strcmp(buscar,v.userin1)==0)
{
band = 1;
cout<<endl<<"Numero de venta: "<<v.numventa<<" hecha por: "<<v.userin1<<" con privilegios de: "<<v.privi1<<endl;
cout<<"Se vendieron: "<<v.totalarticulos<<" articulos por el monto total de: $"<<v.preciototal<<endl;
cout<<"Esta venta se realizo el: "<<v.fechayhora<<endl<<endl;
cout<<"Informacion detallada de esta venta:"<<endl;
cout<<endl<<"  Folio         Producto          Precio      Cantidad      Subtotal"<<endl;
r = r+11;
busca = v.numventa;
//
fstream m("Historiadeta.admma",ios::in|ios::out);
if(!m.good())
{
cout<<endl<<endl<<"No hay un historial de ventas detallado."<<endl<<endl;
}
else
{
while(!m.eof())
{
m.read((char*)&v,sizeof(v));
if(m.eof())
break;
if (busca == v.numventa)
{
r = r + 1;
gotoxy(3,r);
cout<<v.folio;
gotoxy(17,r);
cout<<v.nombre;
gotoxy(35,r);
cout<<"$"<<v.precio;
gotoxy(50,r);
cout<<v.exist;
gotoxy(63,r);
v.subtotal = v.exist * v.precio;
cout<<"$"<<v.subtotal;
}
}
}
cout<<endl<<"----------------------------------------------------------------------"<<endl;
m.close();
}
}
}
n.close();
if(band==0)
{
cout<<endl<<"Usuario no encontrado."<<endl;
}
cout<<endl<<"======================================================================"<<endl;
}

void ventas::eliminarhist()
{
int r;
fstream n("Historial.admma",ios::in|ios::out);
fstream m("Historiadeta.admma",ios::in|ios::out);
cout<<"======================Eliminar Historial de Ventas===================="<<endl;
if(!n.good() && !m.good())
{
cout<<endl<<endl<<"No hay un historial de ventas."<<endl<<endl;
cout<<"======================================================================"<<endl<<endl;
}
else
{
cout<<endl<<"Esta seguro de eliminar todo el historial de ventas?"<<endl<<"1) Si"<<endl<<"2) No"<<endl;
cin>>r;
if(r==1)
{
cout<<endl<<"Eliminando..."<<endl;
cout<<"======================================================================"<<endl<<endl;
n.close();
m.close();
remove("Historial.admma");
remove("Historiadeta.admma");
Sleep (2200);
system("cls");
cout<<"Historial de Ventas Eliminado Correctamente"<<endl;
Sleep (1500);
system("cls");
}
else
{
n.close();
m.close();
cout<<endl<<"Eliminacion del historial cancelada. "<<endl<<endl;  
cout<<"======================================================================"<<endl<<endl;
Sleep (1500);
system ("cls"); 
}
}
}



void ventas::cancelarventa()
{
system ("cls");
int r=2, buscar, band=0, pos=0, res, b=1;
fstream e("Historiadeta.admma",ios::in|ios::out);
//ofstream t("aux1.admma",ios::app);
fstream n("Historial.admma",ios::in|ios::out);
//ofstream s("aux.admma",ios::app);
cout<<"============================Cancelar Venta============================"<<endl;
cout<<endl<<"Numero de venta a buscar: "; cin>>buscar;
////////
if(!n.good())
{
cout<<endl<<endl<<"No hay un historial de ventas."<<endl<<endl;
}
else
{
while(!n.eof())
{
n.read((char*)&v,sizeof(v));
if(n.eof())
break;
//pos=pos+sizeof(v);
if (buscar == v.numventa)
{
cout<<endl<<"Numero de venta: "<<v.numventa<<" hecha por: "<<v.userin1<<" con privilegios de: "<<v.privi1<<endl;
cout<<"Se vendieron: "<<v.totalarticulos<<" articulos por el monto total de: $"<<v.preciototal<<endl;
cout<<"Esta venta se realizo el: "<<v.fechayhora<<endl<<endl;
cout<<"Informacion detallada de esta venta:"<<endl;
cout<<endl<<"  Folio         Producto          Precio      Cantidad      Subtotal"<<endl;
r = r+11;
band=1;
//
fstream m("Historiadeta.admma",ios::in|ios::out);
if(!m.good())
{
//cout<<endl<<endl<<"No hay un historial de ventas detallado."<<endl<<endl;
}
else
{
while(!m.eof())
{
m.read((char*)&v,sizeof(v));
if(m.eof())
break;
//pos=pos+sizeof(v);
if (buscar == v.numventa)
{
r = r + 1;
gotoxy(3,r);
cout<<v.folio;
gotoxy(17,r);
cout<<v.nombre;
gotoxy(35,r);
cout<<"$"<<v.precio;
gotoxy(50,r);
cout<<v.exist;
gotoxy(63,r);
v.subtotal = v.exist * v.precio;
cout<<"$"<<v.subtotal;
band=1;
}
}
m.close();
}
}
}
}
n.close();
if(band==0)
{
cout<<endl<<"Numero de venta no encontrado."<<endl;
e.close();
//t.close();
n.close();
//s.close();
}
else
{
cout<<endl<<"----------------------------------------------------------------------"<<endl;
cout<<endl<<"Cancelar Venta?"<<endl<<"1) Si"<<endl<<"2) No"<<endl;
cin>>res;
if(res==1)
{
///   
fstream a("Historial.admma",ios::in|ios::out);    
if  (!a.good())
{
cout <<"\nERROR.\n";
}
else
{
while (!a.eof())
{
a.read((char*)&v,sizeof(v));
if (a.eof())
{
break;
}
if(buscar != v.numventa)
{
ofstream c("aux2.admma",ios::app);
c.write((char*)&v,sizeof(v));  
c.close();     
}
}
}
a.close();
///

int disponibles;
int pos=0;
char buscar2[20];


e.close();


fstream q("Historiadeta.admma", ios::in|ios::out);
if(!q.good())
{
cout<<endl<<"ERROR."<<endl<<endl;
}
else
{    
while(!q.eof())
{
q.read((char*)&v,sizeof(v));
if(q.eof())
break;
if (buscar == v.numventa)
{
disponibles = v.exist;
strcpy (buscar2,v.folio);
cout<<buscar2;
pos = 0;

fstream j("Inventario.admma", ios::in|ios::out);
if(!j.good())
{
cout<<endl<<"ERROR."<<endl<<endl;
}
else
{
while(!j.eof())
{
j.read((char*)&x,sizeof(x));
if(j.eof())
{
break;
}
pos = pos+sizeof(x);
if(strcmp(buscar2,x.folio)==0)
{
x.exist = x.exist + disponibles;
j.seekp(pos-sizeof(x),ios::beg);
j.write((char*)&x,sizeof(x)); 
}
}
j.close();
}
}
}
}
q.close();  
///
n.close();
//s.close();
e.close();
//t.close();
remove("Historial.admma");
rename("aux2.admma","Historial.admma");
cout<<endl<<"Cancelado correctamente.";
//remove("Historiadeta.admma");
//rename("aux1.admma","Historiadeta.admma");
}
else
{
n.close();
//s.close();
e.close();
//t.close();   
cout<<endl<<"Cancelacion no efectuada, regresando al menu...";
}
///
}
cout<<endl<<"======================================================================"<<endl<<endl;
Sleep(1500);
system ("cls");
}



