#pragma once

#include <stdbool.h>

typedef struct {
  int id;
  char nombre[50];
  int edadInferior;
  int edadSuperior;
  bool discapacidad;
}  Categoria ;

Categoria creaCategoria(int id, char * nombre, int inferior, int superior, bool discapacidad);
