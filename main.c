#include <stdio.h>
#define MAX 100

int arbolBusquedaBinaria[MAX];
int buscar(int arbolBusquedaBinaria[], int x, int i)
{
    if (arbolBusquedaBinaria[i] == 0)
    {
        //Busqueda sin exito: en arbolBusquedaBinaria[0]...
        //...se guarda la posicion donde no se encontro x...
        //Lo anterior con el ojbjeto que la funcion insertar...
        //...sepa donde insertar...
        arbolBusquedaBinaria[0] = i;
        return 0;
    }
    if (arbolBusquedaBinaria[i] < x)
        return buscar(arbolBusquedaBinaria, x, 2 * i + 1);
    else if (arbolBusquedaBinaria[i] > x)
        return buscar(arbolBusquedaBinaria, x, 2 * i);
    else
        return i;
}

int buscarMin(int arbolBusquedaBinaria[])
{
    int i = 1, j;
    while (arbolBusquedaBinaria[i] != 0)
    {
        j = arbolBusquedaBinaria[i];
        i = 2 * i;
    }
    return j;
}
int buscarMax(int arbolBusquedaBinaria[])
{
    int i = 1, j;
    while (arbolBusquedaBinaria[i] != 0)
    {
        j = arbolBusquedaBinaria[i];
        i = 2 * i + 1;
    }
    return j;
}
//void eliminar(int arbolBusquedaBinaria[], int x){

//}
int main()
{
    int i, bandera = 1, n;

    printf("\nCuantos nodos tiene tu arbol binario?: ");
    scanf("%i", &n);
    printf("\nDame el arbol: ");
    for (i = 1; i <= n; i++)
        scanf("%i", &arbolBusquedaBinaria[i]);
    printf("\nElemento minimo: %i", buscarMin(arbolBusquedaBinaria));
    printf("\nElemento maximo: %i", buscarMax(arbolBusquedaBinaria));

    while (bandera)
    {
        printf("\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
        printf("\nElija la opción a desarrollar.");
        printf("\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
        printf("\n\n1.- Buscar un numero:");
        printf("\n2.- Insertar un numero:");
        printf("\n3.- Eliminar un numero:");
        printf("\n4.- Salir:\n");
        printf("Digite la opción: ");
        scanf("%i", &n);    

        switch (n)
        {
        case 1:   //Opción de buscar un numero en el arbol
            printf("\nDame el numero a buscar: ");
            scanf("%i", &n);
            if (n = buscar(arbolBusquedaBinaria, n, 1))
                printf("\nEl numero que buscas esta en la posicion: %i\n\n", n);
            else
                printf("\nEl numero no esta y deberia estar en la posicion %i", arbolBusquedaBinaria[0]);
            break;
        case 2:   //Opción de añadir un numero al arbol
            printf("\nDame el numero a insertar: ");
            scanf("%i", &i);
            if (n = buscar(arbolBusquedaBinaria, i, 1))
                printf("\nEl numero ya se encuentra en la posicion %i: ", n);
            else
                arbolBusquedaBinaria[arbolBusquedaBinaria[0]] = i;
            printf("\nEl numero ha sido correctamente insertado en la posición %i: ", arbolBusquedaBinaria[0]);
            break;
        case 3: //Opción de eliminar un numero del arbol
            printf("\nDame un numero a eliminar: ");
            scanf("%i", &i);
            if (n = buscar(arbolBusquedaBinaria, i, 1))
            {
                arbolBusquedaBinaria[n] = 0;
                printf("\nNumero del nodo %i ha sido eliminado exitosamente.", n);
            }else{
                printf("\nEl numero en el nodo %i. No existe.", arbolBusquedaBinaria[0]);
            }
            break;
        default:
            bandera = 0;
            break;
        case 4:   //Opción de salida del programa
            return 0;
            break;
       /* default:
            bandera = 0;
            break;   */ 
        }
    }
    getchar();
    return 0;
}