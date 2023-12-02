#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

// Programa Principal
int main() {
    int opcion;
    do {
        mostrarMenu();

        if(scanf("%d", &opcion) != 1) {
            printf("\nOpción no válida. Intente de nuevo.\n");
            while (getchar() != '\n'); // Limpiar el búfer de entrada
            continue; // Ignorar la opción no válida y volver a mostrar el menú
        }
        getchar();

        switch (opcion) {
          case 1: {
              int subOpcionAgregar;
              int salirSubmenu = 0; // Variable de control para salir del submenú
              do {
                printf("\n");
                printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                printf("\033[1;36m║\033[0m"    "\033[1;34m      Submenú Agregar Producto\033[0m"   "\033[1;36m     ║ \033[0m\n");
                printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                printf("\033[0;36m║  1. Ingresar Detalle de Producto  ║\033[0m\n");
                printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                printf("\033[0;36m║  2. Agregar Productos desde CSV   ║\033[0m\n");
                printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                printf("\033[0;36m║  3. Volver al Menú Principal      ║\033[0m\n");
                printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                printf("Seleccione una opción: ");

                if (scanf("%d", &subOpcionAgregar) != 1) {
                      printf("\nOpción no válida. Intente de nuevo.\n");
                      while (getchar() != '\n'); // Limpiar el búfer de entrada
                      continue; // Ignorar la opción no válida y volver a mostrar el menú
                  }
                getchar();

                  switch (subOpcionAgregar) {
                      case 1:
                          registrarProducto();
                          break;
                      case 2:
                          agregarProductosDesdeCSV();
                          break;
                      case 3:
                          salirSubmenu = 1; // Actualiza la variable para salir del submenú
                          break;
                      default:
                          printf("\nOpción no válida. Intente de nuevo.\n");
                  }
              } while (!salirSubmenu); // Usa la variable de control en la condición del bucle
              break;
          }
            case 2:
                eliminarProductoPorNombre();
                break;
            case 3:
                eliminarProducto();
                break;
            case 4: {
                int subOpcionActualizar;
                do {

                  printf("\n");
                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[1;36m║\033[0m"    "\033[1;34m     Submenú Actualizar Stock\033[0m"   "\033[1;36m      ║ \033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[0;36m║  1. Añadir Cantidad al Stock      ║\033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[0;36m║  2. Restar Cantidad al Stock      ║\033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[0;36m║  3. Nueva Cantidad Total          ║\033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[0;36m║  4. Volver al Menú principal      ║\033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                  if (scanf("%d", &subOpcionActualizar) != 1) {
                        printf("\nOpción no válida. Intente de nuevo.\n");
                        while (getchar() != '\n'); // Limpiar el búfer de entrada
                        continue; // Ignorar la opción no válida y volver a mostrar el menú
                    }
                  getchar();

                    printf("Seleccione una opción: ");

                    switch (subOpcionActualizar) {
                        case 1:
                            anadirCantidadStock();
                            break;
                        case 2:
                            restarCantidadStock();
                            break;
                        case 3:
                            establecerNuevaCantidadStock();
                            break;
                        default:
                            printf("\nOpción no válida. Intente de nuevo.\n");
                    }
                } while (subOpcionActualizar != 4);
                break;
            }
            case 5: {
                int subOpcionConsultar;
                do {


                  printf("\n");
                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[1;36m║\033[0m"    "\033[1;34m     Submenú Consultar Stock\033[0m"   "\033[1;36m       ║ \033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[0;36m║  1. Consultar Stock por Nombre    ║\033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[0;36m║  2. Consultar Stock por ID        ║\033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                  printf("\033[1;36m╔═══════════════════════════════════════════════════╗\033[0m\n");
                  printf("\033[0;36m║  3. Mostrar Lista Completa de Productos con Stock ║\033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════════════════════╝\033[0m\n\n");

                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[0;36m║  4. Volver al Menú Principal      ║\033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                    printf("Seleccione una opción: ");

                  if (scanf("%d", &subOpcionConsultar) != 1) {
                        printf("\nOpción no válida. Intente de nuevo.\n");
                        while (getchar() != '\n'); // Limpiar el búfer de entrada
                        continue; // Ignorar la opción no válida y volver a mostrar el menú
                    }
                  getchar();

                    switch (subOpcionConsultar) {
                        case 1:
                            consultarStockPorNombre();
                            break;
                        case 2:
                            consultarStock();
                            break;
                        case 3:
                            mostrarListaCompletaProductos();
                            break;
                        default:
                            printf("\nOpción no válida. Intente de nuevo.\n");
                    }
                } while (subOpcionConsultar != 4);
                break;
            }
            case 6:
                registrarVenta();
                break;
            case 7:
                cancelarVenta();
                break;
            case 8: {
                int subOpcionReporte;
                do {

                  printf("\n");
                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[1;36m║\033[0m"    "\033[1;34m      Submenú Generar Reporte\033[0m"   "\033[1;36m      ║ \033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[0;36m║  1. Generar Reporte de Ventas     ║\033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[0;36m║  2. Generar Reporte de Stock      ║\033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[0;36m║  3. Generar Reporte de Ganancias  ║\033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
                  printf("\033[0;36m║  4. Volver al Menú Principal      ║\033[0m\n");
                  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

                    printf("Seleccione una opción: ");

                  if (scanf("%d", &subOpcionReporte) != 1) {
                        printf("\nOpción no válida. Intente de nuevo.\n");
                        while (getchar() != '\n'); // Limpiar el búfer de entrada
                        continue; // Ignorar la opción no válida y volver a mostrar el menú
                    }
                  getchar();

                    switch (subOpcionReporte) {
                        case 1:
                            generarReporteVentas();
                            break;
                        case 2:
                            generarReporteStock();
                            break;
                        case 3:
                            generarReporteGanancias();
                            break;
                        default:
                            printf("\n\nOpción no válida. Intente de nuevo.\n");
                    }
                } while (subOpcionReporte != 4);
                break;
            }
            case 0:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}

void mostrarMenu(){
  // Sección del encabezado
  printf("\n");
  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
  printf("\033[1;36m║\033[0m"    "\033[1;34m            SUPLESTOCK        \033[0m"   "\033[1;36m     ║ \033[0m\n");
  printf("\033[1;36m║\033[0m"    "\033[1;34m  Gestión de Inventario y Ventas\033[0m"   "\033[1;36m   ║ \033[0m\n");
  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

  // Sección de opciones para productos
  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
  printf("\033[1;36m║\033[0m"    "\033[1;34m    Opciones para los Productos\033[0m"   "\033[1;36m    ║ \033[0m\n");
  printf("\033[1;36m╠═══════════════════════════════════╣\033[0m\n");
  printf("\033[0;36m║  1. Agregar Producto              ║\033[0m\n");
  printf("\033[0;36m║  2. Eliminar Producto por Nombre  ║\033[0m\n");
  printf("\033[0;36m║  3. Eliminar Producto por ID      ║\033[0m\n");
  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

  // Sección de opciones para el stock
  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
  printf("\033[1;36m║\033[0m"    "\033[1;34m        Opciones para Stock\033[0m"   "\033[1;36m        ║ \033[0m\n");
  printf("\033[1;36m╠═══════════════════════════════════╣\033[0m\n");
  printf("\033[0;36m║  4. Actualizar Stock              ║\033[0m\n");
  printf("\033[0;36m║  5. Consultar Stock               ║\033[0m\n");
  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

  // Sección de opciones para ventas
  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
  printf("\033[1;36m║\033[0m"    "\033[1;34m        Opciones para Ventas\033[0m"   "\033[1;36m       ║ \033[0m\n");
  printf("\033[1;36m╠═══════════════════════════════════╣\033[0m\n");
  printf("\033[0;36m║  6. Registrar Venta               ║\033[0m\n");
  printf("\033[0;36m║  7. Cancelar Venta                ║\033[0m\n");
  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

  // Sección de opciones para generar reporte
  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
  printf("\033[1;36m║\033[0m"    "\033[1;34m    Opción para Generar Reporte\033[0m"   "\033[1;36m    ║ \033[0m\n");
  printf("\033[1;36m╠═══════════════════════════════════╣\033[0m\n");
  printf("\033[0;36m║  8. Generar Reporte               ║\033[0m\n");
  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

  // Opción salir del programa
  printf("\033[1;36m╔═══════════════════════════════════╗\033[0m\n");
  printf("\033[1;36m║\033[0m"    "\033[1;34m   Opción para Salir del Programa\033[0m"   "\033[1;36m  ║ \033[0m\n");
  printf("\033[1;36m╠═══════════════════════════════════╣\033[0m\n");
  printf("\033[0;36m║  0. Salir del Programa            ║\033[0m\n");
  printf("\033[1;36m╚═══════════════════════════════════╝\033[0m\n\n");

  // Sección del pie de página
  printf("\033[1;20m Seleccione una opción: \033[0m");  
}