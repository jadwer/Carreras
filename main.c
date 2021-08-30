#include <stdio.h>
#include <string.h>

#include "carrera/participante.h"
#include "carrera/registro.h"
#include "configuraCarrera.h"


int menu();

int main(){

  bool salir = false;
  int opcion = 0;

  Carrera quito10k = quito();

  printf("bienvenido a la carrera %s\n",
 quito10k.nombre);
  imprimeFecha(quito10k.fechaCarrera);


  do{
    switch(menu()) {
      case 0:
        salir = true;
        break;
      case 1:
        inscribirParticipantes(quito10k);
        break;
      default:
      printf("\n¡Opción no válida!");
    }
  } while (!salir);

  printf("\n\n\t¡Hasta pronto!\n");

  return 0;
}

int menu() {
  int opcion=0;

  printf("\n\nMENU\n");
  printf("\t0. Salir:\n");
  printf("\t1. Inscribir participantes:\n");
  printf("\nSeleccione la opción deseada: ");
  scanf("%i", &opcion);

  return opcion;


}