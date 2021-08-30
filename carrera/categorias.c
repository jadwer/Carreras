#include <stdio.h>
#include <string.h>

#include "categorias.h"

#ifdef UNIT_TEST_CAT
int main(void){

  Categoria categorias[5];

  categorias[0] = creaCategoria(1, "Juvenil", 12, 19, false);
  categorias[1] = creaCategoria(1, "Elite", 20, 39, false);
  categorias[2] = creaCategoria(1, "Juvenil", 40, 59, false);
  categorias[3] = creaCategoria(1, "Supermaster", 60, 120, false);
  categorias[4] = creaCategoria(1, "Discapacitados", 12, 130, true);


  printf("%s", categorias[0].nombre);



  return 0;
}
#endif

Categoria creaCategoria(int id, char * nombre, int inferior, int superior, bool discapacidad){
  
  Categoria categoria;

  categoria.id = id;
  strcpy(categoria.nombre, nombre);
  categoria.edadInferior = inferior;
  categoria.edadSuperior = superior;
  categoria.discapacidad = discapacidad;

  return categoria;

}
