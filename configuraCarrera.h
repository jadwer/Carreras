#pragma once

#include <stdlib.h>

#include "carrera/carrera.h"
#include "carrera/categorias.h"
#include "carrera/utils.h"



Categoria * categoriasQuito(){

  Categoria * categorias = malloc(sizeof(Categoria) * 5);

  categorias[0] = creaCategoria(1, "Juvenil", 12, 19, false);
  categorias[1] = creaCategoria(1, "Elite", 20, 39, false);
  categorias[2] = creaCategoria(1, "Juvenil", 40, 59, false);
  categorias[3] = creaCategoria(1, "Supermaster", 60, 120, false);
  categorias[4] = creaCategoria(1, "Discapacitados", 12, 130, true);

  return categorias;
}


Carrera quito(){
  return creaCarrera(
    "10k Quito", 
    creaFecha(10, 9, 2021),
    creaFecha(15, 9, 2021),
    creaFecha(05, 9, 2021),
    categoriasQuito()
  );
}

