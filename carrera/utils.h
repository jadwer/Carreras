#pragma once

#include <stdbool.h>

typedef struct {
  int dia;
  int mes;
  int anio;
} Fecha;

typedef struct {
  int horas;
  int minutos;
  int segundos;
} Tiempo;

Fecha creaFecha(int dia, int mes, int anio);
Tiempo creaTiempo(int horas, int minutos, int segundos);

void pausa();
bool validaFin(char []);
bool validaSi(char f[]);

void imprimeFecha(Fecha fecha);
char * nombreMes(int mes);