/**
 * @file main.c
 * @author JOYBOY
 * @brief EL MAIN =D
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "productos.h"
#include "usuario.h"
#include "interfaz.h"

/**
 * @brief Limpiar la pantalla
 * @return void
 */
static void clear_screen() {
    system("cls || clear");
}

/**
 * @brief Leer una opcion de tipo int
 * @return int Opcion leida por el usuario
 */
static int leerOpcionInt(){ 
    int op; 
    if(scanf("%d",&op)!=1) op=-1; 
    while(getchar()!='\n'); 
    return op; 
}

int main(){
    // Inicializar el usuario
    // y la lista de productos
    Usuario usuario;
    char buffer[100];
    usuario.totalPagar=0.0f;
    usuario.carrito=NULL;
    usuario.nombre[0]='\0';
    usuario.numeroCelular[0]='\0';
    Producto* listaProductos;

    // Intentamos abrir el archivo directamente para ver que existe
    FILE* archivo = fopen("data/productos.txt", "r");
    if (archivo == NULL) {
        // Si fopen falla salimos del programa
        printf("No se pudo abrir productos.txt. Asegurate de que existe el archivo.");
        return 1;
    }
    fclose(archivo);

    // Funcion que carga los productos
    listaProductos = cargarProductos("data/productos.txt");

    // Verificamos el resultado
    if (listaProductos == NULL) {
        printf("Error al cargar la lista de productos desde el archivo.");
        return 1;
    }

    // Leer nombre
    printf("Ingrese su nombre: ");
    if(fgets(buffer,sizeof(buffer),stdin)){
        for(int i=0; buffer[i]; i++){
            if(buffer[i]=='\n'){ buffer[i]='\0'; break; }
        }
        strcpy(usuario.nombre, buffer);
    }

    // Leer celular
    printf("Ingrese su numero de celular: ");
    if(fgets(buffer,sizeof(buffer),stdin)){
        for(int i=0; buffer[i]; i++){
            if(buffer[i]=='\n'){ buffer[i]='\0'; break; }
        }
        strcpy(usuario.numeroCelular, buffer);
    }

    // Menu de opciones
    int opcion;
    do{
        clear_screen();
        printf("--- Menu Principal ---\n");
        printf("1. Ver carrito\n2. Info usuario\n3. Productos\n4. Salir\n");
        printf("Seleccione una opcion: "); opcion=leerOpcionInt();
        switch(opcion){
            case 1: verCarrito(&usuario); break;
            case 2: verInformacionUsuario(&usuario); break;
            case 3: verProductos(&usuario, listaProductos); break;
            case 4: printf("Hasta luego, vuelva pronto xd\n"); break;
            default: printf("Opcion invalida\n"); getchar();
        }
    } while(opcion!=4);

    // Liberar memoria al finalizar
    liberarProductos(listaProductos);
    while(usuario.carrito){ 
        Producto* tmp=usuario.carrito; usuario.carrito=tmp->siguiente; free(tmp);
    }
    return 0;
}
