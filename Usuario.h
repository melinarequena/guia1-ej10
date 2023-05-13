//
// Created by Administrador on 13/5/2023.
//

#ifndef GUIA1_EJ10_USUARIO_H
#define GUIA1_EJ10_USUARIO_H

typedef struct usuario{
    char nombre[20];
    int codZona;
    char calle[20];
    int numCalle;
    char categoria;
    float consumo; /*En KW -> Importe(float) = Consumo(float)*TarifaxKW*/
    struct usuario * sig;
}Usuario;

 typedef struct lista{
     Usuario * cabecera;
 }Lista;

 Usuario * newUsuario(char * nombre, int codZona, char * calle, int numCalle, char categoria, float consumo);
 Lista * newLista();
void llenar(Usuario * usuario, Lista * lista);
void listar(Usuario * usuario, Lista * lista, float consumoMinimo, float importeP, float importeC);
void nombreYConsumoP(Usuario * usuario, Lista * lista);
void maxConsumoC(Usuario * usuario, Lista * lista);
void totalYMin(Usuario * usuario, Lista * lista,float consumoMinimo, float importeP, float importeC);


#endif //GUIA1_EJ10_USUARIO_H
