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

// Prototipos de funciones 
void mostrarMenu();
int calcularHash(int id); // Funciones Hash

// Funciones de Gestión de Productos
void registrarProducto(); 
void eliminarProducto(); 
void eliminarProductoPorNombre();
void agregarProductosDesdeCSV();
void agregarProductoDetalle(int id, char *nombre, float precio_compra, float precio_venta, int cantidad_stock);
void mostrarListaCompletaProductos();

// Funciones de Gestión de Stock
void consultarStock(); 
void actualizarStock(); 
void anadirCantidadStock();
void restarCantidadStock();
void establecerNuevaCantidadStock();
void consultarStockPorNombre();

// Función de Gestión de Ventas
void registrarVenta();
void buscarVenta();
void cancelarVenta();

// Funciones de Gestión de Reportes
void generarReporteVentas();
void generarReporteStock();
void generarReporteGanancias();

#endif // HASHMAP_H

