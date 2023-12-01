#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TABLA 100
#define TAM_TABLA_VENTAS 100

// Definiciones de estructuras
typedef struct producto {
    int id;
    char nombre[50];
    float precio_compra;
    float precio_venta;
    int cantidad_stock;
    struct producto *siguiente;
} Producto;

typedef struct venta {
    int id_venta;
    int id_producto;
    int cantidad_vendida;
    float total_venta;
    struct venta *siguiente;
} Venta;

extern Producto *tablaHash[TAM_TABLA];
extern Venta *tablaHashVentas[TAM_TABLA_VENTAS];