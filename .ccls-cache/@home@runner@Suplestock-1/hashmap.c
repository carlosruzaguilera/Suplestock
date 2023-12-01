#include "hashmap.h"

Producto *tablaHash[TAM_TABLA] = {NULL}; // Inicializar todas las entradas a NULL
Venta *tablaHashVentas[TAM_TABLA_VENTAS] = {NULL}; // Inicializar todas las entradas a NULL


int calcularHash(int id) {
    return id % TAM_TABLA;
}