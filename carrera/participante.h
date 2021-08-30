#pragma once

#include <stdio.h>
#include <string.h>
#include "utils.h"

typedef struct {
  char nombre[50];
  char genero;
  int edad;
  int numero;
  int categoria;
  Fecha fechaInscripcion;
  Tiempo tiempoFinal;
} Participante;

Participante creaParticipante(char * nombre, char genero, int edad, int numero, int categoria, Fecha inscripcion, Tiempo tiempo);
Participante creaParticipanteVacio();
void imprimeParticipante(Participante participante);
int cuentaParticipantes(Participante * participantes);