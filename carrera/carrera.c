#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carrera.h"

#ifdef UNIT_TEST_CAR

int main(void){
  Categoria * categorias = categoriasCarrera();
  printf("%s", categorias[0].nombre);

  Carrera carrera = creaCarrera("Carrera", creaFecha(12, 12, 12), creaFecha(12, 12, 12), creaFecha(12, 12, 12), categoriasCarrera());

  printf("%s", carrera.nombre);
  printf("%s", carrera.categorias[0].nombre);

  free(categorias);
  return 0;
}
#endif

Carrera creaCarrera(char * nombre, Fecha fecha, Fecha inicioInscripcion, Fecha finInscripcion, Categoria * categorias) {
  Carrera carrera;

  strcpy(carrera.nombre, nombre);
  carrera.fechaCarrera = fecha;
  carrera.inicioInscripcion = inicioInscripcion;
  carrera.finInscripcion = finInscripcion;
  carrera.categorias = categorias;

  return carrera;
}

