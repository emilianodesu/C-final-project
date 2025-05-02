/**
 * @file interfaz.c
 * @author JOYBOY
 * @brief Funciones para manejar la interfaz de usuario.
 * Maneja la lista de productos y el carrito de compras.
 * Permite al usuario ver los productos disponibles y agregar productos al carrito.
 */

#include "interfaz.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * @brief Limpiar la pantalla
 * @return void
 */
static void clear_screen() {
    system("cls || clear");
}

/**
 * @brief Lee un entero
 * @return int Valor leido por el usuario
 */
static int leerEntero() {
    int v;
    if (scanf("%d", &v) != 1) {
        v = 1;  // valor por defecto
    }
    while (getchar() != '\n');
    return (v > 0 ? v : 1);
}

/**
 * @brief Leer una opcion de tipo char
 * @return char Opcion leida por el usuario
 */
static char leerOpcionChar() {
    char c;
    if (scanf(" %c", &c) != 1) {
        c = '\0';
    }
    while (getchar() != '\n'); // Limpiar el buffer de entrada
    return c;
}

/**
 * @brief Muestra la lista de productos y permite navegar y agregar al carrito
 * @param usuario Estructura del usuario
 * @param listaProductos Arreglo de la lista de productos
 * @return void
 */
void verProductos(Usuario* usuario, Producto* listaProductos) {
    clear_screen();
    static int current = 0; // <- ¡Aquí está la memoria!
    int count = 0;
    // Contar los productos disponibles
    for (Producto* p = listaProductos; p; p = p->siguiente) {
        count++;
    }
    // Si no hay productos disponibles, mostrar mensaje y regresar al menu
    if (count == 0) {
        printf("No hay productos disponibles\n");
        printf("\nPresione Enter para regresar..."); 
        getchar();
        return;
    }
    // Asegurar que current esté dentro del rango
    if (current >= count) {
        current = count - 1;
    }

    // Crear un arreglo de apuntadores a productos para navegar
    Producto** arr = malloc(count * sizeof(Producto*));
    int i = 0;
    // Llenar el arreglo con los productos
    for (Producto* p = listaProductos; p; p = p->siguiente) {
        arr[i++] = p;
    }
    // Mostrar los productos y permitir navegar y agregar al carrito
    char tecla;
    do {
        clear_screen();
        printf("--- Lista de Productos ---\n");
        printf("Producto %d de %d\n\n", current+1, count);
        printf("Nombre: %s\n", arr[current]->nombre);
        printf("Precio: $%.2f\n\n", arr[current]->costo);
        printf("Opciones:\n");
        printf("S - Siguiente producto\n");
        printf("A - Producto anterior\n");
        printf("G - Agregar al carrito\n");
        printf("Q - Volver al menu\n");
        printf("Selecciona una opcion: ");
        tecla = leerOpcionChar();

        switch (tolower(tecla)) {
            // Siguiente producto
            case 's':
                if (current < count-1) {
                    current++;
                } else { 
                    printf("\nHasta aqui llegamos (como dijo mi ex)\n");
                    printf("Presione Enter para continuar...");
                    getchar(); 
                }
                
                break;
            // Producto anterior
            case 'a':
                if (current > 0) {
                    current--;
                } else { 
                    printf("\nYa no hay mas atras, solo pa adelante c:\n");
                    printf("Presione Enter para continuar...");
                    getchar(); 
                }
                break;
            // Agregar al carrito
            case 'g':
                printf("\nCuantas unidades deseas agregar? ");
                int cantidad = leerEntero();
                for (int k = 0; k < cantidad; k++) {
                    agregarAlCarrito(usuario, arr[current]);
                }
                printf("\nSe agregaron %d unidad(es). Total agregado: $%.2f\n", cantidad, arr[current]->costo * cantidad);
                printf("Presione Enter para continuar...");
                getchar();
                break;
            // Volver al menu
            case 'q': break;
            default:
                printf("Opcion no valida\n"); 
                printf("Presione Enter para continuar...");
                getchar();
        }
    } while (tolower(tecla) != 'q');
    free(arr);
}
