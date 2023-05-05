/*
 10. Se conocen: las tarifas particulares y comercial del KW y el consumo mínimo de
ambas categorías. Además se dispone de la siguiente información por cada usuario:
nro de zona, nombre, calle, nro , tipo-usuario (‘P’ o ‘C’), consumo.
Se pide:
a. Listar para cada zona aquellos usuarios que superen el consumo mínimo
detallando: tipo de usuario, nombre, calle y número, consumo e importe.
b. Informar para cada zona:
i. Nombre y consumo promedio de los usuarios particulares.
ii. La dirección del usuario comercial cuyo consumo haya sido el
máximo registrado en esa zona.
iii. El total facturado y la cantidad de usuarios de cada categoría que
abonen el mínimo.*/

#include<stdio.h>

typedef struct usuarios{
    int CodZona;
    char Nombre[30];
    char Direc[30];
    int NumDirec;
    char TipoUser; //P Particular, C Comercial
    int Consumo;
    struct usuarios * sig; //Apunta al usuario siguiente
}Usuario;

Usuario * newUsuario(int CodZona, char * Nombre, char * Direc, int NumDirec, char TipoUser, int Consumo); //Crea nuevos usuarios
void listarcm(struct Usuario *usuarios, int ConsMinC, int ConsMinP);
void nomprompart(struct Usuario *usuarios);
int maxcom(struct Usuario *usuarios);
void totfacturado(struct Usuarios *usuarios);


int main(){
    int ConsMinP, ConsMinC, TarPart, TarCome;


}

Usuario * newUsuario(int CodZona, char * Nombre, char * Direc, int NumDirec, char TipoUser, int Consumo){//Crea nuevos usuarios

}


