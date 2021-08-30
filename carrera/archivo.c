#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "archivo.h"

#ifdef UNIT_TEST_ARC
  int main(void){
    Participante participante = creaParticipante("Juan papayas", 'M', 22, 1234, 1, creaFecha(12,12,2020), creaTiempo(0,0,0));

    //printf("%s", participante.nombre);

    //guardarParticipante(participante);

    Participante participante2 = buscaParticipante(1234);

    //imprimeParticipante(participante2);

    Participante participanteTiempo;

    participanteTiempo = setTiempoFinal(1234, creaTiempo(1, 12, 40));

    //imprimeParticipante(participanteTiempo);

    //imprimeParticipante(buscaParticipante(1234));

    Participante * participantes = getParticipantes();

    long num = numeroParticipantes();
    printf("Num Participante: %ld\n", num);

    for(long i = 0; i < num; i++) {
      imprimeParticipante(participantes[i]);
    }

    free(participantes);
    return 0;
  }
#endif


void creaArchivo() {
    FILE *arch;
    arch=fopen("inscripcion.txt","wb");
    if (arch==NULL){
      printf("ERROR: No se pudo crear el archivo.");
      exit(1);
    }
    fclose(arch);
}

void guardarParticipante(Participante participante) {
    FILE * archivo;
    archivo=fopen("inscripcion.txt","ab");
    if (archivo==NULL) {
      printf("ERROR: No se pudo crear el archivo.");
      exit(1);
    }

    fwrite(&participante, sizeof(Participante), 1, archivo);
    fclose(archivo);

    return;
}

Participante buscaParticipante(int numero) {

    Participante participante;
    bool existe = false;

    FILE * archivo;

    archivo=fopen("inscripcion.txt","rb");
    if (archivo == NULL) {
      printf("ERROR: No se pudo crear el archivo.");
      exit(1);
    }
    fread(&participante, sizeof(Participante), 1, archivo);
    while(!feof(archivo))
    {
        if (numero == participante.numero)
        {
           existe = true;
           break;
        }
        fread(&participante, sizeof(Participante), 1, archivo);
    }
    if (existe==false){
        printf("No existe un participante con ese número dorsal.\n");
        
        fclose(archivo);

        return creaParticipanteVacio();
    }
    fclose(archivo);

    return participante;
}

Participante setTiempoFinal(int numero, Tiempo tiempo) {

    Participante participante;

    participante = buscaParticipante(numero);
    if(participante.numero == 0){
      return participante;
    }
    FILE * archivo;
    archivo = fopen("inscripcion.txt","r+b");

    if (archivo == NULL) {
      printf("ERROR: No se pudo abrir el archivo.");
      exit(1);
    }

    fread(&participante, sizeof(Participante), 1, archivo);

    while(!feof(archivo))
    {
        if (numero == participante.numero )
        {
           int posicionPtr = ftell(archivo)-sizeof(Participante);
           fseek(archivo, posicionPtr, SEEK_SET);
           participante.tiempoFinal = tiempo;
           fwrite(&participante, sizeof(Participante), 1, archivo);
           break;
        }
        fread(&participante, sizeof(Participante), 1, archivo);
    }
    fclose(archivo);
    
    return participante;
}

Participante * getParticipantes() {

    Participante participante;
    Participante * participantes = NULL;
    int cont = 0;

    participantes = (Participante *)malloc(sizeof(Participante));
    if(participantes == NULL) {
      printf("Error: No se pudo apartar la memoria.");
      exit(0);
    }

    FILE * archivo;

    archivo = fopen("inscripcion.txt","rb");
    if (archivo == NULL) {
      printf("ERROR: No se pudo abrir el archivo.");
      exit(1);
    }

    fread(&participante, sizeof(Participante), 1, archivo);

    while(!feof(archivo))
    {
      participantes[cont] = participante;
      fread(&participante, sizeof(Participante), 1, archivo);

      cont += 1;
      participantes = (Participante *)realloc(participantes, (cont+1) * sizeof(Participante));

      if( participantes == NULL )
      {
        fprintf(stderr, "allocate memory Error1!\n");
        free(participantes);
      }
   
      participantes[cont] = participante;
    }

    fclose(archivo);

    return participantes;
}

long numeroParticipantes() {

  long numeroParticipantes;

  FILE * archivo;
  archivo = fopen("inscripcion.txt", "rb");
 
  fseek(archivo, 0, SEEK_END);
 
  numeroParticipantes = ftell(archivo)/sizeof(Participante);
  fclose(archivo);

  return numeroParticipantes;
}
