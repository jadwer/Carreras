#include <stdio.h>
#include <string.h>

#include "participante.h"

#ifdef UNIT_TEST_PART
int main(void) {
  Participante participante;
  strcpy(participante.nombre, "Nombre del participante");
  participante.genero = 'F';
  participante.edad = 24;
  participante.numero = 1234;
  participante.categoria = 1;
  participante.fechaInscripcion.dia = 12;
  participante.fechaInscripcion.mes = 12;
  participante.fechaInscripcion.anio = 1212;
  participante.tiempoFinal.horas = 1;
  participante.tiempoFinal.minutos = 12;
  participante.tiempoFinal.segundos = 40;

  imprimeParticipante(participante);
  
  Participante nuevoP = creaParticipante("Juan papayas", 'M', 22, 1234, 1, creaFecha(12,12,2020), creaTiempo(1,12,40));

  imprimeParticipante(nuevoP);

  return 0;
}
#endif

Participante creaParticipante(char * nombre, char genero, int edad, int numero, int categoria, Fecha inscripcion, Tiempo tiempo) {

  Participante participante;

  strcpy(participante.nombre, nombre);
  participante.genero = genero;
  participante.edad = edad;
  participante.numero = numero;
  participante.categoria = categoria;
  participante.fechaInscripcion = inscripcion;
  participante.tiempoFinal = tiempo;

  return participante;
}

Participante creaParticipanteVacio() {

  Participante participante;

  strcpy(participante.nombre, "");
  participante.genero = 'M';
  participante.edad = 0;
  participante.numero = 0;
  participante.categoria = 0;
  participante.fechaInscripcion = creaFecha(0,0,0);
  participante.tiempoFinal = creaTiempo(0,0,0);

  return participante;
}

void imprimeParticipante(Participante participante ){

  printf(" Nombre: %s", participante.nombre);
  printf("\n Genero: %c", participante.genero);
  printf("\n Edad: %i", participante.edad);
  printf("\n Numero: %i", participante.numero);
  printf("\n Categoria: %i", participante.categoria);
  printf("Fecha de inscripción: ");
  imprimeFecha(participante.fechaInscripcion);
  printf("\n Tiempo: %i:%i:%i\n", participante.tiempoFinal.horas, participante.tiempoFinal.minutos, participante.tiempoFinal.segundos);

  return;
}

int cuentaParticipantes(Participante * participantes) {
  int n = (int)(sizeof(*participantes)/sizeof(Participante));
  return n;
}