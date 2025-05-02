/**
 * @file usuario.c
 * @author JOYBOY
 * @brief Funciones para manejar la estructura de usuario.
 */

#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Agrega un producto al carrito del usuario y actualiza el total a pagar
 * Crea un nuevo nodo para el producto y lo agrega al final de la lista del carrito
 * @param usuario Estructura del usuario
 * @param producto Objeto del producto a agregar al carrito
 * @return void
 */
void agregarAlCarrito(Usuario* usuario, Producto* producto) {
    Producto* nuevo = malloc(sizeof(Producto));
    strcpy(nuevo->nombre, producto->nombre);
    nuevo->costo = producto->costo;
    nuevo->siguiente = NULL;
    // Si el carrito esta vacio, el nuevo producto es el inicio
    if (!usuario->carrito) {
        usuario->carrito = nuevo;
    } else {
        Producto* p = usuario->carrito;
        while (p->siguiente) p = p->siguiente;
        p->siguiente = nuevo;
    }
    // Actualizar el total a pagar
    usuario->totalPagar += producto->costo;
}

/**
 * @brief Muestra el contenido del carrito de compras y el total a pagar
 * @param usuario Estructura del usuario
 * @return void
 */
void verCarrito(Usuario* usuario) {
    printf("\n--- Carrito de Compras ---\n");
    // Verificar si el carrito esta vacio
    if (!usuario->carrito) {
        printf("El carrito esta vacio\n");
    } else {
        Producto* temp = usuario->carrito;
        int i = 1;
        while (temp) {
            printf("%d. %s - $%.2f\n", i++, temp->nombre, temp->costo);
            temp = temp->siguiente;
        }
        printf("\nTotal a pagar: $%.2f\n", usuario->totalPagar);
    }
    printf("\nPresione Enter para regresar..."); getchar();
}

/**
 * @brief Muestra la informacion del usuario
 * @param usuario Estructura del usuario
 * @return void
 */
void verInformacionUsuario(Usuario* usuario) {
    printf("\n--- Informacion del Usuario ---\n");
    printf("Nombre: %s\n", usuario->nombre);
    printf("Numero de celular: %s\n", usuario->numeroCelular);
    printf("Total a pagar: $%.2f\n", usuario->totalPagar);
    printf("\nPresione Enter para regresar..."); getchar();
}
