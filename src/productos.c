/**
 * @file productos.c
 * @author JOYBOY
 * @brief Funciones para manejar la lista de productos.
 * Carga los productos desde un archivo de texto.
 */
#include "productos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maxima longitud de una linea en el archivo
#define MAX_LINEA 256

/**
 * @brief Leer el archivo de texto con los productos y carga los productos en una lista ligada
 * 
 * @param archivo El nombre del archivo a cargar
 * @return Producto* Apuntador a la lista de productos
 * @note La lista es una lista ligada, cada nodo contiene el nombre y costo del producto 
 */
Producto* cargarProductos(const char* archivo) {
    FILE* f = fopen(archivo, "r");
    if (!f) return NULL;

    Producto* inicio = NULL;
    char linea[MAX_LINEA];

    while (fgets(linea, sizeof(linea), f)) {
        // Eliminar salto de linea
        char* fin = strchr(linea, '\n');
        if (fin) *fin = '\0';
        // Comprobar si la linea esta vacia
        if (linea[0] == '\0') continue;

        // Separar nombre y costo
        // Vamos a suponer que el nombre no contiene comas
        // y que las comas separan el nombre del costo
        char* ptr = strchr(linea, ',');
        if (!ptr) continue;

        *ptr = '\0';
        char* textoCosto = ptr + 1;

        char nombre[100];
        strncpy(nombre, linea, sizeof(nombre)-1);
        nombre[sizeof(nombre)-1] = '\0';
        float costo = atof(textoCosto);

        // Nuevo nodo
        Producto* nuevo = malloc(sizeof(Producto));
        strcpy(nuevo->nombre, nombre);
        nuevo->costo = costo;
        nuevo->siguiente = NULL;

        // Insertar al final de la lista
        // Si la lista esta vacia, el nuevo nodo es el inicio
        if (!inicio) {
            inicio = nuevo;
        } else {
            Producto* p = inicio;
            while (p->siguiente) p = p->siguiente;
            p->siguiente = nuevo;
        }
    }
    fclose(f);
    return inicio;
}

/**
 * @brief Libera la memoria de la lista de productos
 * @param productos Apuntador a la lista de productos 
 * @return void
 */
void liberarProductos(Producto* productos) {
    Producto* temp;
    while (productos) {
        temp = productos;
        productos = productos->siguiente;
        free(temp);
    }
}
