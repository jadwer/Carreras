#include <stdio.h>

#include "utils.h"

Fecha creaFecha(int dia, int mes, int anio){
  Fecha fecha;

  fecha.dia = dia;
  fecha.mes = mes;
  fecha.anio = anio;

  return fecha;
}

Tiempo creaTiempo(int horas, int minutos, int segundos){
  Tiempo tiempo;

  tiempo.horas = horas;
  tiempo.minutos = minutos;
  tiempo.segundos = segundos;

  return tiempo;
}

void continuar()
{
    printf("Presione una tecla para continuar\n\n");
    getchar();
}

bool validaFin(char f[]) {
	bool fin = false;
	
	if(f[0] == 'F'|| f[0] == 'f'){
		if(f[1] == 'I' || f[1] == 'i'){
			if(f[2] == 'N'|| f[2] == 'n'){
				fin = true;
			}
		}
	}
	
	return fin;
} 

bool validaSi(char f[]){
	bool si = false;
	
	if(f[0] == 'S'|| f[0] == 's'){
		if(f[1] == 'I' || f[1] == 'i'){
      si = true;
		}
	}
	
	return si;
} 

void imprimeFecha(Fecha fecha){
  char * mes = nombreMes(fecha.mes);
  printf("%i de %s del %i", fecha.dia, mes, fecha.anio);
}

char * nombreMes(int mes){
  char * nombre;
  switch(mes){
    case 1:
      nombre = "enero";
      break;
    case 2:
      nombre =  "febrero";
      break;
    case 3:
      nombre =  "marzo";
      break;
    case 4:
      nombre =  "abril";
      break;
    case 5:
      nombre =  "mayo";
      break;
    case 6:
      nombre =  "junio";
      break;
    case 7:
      nombre =  "julio";
      break;
    case 8:
      nombre =  "agosto";
      break;
    case 9:
      nombre =  "septiembre";
      break;
    case 10:
      nombre =  "octubre";
      break;
    case 11:
      nombre =  "noviembre";
      break;
    case 12:
      nombre =  "diciembre";
      break;
    default:
      nombre =  "Error, no es un mes";
  }
  return nombre;
}