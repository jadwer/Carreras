#include <stdio.h>

#include "registro.h"
#include "carrera.h"

#ifdef UNIT_TEST_REG
int main(void){

  Carrera carrera = creaCarrera("10K Quito", creaFecha(10, 9, 2021), creaFecha(15, 8, 2021), creaFecha(02, 10, 2021), categoriasCarrera());

  inscribirParticipantes(carrera);


 
  return 0;
}
#endif

void inscribirParticipantes(Carrera carrera){
  printf("\t\t** Inscribiendo participantes**\n");
  Participante * participantes = NULL;

  imprimeParticipante(validaParticipante(carrera));


  return;
}

Participante validaParticipante(Carrera carrera) {

  Participante participante;

  char nombre[50];
  int edad = 0;
  char discapacidad[10];
  bool condicion = false;
  Fecha inscripcion;
  int categoria = 0;

  getchar();
  printf("Nombre del participante: ");
  fgets(nombre, 50, stdin);

  printf("Edad: ");
  scanf("%d", &edad);
  printf("Dicapacidad: ");  
  scanf("%s", discapacidad);
  condicion = validaSi(discapacidad);
  categoria = asignaCategoria(edad, condicion, carrera.categorias);
  
  printf("La categoria asignada es: %i", categoria);

  printf("\tfecha de inscripción ");
  printf("Dia: ");
  scanf("%d", &inscripcion.dia);
  printf("Mes: ");
  scanf("%d", &inscripcion.mes);
  printf("Año: ");
  scanf("%d", &inscripcion.anio);
  validaFechaInscripcion(inscripcion, carrera);
  

  printf("\n Su número asignado es: ");
  



  return participante;
}

/*
  categorias[0] = creaCategoria(1, "Juvenil", 12, 19, false);
  categorias[1] = creaCategoria(1, "Elite", 20, 39, false);
  categorias[2] = creaCategoria(1, "Juvenil", 40, 59, false);
  categorias[3] = creaCategoria(1, "Supermaster", 60, 120, false);
  categorias[4] = creaCategoria(1, "Discapacitados", 12, 130, true);
*/


int asignaCategoria(int edad, bool condicion,Categoria * categorias){
  return 1;
  // if (validaSi()){}
}

bool validaFechaInscripcion(Fecha 
fecha, Carrera carrera){

  bool fechaValida = false;

  // TODO valida la fecha entre inicio de inscrip y fin de inscrip
  {
    fechaValida = true;
  }

  return fechaValida;
}
