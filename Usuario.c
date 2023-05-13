//
// Created by Administrador on 13/5/2023.
//

#include "Usuario.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Usuario * newUsuario(char * nombre, int codZona, char * calle, int numCalle, char categoria, float consumo){
    Usuario * auxUsuario = NULL; //Lo seteo a null p evitar basura, deitel
    auxUsuario = malloc(sizeof(Usuario)); //Asigno memoria
    if(auxUsuario == NULL){
        printf("Error al asignar memoria\n"); //No existe memoria contigua
        exit -1; //Salida de error
    }else{
        //Seteo el apuntador del siguiente a NULL
        auxUsuario->sig = NULL;
        //Relleno campos
        strcpy(auxUsuario->nombre, nombre);
        auxUsuario->codZona = codZona;
        strcpy(auxUsuario->calle, calle);
        auxUsuario->numCalle = numCalle;
        auxUsuario->categoria = categoria;
        auxUsuario->consumo = consumo;
    }
    return auxUsuario;
}

Lista * newLista(){ //No recibe ningun parametro
    Lista * auxLista = NULL; //Idem fn newUsuario
    auxLista = malloc(sizeof(Lista));
    if(auxLista == NULL){
        printf("Error al asignar memoria\n");
        exit -1;
    }else{
        auxLista->cabecera = NULL;
    }
    return auxLista;
}

void llenar(Usuario * usuario, Lista * lista){
    if(lista->cabecera == NULL){ //La lista esta vacia
        lista->cabecera = usuario;
    }else{ //Existen ya usuarios ingresados en la lista
        Usuario * auxUsuario = lista->cabecera;
        while(auxUsuario->sig !=NULL)//Intentamos llegar al final de la lista
            {
            auxUsuario = auxUsuario->sig; //Paso al siguiente
            } // Salgo del while, aux usuario esta apuntando al ultimo elemento de la lista
        auxUsuario->sig = usuario; //Usuario pasa a ser el ultimo elemento
    }
}

void listar(Lista * lista, float consumoMinimo, float importeP, float importeC){
    Usuario * auxUsuario = lista->cabecera;
    while(auxUsuario!=NULL){
        if(auxUsuario->consumo>consumoMinimo){
            if(auxUsuario->categoria == 'P') {
                printf("El usuario %s, de categoria P, domicilio en calle %s %d, ha registrado un consumo de %.2f, por lo que su importe es de: \n$%.2f", auxUsuario->nombre, auxUsuario->calle, auxUsuario->numCalle, auxUsuario->consumo, auxUsuario->consumo*importeP);
            }else{
                printf("El usuario %s, de categoria C, domicilio en calle %s %d, ha registrado un consumo de %.2f, por lo que su importe es de: \n$%.2f",auxUsuario->nombre, auxUsuario->calle, auxUsuario->numCalle, auxUsuario->consumo, auxUsuario->consumo*importeC);
            }
        }
        auxUsuario=auxUsuario->sig;
    }
}

void nombreYConsumoP(Lista * lista) {
    int cont = 0;
    float suma = 0;
    Usuario *auxUsuario = lista->cabecera;
    printf("Usuarios particulares:\n");
    while (auxUsuario != NULL) {
        if (auxUsuario->categoria = 'P') {
            suma = auxUsuario->consumo;
            cont++;
            printf("%s\n", auxUsuario->nombre);
        }
        auxUsuario = auxUsuario->sig;
    }
    printf("El promedio de consumo de usuarios particulares es de %.2f",
           suma / cont); //Es necesario el casting? El ide me marca warning
}

void maxConsumoC(Lista * lista){
    Usuario * auxUsuario = lista->cabecera;
    float max=auxUsuario->consumo;
    char maxUsuario [20];
    strcpy(maxUsuario, auxUsuario->nombre);

    while(auxUsuario!=NULL){
        if(auxUsuario->consumo<auxUsuario->sig->consumo){
           max=auxUsuario->sig->consumo;
            strcpy(maxUsuario, auxUsuario->sig->calle);
        }
        auxUsuario=auxUsuario->sig;
    }
    printf("El usuario C con mayor consumo (%.2f) tiene direccion en %s", max, maxUsuario);
}

void totalYMin(Lista * lista, float consumoMinimo, float importeP, float importeC){
    float suma=0;
    int contC=0, contP=0;
    Usuario * auxUsuario = lista->cabecera;
    while(auxUsuario!=NULL){
        if(auxUsuario->categoria ==  'P'){
            suma = suma + auxUsuario->consumo*importeP;
            if(consumoMinimo == auxUsuario->consumo){
                contP++;
            }
        }
        if(auxUsuario->categoria ==  'C'){
            suma = suma + auxUsuario->consumo*importeC;
            if(consumoMinimo == auxUsuario->consumo){
                contC++;
            }
        }
    }
    printf("El importe total es de $%.2f, existen %d C que consumieron lo minimo, mientras que existen %d P que consumieron lo min tmb", suma, contC, contP);

}