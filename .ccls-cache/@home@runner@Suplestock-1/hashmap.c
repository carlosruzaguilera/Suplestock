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

void eliminarProducto() {
    int id;
    printf("\nIngrese ID del producto a eliminar: ");
    scanf("%d", &id);

    int indice = calcularHash(id);
    Producto *actual = tablaHash[indice];
    Producto *anterior = NULL;

    // Buscar en la lista enlazada
    while (actual != NULL) {
        if (actual->id == id) {
            if (anterior == NULL) {
                // Eliminar el primer producto en la lista
                tablaHash[indice] = actual->siguiente;
            } else {
                // Eliminar un producto que no es el primero
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            printf("\nProducto con ID %d eliminado.\n", id);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    printf("\nProducto con ID %d no encontrado.\n", id);
}

void eliminarProductoPorNombre() {
    char nombreBuscado[50];
    printf("\nIngrese el nombre del producto a eliminar: ");
    scanf("%s", nombreBuscado);

    int encontrado = 0;

    for (int i = 0; i < TAM_TABLA; ++i) {
        Producto *actual = tablaHash[i];
        Producto *anterior = NULL;

        while (actual != NULL) {
            if (strcmp(actual->nombre, nombreBuscado) == 0) {
                encontrado = 1;
                if (anterior == NULL) {
                    // Eliminar el primer producto en la lista
                    tablaHash[i] = actual->siguiente;
                } else {
                    // Eliminar un producto que no es el primero
                    anterior->siguiente = actual->siguiente;
                }
                free(actual);
                printf("\nProducto con nombre '%s' eliminado.\n", nombreBuscado);
                break; // Salir del bucle si se encuentra y elimina el producto
            }
            anterior = actual;
            actual = actual->siguiente;
        }

        if (encontrado) {
            break; // Salir del bucle principal si se ha eliminado el producto
        }
    }

    if (!encontrado) {
        printf("\nProducto con nombre '%s' no encontrado.\n", nombreBuscado);
    }
}
