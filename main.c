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

#include <stdio.h>
#include "Usuario.h"

int main(){
    Lista * lista = newLista();
llenar(newUsuario("Melina", 1, "Maure", 1740, 'P', 1426), lista);
llenar(newUsuario("Felipe", 4, "Guayaquil", 2075, 'P', 2500), lista);
llenar(newUsuario("Lisa", 1, "Maure", 1740, 'P', 360), lista);
llenar(newUsuario("Sergio", 2, "Maipu", 1425, 'C', 26), lista);
llenar(newUsuario("Lola", 2, "Zabala", 1742, 'C', 14026), lista);
llenar(newUsuario("Belen", 2, "Vergara", 2403, 'C', 1426), lista);
llenar(newUsuario("Sol", 2, "Libertador", 5599, 'P', 20), lista);

listar(lista, 20, 30, 40);
nombreYConsumoP(lista);
maxConsumoC(lista);
totalYMin(lista, 20, 30, 40);

return 0;
}


