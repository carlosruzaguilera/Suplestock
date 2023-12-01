#include "hashmap.h"

Producto *tablaHash[TAM_TABLA] = {NULL}; // Inicializar todas las entradas a NULL
Venta *tablaHashVentas[TAM_TABLA_VENTAS] = {NULL}; // Inicializar todas las entradas a NULL


int calcularHash(int id) {
    return id % TAM_TABLA;
}

void registrarProducto() {
    Producto producto;

    printf("\nIngrese ID del producto: ");
    scanf("%d", &producto.id);
    printf("\nIngrese nombre del producto: ");
    scanf("%s", producto.nombre);
    printf("\nIngrese precio de compra: ");
    scanf("%f", &producto.precio_compra);
    printf("\nIngrese precio de venta: ");
    scanf("%f", &producto.precio_venta);
    printf("\nIngrese cantidad en stock: ");
    scanf("%d", &producto.cantidad_stock);

    int indice = calcularHash(producto.id);

    Producto *nuevoProducto = (Producto *)malloc(sizeof(Producto));
    *nuevoProducto = producto;
    nuevoProducto->siguiente = NULL;

    if (tablaHash[indice] == NULL) {
        tablaHash[indice] = nuevoProducto;
    } else {
        Producto *actual = tablaHash[indice];
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoProducto;
    }
}