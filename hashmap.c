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

void agregarProductosDesdeCSV() {
    char filename[100];
    printf("\nIngrese el nombre del archivo CSV: ");
    scanf("%99s", filename); // Limita la entrada
    while (getchar() != '\n'); // Limpia el buffer

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("\nNo se pudo abrir el archivo %s\n", filename);
        return;
    }

    char line[1024];

    // Si tu CSV tiene una línea de encabezado, descomenta la siguiente línea
    // fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        char *token;
        int id, cantidad_stock;
        char nombre[50];
        float precio_compra, precio_venta;

        // Tokenización y conversión de datos
        token = strtok(line, ",");
        if (token) id = atoi(token);

        token = strtok(NULL, ",");
        if (token) strcpy(nombre, token);

        token = strtok(NULL, ",");
        if (token) precio_compra = atof(token);

        token = strtok(NULL, ",");
        if (token) precio_venta = atof(token);

        token = strtok(NULL, ",");
        if (token) cantidad_stock = atoi(token);

        // Agregar producto al sistema
        agregarProductoDetalle(id, nombre, precio_compra, precio_venta, cantidad_stock);
    }

    fclose(file);
    printf("\nProductos agregados desde CSV correctamente.\n");
}

void agregarProductoDetalle(int id, char *nombre, float precio_compra, float precio_venta, int cantidad_stock) {
    Producto producto;
    producto.id = id;
    strncpy(producto.nombre, nombre, sizeof(producto.nombre) - 1); // Asegurar que no exceda el límite de tamaño
    producto.precio_compra = precio_compra;
    producto.precio_venta = precio_venta;
    producto.cantidad_stock = cantidad_stock;

    int indice = calcularHash(producto.id);

    Producto *nuevoProducto = (Producto *)malloc(sizeof(Producto));
    if (nuevoProducto == NULL) {
        printf("\nError al asignar memoria para nuevo producto.\n");
        return;
    }

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

    printf("\nProducto '%s' agregado correctamente.\n", nombre);
}

void mostrarListaCompletaProductos() {
    printf("\n--- Lista Completa de Productos en Inventario ---\n");

    int hayProductos = 0;
    for (int i = 0; i < TAM_TABLA; i++) {
        Producto *producto = tablaHash[i];
        while (producto != NULL) {
            printf("\nID: %d, Nombre: %s, Precio Compra: %.2f, Precio Venta: %.2f, Stock: %d\n",
                   producto->id, producto->nombre, producto->precio_compra, 
                   producto->precio_venta, producto->cantidad_stock);
            producto = producto->siguiente;
            hayProductos = 1;
        }
    }

    if (!hayProductos) {
        printf("\nNo hay productos en el inventario.\n");
    }
}

void consultarStock() {
    int id;
    printf("\nIngrese ID del producto a consultar: ");
    scanf("%d", &id);

    int indice = calcularHash(id);
    Producto *producto = tablaHash[indice];

    // Buscar en la lista enlazada
    while (producto != NULL) {
        if (producto->id == id) {
            printf("\nProducto encontrado: %s\n", producto->nombre);
            printf("\nCantidad en stock: %d\n", producto->cantidad_stock);
            return;
        }
        producto = producto->siguiente;
    }

    printf("\nProducto con ID %d no encontrado.\n", id);
}

void actualizarStock() {
    int id, nuevaCantidad;
    printf("\nIngrese ID del producto a actualizar: ");
    scanf("%d", &id);

    int indice = calcularHash(id);
    Producto *producto = tablaHash[indice];

    // Buscar en la lista enlazada
    while (producto != NULL) {
        if (producto->id == id) {
            printf("\nProducto encontrado: %s\n", producto->nombre);
            printf("\nCantidad en stock actual: %d\n", producto->cantidad_stock);
            printf("\nIngrese la nueva cantidad en stock: ");
            scanf("%d", &nuevaCantidad);
            producto->cantidad_stock = nuevaCantidad;
            printf("\nStock actualizado. Nueva cantidad en stock: %d\n", producto->cantidad_stock);
            return;
        }
        producto = producto->siguiente;
    }

    printf("\nProducto con ID %d no encontrado.\n", id);
}

void anadirCantidadStock() {
    int id, cantidadAAnadir;
    printf("\nIngrese ID del producto a añadir stock: ");
    scanf("%d", &id);

    printf("\nIngrese la cantidad a añadir: ");
    scanf("%d", &cantidadAAnadir);

    int indice = calcularHash(id);
    Producto *producto = tablaHash[indice];

    // Buscar en la lista enlazada
    while (producto != NULL) {
        if (producto->id == id) {
            producto->cantidad_stock += cantidadAAnadir;  // Añadir al stock
            printf("\nCantidad añadida. Nueva cantidad en stock de '%s': %d\n", producto->nombre, producto->cantidad_stock);
            return;
        }
        producto = producto->siguiente;
    }

    printf("\nProducto con ID %d no encontrado.\n", id);
}

void restarCantidadStock() {
    int id, cantidadARestar;
    printf("\nIngrese ID del producto a restar stock: ");
    scanf("%d", &id);

    printf("\nIngrese la cantidad a restar: ");
    scanf("%d", &cantidadARestar);

    if (cantidadARestar < 0) {
        printf("\nNo se puede restar una cantidad negativa.\n");
        return;
    }

    int indice = calcularHash(id);
    Producto *producto = tablaHash[indice];

    // Buscar en la lista enlazada
    while (producto != NULL) {
        if (producto->id == id) {
            if (producto->cantidad_stock < cantidadARestar) {
                printf("\nOperación no válida. La cantidad a restar excede el stock actual.\n");
                return;
            }
            producto->cantidad_stock -= cantidadARestar;  // Restar del stock
            printf("\nCantidad restada. Nueva cantidad en stock de '%s': %d\n", producto->nombre, producto->cantidad_stock);
            return;
        }
        producto = producto->siguiente;
    }

    printf("\nProducto con ID %d no encontrado.\n", id);
}