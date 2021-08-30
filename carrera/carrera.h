#pragma once

#include "categorias.h"
#include "utils.h"

typedef struct {
  char nombre[50];
  Fecha fechaCarrera;
  Fecha inicioInscripcion;
  Fecha finInscripcion;
  Categoria * categorias;
} Carrera;

Carrera creaCarrera(char * nombre, Fecha fecha, Fecha inicioInscripcion, Fecha finInscripcion, Categoria * categorias);
Categoria * categoriasCarrera();